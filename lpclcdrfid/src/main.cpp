/*
 * LPCLDC ported to Keil uV
 *
 */

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#include "LPC11Uxx.h"
#include "type.h"
//#include "xprintf.h"
//#include "systick.h"

#include "armcmx.h"
#include "USARTSerial.h"
#include "I2CBus.h"
#include "i2clcd.h"
#include "ST7032i.h"
#include "DS1307.h"
#include "PN532_I2C.h"

#include "ISO14443.h"

#ifdef _LPCXPRESSO_CRP_
#include <cr_section_macros.h>
#include <NXP/crp.h>

// Variable to store CRP value in. Will be placed automatically
// by the linker when "Enable Code Read Protect" selected.
// See crp.h header for more information
__CRP const unsigned int CRP_WORD = CRP_NO_CRP ;
#endif


/*******************************************************************************
**   Main Function  main()
*******************************************************************************/

// Strawberry Linux original lpclcd port maps
#define LCDBKLT PIO1_3
#define LCDRST  PIO1_25
#define USERLED PIO1_6
#define USERBTN PIO0_1
#define RXD2    PIO0_18
#define TXD2    PIO0_19
#define NFC_IRQ PIO1_5

#define RTC_ADDR 0x68


ST7032i i2clcd(Wire, LCDBKLT, LCDRST);
DS1307 rtc(Wire, DS1307::CHIP_M41T62);
PN532  nfcreader(Wire, PN532::I2C_ADDRESS, NFC_IRQ, PIO1_25);
const byte NFCpollingOrder[] = {
  2,
  TypeA,
  TypeF
};

void readcard(ISO14443 & card, IDData & data);
uint8 get_MifareBlock(ISO14443 & card, IDData & data);
uint8 get_FCFBlock(ISO14443 & card, IDData & data);

const static byte IizukaKey_b[] = {
  0xBB, 0x63, 0x45, 0x74, 0x55, 0x79, 0x4B };
//const static byte factory_a[] = {
//  0xaa, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff };


void init() {
  SystemInit();
  GPIOInit();
  // systick initialize
//  SysTick_Config( SystemCoreClock / 1000 );
//  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);

  init_timer16_1();
  // initialize xprintf
  //xfunc_out = (void(*)(unsigned char))i2clcd_data;
}

char msg[32];
uint8_t tmp[32];

void setup() {
  enable_timer16_1(); // for delay
  pinMode(USERBTN, INPUT);
  
  /* NVIC is installed inside UARTInit file. */
  //USART_init(&usart, PIO0_18, PIO0_19);
  Serial.begin(115200);
  Serial.println("\nUSART Serial started. \nHello.");

  Wire.begin(); 	/* initialize I2c */
  if ( Wire.status == FALSE )
  	while ( 1 );				/* Fatal error */
  Serial.println("I2C Bus started.");
  
  // I2C液晶を初期化します
  while(1)
    //if(!i2clcd_init(0x27)) break;   // 初期化完了ならwhileを抜ける
    if ( i2clcd.begin() ) break;
    // 失敗したら初期化を永遠に繰り返す
  Serial.println("I2CLCD started.");
  i2clcd.clear();
  i2clcd.print("Hello.");
  
  while(1)
    if ( rtc.begin() ) break;
    // 失敗したら初期化を永遠に繰り返す
  Serial.println("I2C RTC started.");

  nfcreader.begin();
  while (1) {
    if ( nfcreader.GetFirmwareVersion() && nfcreader.getCommandResponse((uint8_t*)tmp) ) 
      break;
    delay(250);
  }
  Serial << "I2C NFC reader ver. " << tmp[0] << " firm. " << tmp[1] << " rev. " << tmp[2];
  Serial.print(" support ");
  Serial.print(tmp[3], BIN);
  if ( !nfcreader.SAMConfiguration() ) {
		Serial.println("....SAMConfiguration failed. Halt.\n");
		while (1);
	}
  Serial.println(", SAM Configured.");
  
  // PIO1_6 USR LED //  GPIOSetDir(1, 6, 1 ); //  GPIOSetBitValue( 1, 6, 1);
  pinMode(USERLED, OUTPUT);
  digitalWrite(USERLED, HIGH);
}


