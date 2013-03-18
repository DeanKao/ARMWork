
#ifndef _FIXED8x8_H_
#define _FIXED8x8_H_

#include <inttypes.h>
#if defined ARDUINO
#include <avr/pgmspace.h>
#elif defined ARMCMX
#include "pgm.h"
#endif

#define Fixed8x8_WIDTH 7
#define Fixed8x8_HEIGHT 8


static const uint8_t Fixed7x8[] PROGMEM = {
    0x0, 0x0, // size of zero indicates fixed width font, actual length is width * height
    0x07, // width
    0x08, // height
    0x20, // first char
    0x60, // char count
    
    // Fixed width; char width table not used !!!!
    
// 20 ( ) 
0x00, 
0x00, 
0x00, 
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 21 (!) 
0x06, // 00000110
0x5f, // 01011111
0x5f, // 01011111
0x06, // 00000110
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 22 (") 
0x07, // 00000111
0x07, // 00000111
0x00, // 00000000
0x07, // 00000111
0x07, // 00000111
0x00, // 00000000
0x00, // 00000000

// 23 (#) 
0x7f, // 01111111
0x7f, // 01111111
0x14, // 00010100
0x7f, // 01111111
0x7f, // 01111111
0x14, // 00010100
0x00, // 00000000

// 24 ($) 
0x24, // 00100100
0x2e, // 00101110
0x6b, // 01101011
0x6b, // 01101011
0x3a, // 00111010
0x12, // 00010010
0x00, // 00000000

// 25 (%) 
0x46, // 01000110
0x66, // 01100110
0x30, // 00110000
0x18, // 00011000
0x0c, // 00001100
0x66, // 01100110
0x62, // 01100010

// 26 (&) 
0x30, // 00110000
0x7a, // 01111010
0x4f, // 01001111
0x5d, // 01011101
0x37, // 00110111
0x7a, // 01111010
0x48, // 01001000

// 27 (') 
0x04, // 00000100
0x07, // 00000111
0x03, // 00000011
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 28 (() 
0x00, // 00000000
0x1c, // 00011100
0x3e, // 00111110
0x63, // 01100011
0x41, // 01000001
0x00, // 00000000
0x00, // 00000000

// 29 ()) 
0x00, // 00000000
0x41, // 01000001
0x63, // 01100011
0x3e, // 00111110
0x1c, // 00011100
0x00, // 00000000
0x00, // 00000000

// 2a (*) 
0x2a, // 00101010
0x3e, // 00111110
0x1c, // 00011100
0x1c, // 00011100
0x3e, // 00111110
0x2a, // 00101010
0x08, // 00001000

// 2b (+) 
0x08, // 00001000
0x3e, // 00111110
0x3e, // 00111110
0x08, // 00001000
0x08, // 00001000
0x00, // 00000000
0x00, // 00000000

// 2c (,) 
0x00, // 00000000
0x80, // 10000000
0xe0, // 11100000
0x60, // 01100000
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 2d (-) 
0x08, // 00001000
0x08, // 00001000
0x08, // 00001000
0x08, // 00001000
0x08, // 00001000
0x08, // 00001000
0x00, // 00000000

// 2e (.) 
0x00, // 00000000
0x00, // 00000000
0x60, // 01100000
0x60, // 01100000
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 2f (/) 
0x60, // 01100000
0x30, // 00110000
0x18, // 00011000
0x0c, // 00001100
0x06, // 00000110
0x03, // 00000011
0x01, // 00000001

// 30 (0) 
0x3e, // 00111110
0x7f, // 01111111
0x41, // 01000001
0x49, // 01001001
0x41, // 01000001
0x7f, // 01111111
0x3e, // 00111110

// 31 (1) 
0x44, // 01000100
0x42, // 01000010
0x7f, // 01111111
0x7f, // 01111111
0x40, // 01000000
0x40, // 01000000
0x00, // 00000000

// 32 (2) 
0x62, // 01100010
0x73, // 01110011
0x59, // 01011001
0x49, // 01001001
0x6f, // 01101111
0x66, // 01100110
0x00, // 00000000

// 33 (3) 
0x22, // 00100010
0x63, // 01100011
0x49, // 01001001
0x49, // 01001001
0x7f, // 01111111
0x36, // 00110110
0x00, // 00000000

// 34 (4) 
0x18, // 00011000
0x1c, // 00011100
0x16, // 00010110
0x53, // 01010011
0x7f, // 01111111
0x7f, // 01111111
0x50, // 01010000

// 35 (5) 
0x27, // 00100111
0x67, // 01100111
0x45, // 01000101
0x45, // 01000101
0x7d, // 01111101
0x39, // 00111001
0x00, // 00000000

// 36 (6) 
0x3c, // 00111100
0x7e, // 01111110
0x4b, // 01001011
0x49, // 01001001
0x79, // 01111001
0x30, // 00110000
0x00, // 00000000

// 37 (7) 
0x03, // 00000011
0x03, // 00000011
0x71, // 01110001
0x79, // 01111001
0x0f, // 00001111
0x07, // 00000111
0x00, // 00000000

// 38 (8) 
0x36, // 00110110
0x7f, // 01111111
0x49, // 01001001
0x49, // 01001001
0x7f, // 01111111
0x36, // 00110110
0x00, // 00000000

// 39 (9) 
0x06, // 00000110
0x4f, // 01001111
0x49, // 01001001
0x69, // 01101001
0x3f, // 00111111
0x1e, // 00011110
0x00, // 00000000

// 3a (:) 
0x00, // 00000000
0x00, // 00000000
0x66, // 01100110
0x66, // 01100110
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 3b (;) 
0x00, // 00000000
0x80, // 10000000
0xe6, // 11100110
0x66, // 01100110
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000

// 3c (<) 
0x08, // 00001000
0x1c, // 00011100
0x36, // 00110110
0x63, // 01100011
0x41, // 01000001
0x00, // 00000000
0x00, // 00000000

// 3d (=) 
0x24, // 00100100
0x24, // 00100100
0x24, // 00100100
0x24, // 00100100
0x24, // 00100100
0x24, // 00100100
0x00, // 00000000

// 3e (>) 
0x00, // 00000000
0x41, // 01000001
0x63, // 01100011
0x36, // 00110110
0x1c, // 00011100
0x08, // 00001000
0x00, // 00000000

// 3f (?) 
0x02, // 00000010
0x03, // 00000011
0x51, // 01010001
0x59, // 01011001
0x0f, // 00001111
0x06, // 00000110
0x00, // 00000000

// 40 (@) 
0x3e, // 00111110
0x7f, // 01111111
0x41, // 01000001
0x5d, // 01011101
0x55, // 01010101
0x57, // 01010111
0x1e, // 00011110

// 41 (A) 
0x7c, // 01111100
0x7e, // 01111110
0x13, // 00010011
0x13, // 00010011
0x7e, // 01111110
0x7c, // 01111100
0x00, // 00000000

// 42 (B) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x49, // 01001001
0x49, // 01001001
0x7f, // 01111111
0x36, // 00110110

// 43 (C) 
0x1c, // 00011100
0x3e, // 00111110
0x63, // 01100011
0x41, // 01000001
0x41, // 01000001
0x63, // 01100011
0x22, // 00100010

// 44 (D) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x41, // 01000001
0x63, // 01100011
0x3e, // 00111110
0x1c, // 00011100

// 45 (E) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x49, // 01001001
0x5d, // 01011101
0x41, // 01000001
0x63, // 01100011

// 46 (F) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x49, // 01001001
0x1d, // 00011101
0x01, // 00000001
0x03, // 00000011

// 47 (G) 
0x1c, // 00011100
0x3e, // 00111110
0x63, // 01100011
0x41, // 01000001
0x51, // 01010001
0x73, // 01110011
0x72, // 01110010

// 48 (H) 
0x7f, // 01111111
0x7f, // 01111111
0x08, // 00001000
0x08, // 00001000
0x7f, // 01111111
0x7f, // 01111111
0x00, // 00000000

// 49 (I) 
0x00, // 00000000
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x41, // 01000001
0x00, // 00000000
0x00, // 00000000

// 4a (J) 
0x30, // 00110000
0x70, // 01110000
0x40, // 01000000
0x41, // 01000001
0x7f, // 01111111
0x3f, // 00111111
0x01, // 00000001

// 4b (K) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x08, // 00001000
0x1c, // 00011100
0x77, // 01110111
0x63, // 01100011

// 4c (L) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x41, // 01000001
0x40, // 01000000
0x60, // 01100000
0x70, // 01110000

// 4d (M) 
0x7f, // 01111111
0x7f, // 01111111
0x0e, // 00001110
0x1c, // 00011100
0x0e, // 00001110
0x7f, // 01111111
0x7f, // 01111111

// 4e (N) 
0x7f, // 01111111
0x7f, // 01111111
0x06, // 00000110
0x0c, // 00001100
0x18, // 00011000
0x7f, // 01111111
0x7f, // 01111111

// 4f (O) 
0x3e, // 00111110
0x7f, // 01111111
0x41, // 01000001
0x41, // 01000001
0x41, // 01000001
0x7f, // 01111111
0x3e, // 00111110

// 50 (P) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x49, // 01001001
0x09, // 00001001
0x0f, // 00001111
0x06, // 00000110

// 51 (Q) 
0x1e, // 00011110
0x3f, // 00111111
0x21, // 00100001
0x71, // 01110001
0x7f, // 01111111
0x5e, // 01011110
0x00, // 00000000

// 52 (R) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x09, // 00001001
0x19, // 00011001
0x7f, // 01111111
0x66, // 01100110

// 53 (S) 
0x22, // 00100010
0x67, // 01100111
0x4d, // 01001101
0x59, // 01011001
0x73, // 01110011
0x22, // 00100010
0x00, // 00000000

// 54 (T) 
0x03, // 00000011
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x41, // 01000001
0x03, // 00000011
0x00, // 00000000

// 55 (U) 
0x7f, // 01111111
0x7f, // 01111111
0x40, // 01000000
0x40, // 01000000
0x7f, // 01111111
0x7f, // 01111111
0x00, // 00000000

// 56 (V) 
0x1f, // 00011111
0x3f, // 00111111
0x60, // 01100000
0x60, // 01100000
0x3f, // 00111111
0x1f, // 00011111
0x00, // 00000000

// 57 (W) 
0x7f, // 01111111
0x7f, // 01111111
0x30, // 00110000
0x18, // 00011000
0x30, // 00110000
0x7f, // 01111111
0x7f, // 01111111

// 58 (X) 
0x43, // 01000011
0x67, // 01100111
0x3c, // 00111100
0x18, // 00011000
0x3c, // 00111100
0x67, // 01100111
0x43, // 01000011

// 59 (Y) 
0x07, // 00000111
0x4f, // 01001111
0x78, // 01111000
0x78, // 01111000
0x4f, // 01001111
0x07, // 00000111
0x00, // 00000000

// 5a (Z) 
0x47, // 01000111
0x63, // 01100011
0x71, // 01110001
0x59, // 01011001
0x4d, // 01001101
0x67, // 01100111
0x73, // 01110011

// 5b ([) 
0x00, // 00000000
0x7f, // 01111111
0x7f, // 01111111
0x41, // 01000001
0x41, // 01000001
0x00, // 00000000
0x00, // 00000000

// 5c (\) 
0x01, // 00000001
0x03, // 00000011
0x06, // 00000110
0x0c, // 00001100
0x18, // 00011000
0x30, // 00110000
0x60, // 01100000

// 5d (]) 
0x00, // 00000000
0x41, // 01000001
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x00, // 00000000
0x00, // 00000000

// 5e (^) 
0x08, // 00001000
0x0c, // 00001100
0x06, // 00000110
0x03, // 00000011
0x06, // 00000110
0x0c, // 00001100
0x08, // 00001000

// 5f (_) 
0x80, // 10000000
0x80, // 10000000
0x80, // 10000000
0x80, // 10000000
0x80, // 10000000
0x80, // 10000000
0x80, // 10000000

// 60 (`) 
0x00, // 00000000
0x00, // 00000000
0x03, // 00000011
0x07, // 00000111
0x04, // 00000100
0x00, // 00000000
0x00, // 00000000

// 61 (a) 
0x20, // 00100000
0x74, // 01110100
0x54, // 01010100
0x54, // 01010100
0x3c, // 00111100
0x78, // 01111000
0x40, // 01000000

// 62 (b) 
0x41, // 01000001
0x7f, // 01111111
0x3f, // 00111111
0x44, // 01000100
0x44, // 01000100
0x7c, // 01111100
0x38, // 00111000

// 63 (c) 
0x38, // 00111000
0x7c, // 01111100
0x44, // 01000100
0x44, // 01000100
0x6c, // 01101100
0x28, // 00101000
0x00, // 00000000

// 64 (d) 
0x38, // 00111000
0x7c, // 01111100
0x44, // 01000100
0x45, // 01000101
0x3f, // 00111111
0x7f, // 01111111
0x40, // 01000000

// 65 (e) 
0x38, // 00111000
0x7c, // 01111100
0x54, // 01010100
0x54, // 01010100
0x5c, // 01011100
0x18, // 00011000
0x00, // 00000000

// 66 (f) 
0x48, // 01001000
0x7e, // 01111110
0x7f, // 01111111
0x49, // 01001001
0x03, // 00000011
0x02, // 00000010
0x00, // 00000000

// 67 (g) 
0x98, // 10011000
0xbc, // 10111100
0xa4, // 10100100
0xa4, // 10100100
0xf8, // 11111000
0x7c, // 01111100
0x04, // 00000100

// 68 (h) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x08, // 00001000
0x04, // 00000100
0x7c, // 01111100
0x78, // 01111000

// 69 (i) 
0x00, // 00000000
0x44, // 01000100
0x7d, // 01111101
0x7d, // 01111101
0x40, // 01000000
0x00, // 00000000
0x00, // 00000000

// 6a (j) 
0x60, // 01100000
0xe0, // 11100000
0x80, // 10000000
0x80, // 10000000
0xfd, // 11111101
0x7d, // 01111101
0x00, // 00000000

// 6b (k) 
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x10, // 00010000
0x38, // 00111000
0x6c, // 01101100
0x44, // 01000100

// 6c (l) 
0x00, // 00000000
0x41, // 01000001
0x7f, // 01111111
0x7f, // 01111111
0x40, // 01000000
0x00, // 00000000
0x00, // 00000000

// 6d (m) 
0x7c, // 01111100
0x7c, // 01111100
0x18, // 00011000
0x38, // 00111000
0x1c, // 00011100
0x7c, // 01111100
0x78, // 01111000

// 6e (n) 
0x7c, // 01111100
0x7c, // 01111100
0x04, // 00000100
0x04, // 00000100
0x7c, // 01111100
0x78, // 01111000
0x00, // 00000000

// 6f (o) 
0x38, // 00111000
0x7c, // 01111100
0x44, // 01000100
0x44, // 01000100
0x7c, // 01111100
0x38, // 00111000
0x00, // 00000000

// 70 (p) 
0x84, // 10000100
0xfc, // 11111100
0xf8, // 11111000
0xa4, // 10100100
0x24, // 00100100
0x3c, // 00111100
0x18, // 00011000

// 71 (q) 
0x18, // 00011000
0x3c, // 00111100
0x24, // 00100100
0xa4, // 10100100
0xf8, // 11111000
0xfc, // 11111100
0x84, // 10000100

// 72 (r) 
0x44, // 01000100
0x7c, // 01111100
0x78, // 01111000
0x4c, // 01001100
0x04, // 00000100
0x1c, // 00011100
0x18, // 00011000

// 73 (s) 
0x48, // 01001000
0x5c, // 01011100
0x54, // 01010100
0x54, // 01010100
0x74, // 01110100
0x24, // 00100100
0x00, // 00000000

// 74 (t) 
0x00, // 00000000
0x04, // 00000100
0x3e, // 00111110
0x7f, // 01111111
0x44, // 01000100
0x24, // 00100100
0x00, // 00000000

// 75 (u) 
0x3c, // 00111100
0x7c, // 01111100
0x40, // 01000000
0x40, // 01000000
0x3c, // 00111100
0x7c, // 01111100
0x40, // 01000000

// 76 (v) 
0x1c, // 00011100
0x3c, // 00111100
0x60, // 01100000
0x60, // 01100000
0x3c, // 00111100
0x1c, // 00011100
0x00, // 00000000

// 77 (w) 
0x3c, // 00111100
0x7c, // 01111100
0x70, // 01110000
0x38, // 00111000
0x70, // 01110000
0x7c, // 01111100
0x3c, // 00111100

// 78 (x) 
0x44, // 01000100
0x6c, // 01101100
0x38, // 00111000
0x10, // 00010000
0x38, // 00111000
0x6c, // 01101100
0x44, // 01000100

// 79 (y) 
0x9c, // 10011100
0xbc, // 10111100
0xa0, // 10100000
0xa0, // 10100000
0xfc, // 11111100
0x7c, // 01111100
0x00, // 00000000

// 7a (z) 
0x4c, // 01001100
0x64, // 01100100
0x74, // 01110100
0x5c, // 01011100
0x4c, // 01001100
0x64, // 01100100
0x00, // 00000000

// 7b ({) 
0x08, // 00001000
0x08, // 00001000
0x3e, // 00111110
0x77, // 01110111
0x41, // 01000001
0x41, // 01000001
0x00, // 00000000

// 7c (|) 
0x00, // 00000000
0x00, // 00000000
0x00, // 00000000
0x77, // 01110111
0x77, // 01110111
0x00, // 00000000
0x00, // 00000000

// 7d (}) 
0x41, // 01000001
0x41, // 01000001
0x77, // 01110111
0x3e, // 00111110
0x08, // 00001000
0x08, // 00001000
0x00, // 00000000

// 7e (~) 
0x02, // 00000010
0x03, // 00000011
0x01, // 00000001
0x03, // 00000011
0x02, // 00000010
0x03, // 00000011
0x01, // 00000001

// 7f () 
0x00, // 00000000
0x06, // 00000110
0x0f, // 00001111
0x09, // 00001001
0x0f, // 00001111
0x06, // 00000110
0x00, // 00000000    
};

#endif
