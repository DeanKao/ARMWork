/*
 * LPCLDC ported to Keil uV
 *
 */

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>

#include "LPC11Uxx.h"
#include "type.h"
#include "xprintf.h"
//#include "systick.h"

#include "armcmx.h"
#include "USARTSerial.h"
#include "I2CBus.h"
#include "i2clcd.h"
#include "ST7032i.h"

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

#define RTC_ADDR 0x68

char day[7][4] = {
  "Sun",
  "Mon",
  "Tue",
  "Wed",
  "Thu",
  "Fri",
  "Sat"
  };

ST7032i i2clcd(Wire, LCDBKLT, LCDRST);
/*
uint8_t i2clcd_data(uint8_t d) {
  return (uint8_t) i2clcd.write(d);
}
*/

int main (void) {
	long sw, ontime = 0; //, offtime;
  long i;
  char c = 0;
  char str[32];
  char message[32];
  char tmp[32];
  
  SystemInit();
  GPIOInit();
  
  // systick initialize
//  SysTick_Config( SystemCoreClock / 1000 );
//  LPC_SYSCON->SYSAHBCLKCTRL |= (1<<6);

  init_timer16_1();
  enable_timer16_1();

  // initialize xprintf
  //xfunc_out = (void(*)(unsigned char))i2clcd_data;
  
  // I2C LCD Backlight controll pin
  pinMode(LCDBKLT, OUTPUT);
  digitalWrite(LCDBKLT, HIGH);

  pinMode(USERBTN, INPUT);
  
  /* NVIC is installed inside UARTInit file. */
  //USART_init(&usart, PIO0_18, PIO0_19);
  Serial.begin(115200);

  Wire.begin();
  if ( Wire.status == FALSE ){	/* initialize I2c */
  	while ( 1 );				/* Fatal error */
  }

  // I2C液晶を初期化します
  while(1){
    //if(!i2clcd_init(0x27)) break;   // 初期化完了ならwhileを抜ける
    if ( i2clcd.begin() ) break;
    // 失敗したら初期化を永遠に繰り返す
  }

  // PIO1_6 USR LED //  GPIOSetDir(1, 6, 1 ); //  GPIOSetBitValue( 1, 6, 1);
  pinMode(USERLED, OUTPUT);
  digitalWrite(USERLED, HIGH);
    
  Serial.print("Hello!\n");
  
  tmp[0] = 0;
  Wire.beginTransmission(RTC_ADDR);
  Wire.write(0);
  Wire.endRequest();
  Wire.requestFrom(RTC_ADDR, 8);
  Wire.readBytes(tmp, 8);
  sprintf(str, "%02x:%02x:%02x\n%s\n%02x/%02x/'%02x\n", tmp[3]&0x3f, tmp[2]&0x7f, tmp[1]&0x7f, day[tmp[4]&0x07], tmp[6]&0x1f, tmp[5]&0x3f, tmp[7]);
  Serial.print(str);


  i2clcd.print("I was an lpclcd.");
  i2clcd.setCursor(0, 1);	// move to 2nd line
  i2clcd.print("Hi, everybody!");

  sw = millis();
  
  while (1){    /* Loop forever */
    
    if ( millis() - sw >= 100 ) {
      sw = millis();

      i2clcd.setCursor(0, 1);
      tmp[0] = 0;
      Wire.beginTransmission(RTC_ADDR);
      Wire.write(0);
      Wire.endRequest();
      Wire.receiveFrom(RTC_ADDR, 8);
      Wire.readBytes(tmp, 8); //Wire.receive();
//      I2C_read(&i2c, RTC_ADDR, (uint8*)tmp, 1, 8);
      sprintf(str, "%02x:%02x:%02x", tmp[3]&0x3f, tmp[2]&0x7f, tmp[1]&0x7f);
      i2clcd.print(str);
//      sprintf(str, " %02x/%02x %02x", tmp[6]&0x1f, tmp[5]&0x3f, tmp[7]);
      sprintf(str, " %06d", micros()/1000);
      i2clcd.print(str);
    }
    
    if ( digitalRead(USERBTN) == LOW ) {
      if ( ontime == 0 ) {
        ontime = millis();
        Serial.println(micros());
      }
    } else /* if ( digitalRead(USERBTN) == HIGH ) */ {
      if (  ontime > 0 && (millis() - ontime >= 5000) ) {
        Serial.println(millis() - ontime);
        tmp[0] = 1;
        tmp[1] = 0x00;
        tmp[2] = 0x11;
        tmp[3] = 0x01;
        tmp[4] = 0x06;
        tmp[5] = 0x13;
        tmp[6] = 0x07;
        tmp[7] = 0x13;
        Wire.beginTransmission(RTC_ADDR);
        Wire.write((const uint8_t *)tmp, 8);
        Wire.endTransmission();
      } else if ( ontime > 0 && (millis() - ontime >= 1000) ) {
        Serial.println(millis() - ontime);
        digitalToggle(LCDBKLT);
      } 
      ontime = 0;
    }
    
    if ( Serial.available() > 0 ) {
      i = strlen(message);
      while ( Serial.available() > 0 ) {
        c = Serial.read();
        if ( c == '\n' || c == '\r' )
          break;
        message[i] = c;
        i++;
      }
      message[i] = 0;
      i2clcd.home();
      i2clcd.print(message);
      if ( c == '\n' || c == '\r' ) {
        Serial.println(message);
        for( ; i < 16; i++) 
          i2clcd.print(' ');
        message[0] = 0;
      }
    }

  }
  
}

/******************************************************************************
**                            End Of File
******************************************************************************/