int main (void) {
	long lastread = 0, swatch = 0, lasttime = 0;
  ISO14443 card, lastcard;
  IDData iddata;
  
  init();
  setup();
  // ---------------------------------------
  rtc.updateCalendar();
  rtc.updateTime();
  sprintf(msg, "%02x:%02x:%02x\n%02x/%02x/'%02x\n", 
                rtc.time>>16&0x3f, rtc.time>>8&0x7f, rtc.time&0x7f, 
                rtc.cal>>8&0x1f, rtc.cal&0x3f, rtc.cal>>16&0xff);
  Serial.print(msg);

  lastread = millis();
  
  while (1){    /* Loop forever */
    
		if ( nfcreader.InAutoPoll(1, 1, NFCpollingOrder+1, NFCpollingOrder[0]) 
        && nfcreader.getAutoPollResponse(tmp) ) {
				// NbTg, type1, length1, [Tg, ...]
          card.set(tmp[1], tmp+3);
          i2clcd.backlightOn();
          if ( millis() - lastread > 10000 or (millis() - lastread > 1999 and lastcard != card) ) {
            lastread = millis();
            lastcard = card;
            Serial.print("InAutoPoll: ");
            card.printOn(Serial);
            Serial.println();
            //
            readcard(card, iddata);
            if (card.type == FeliCa212kb ) {
              i2clcd.setCursor(0,0);
              if ( iddata.fcf.division[1] == 0 ) 
                i2clcd.write(iddata.fcf.division, 1);
              else
                i2clcd.write(iddata.fcf.division, 2);
              i2clcd.print('-');
              i2clcd.write(iddata.fcf.pid, 8);
              i2clcd.print('-');
              
              i2clcd.write((char)iddata.fcf.issue);
              Serial.write(iddata.fcf.pid, 8);
              Serial.print('-');
              Serial.write((char)iddata.fcf.issue);
              Serial.println();
              //
            } else if (card.type == Mifare ) {
              i2clcd.setCursor(0,0);
              i2clcd.write(iddata.iizuka.division, 2);
              i2clcd.print('-');
              i2clcd.write(iddata.iizuka.pid, 8);
              i2clcd.print('-');
              i2clcd.print((char)iddata.iizuka.issue);
              Serial.write(iddata.iizuka.pid, 8);
              Serial.print('-');
              Serial.print((char)iddata.iizuka.issue);
              Serial.println();
              //
            } else {
              Serial.println("Unknown card type.");
            }
          }
    } else if (millis() - lastread > 10000 ) {
      i2clcd.setCursor(0, 0);
      i2clcd.print("                ");
      i2clcd.backlightOff();
    }      

    if ( millis() - swatch >= 100 ) {
      swatch = millis();
      rtc.updateTime();
      if ( lasttime != rtc.time ) {
        lasttime = rtc.time;
        rtc.updateCalendar();
        i2clcd.setCursor(0, 1);
        sprintf((char*)tmp, "%02x:%02x:%02x", rtc.time>>16&0x3f, rtc.time>>8&0x7f, rtc.time&0x7f);
        i2clcd.print((char*)tmp);
        sprintf((char*)tmp, " %02x/%02x", rtc.cal>>8&0x1f, rtc.cal&0x3f);
        i2clcd.print((char*)tmp);
      }
    }
    
  }
  
}



void readcard(ISO14443 & card, IDData & data) {
  byte resp[128];
  uint16_t n;
	switch (card.type) {
    case Mifare:
      if ( nfcreader.InListPassiveTarget(1, PN532::BaudrateType_106kbitTypeA, (byte *)0, 0)
        and nfcreader.getListPassiveTarget(resp) ) {
          Serial.print("result: ");
          Serial.println(n);
          Serial.printByte(resp, 64);
          Serial.println();
          card.setInList(resp);
          if ( get_MifareBlock(card, data) == 0 ) 
            card.clear();
        }
        break;
    case FeliCa212kb:
      if ( get_FCFBlock(card, data) == 0 )
        card.clear();
      break;
	}
	return;
}

uint8 get_FCFBlock(ISO14443 & card, IDData & data) {
  word syscode = 0x00FE;
  int len;
  byte c;

  // Polling command, with system code request.
  len = nfcreader.felica_Polling(data.raw, syscode);
  if ( len == 0 ) 
    return 0;
  
  // low-byte first service code.
  // Suica, Nimoca, etc. 0x090f system 0x0300
  // Edy service 0x170f (0x1317), system 0x00FE // 8280
  // FCF 1a8b
  word servcode = 0x1a8b;
  word scver = nfcreader.felica_RequestService(servcode);
  if ( scver == 0xffff ) 
    return 0;
  //
  //printf("%04x ver %04x.\n", servcode, scver);
  //
  word blist[] = { 0, 1, 2, 3};
  c = nfcreader.felica_ReadBlocksWithoutEncryption(data.raw, servcode, (byte) 4, blist);
  if ( c == 0 ) {
    //printf("\nfailed reading FCF blocks. \n");
    return 0;
  }
//  printf("\n--- End of FCF reading ---\n\n");
  return 1;
}


uint8 get_MifareBlock(ISO14443 & card, IDData & data) {
  uint8 res;
  nfcreader.targetSet(0x10, card.ID, card.IDLength);
  if ( nfcreader.mifare_AuthenticateBlock(4, IizukaKey_b) 
     && nfcreader.getCommandResponse(&res) && res == 0) {
    nfcreader.mifare_ReadDataBlock(4, data.raw);
    nfcreader.mifare_ReadDataBlock(5, data.raw+16);
    nfcreader.mifare_ReadDataBlock(6, data.raw+32);
    card.type = Mifare;
  } 
  else {
    Serial.println("Mifare sector 1 Authentication failed.");
    return 0;
  }
  return 1;
}

/******************************************************************************
**                            End Of File
******************************************************************************/
