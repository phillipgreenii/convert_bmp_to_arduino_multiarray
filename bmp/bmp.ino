// IMPORTANT: Adafruit_TFTLCD LIBRARY MUST BE SPECIFICALLY
// CONFIGURED FOR EITHER THE TFT SHIELD OR THE BREAKOUT BOARD.
// SEE RELEVANT COMMENTS IN Adafruit_TFTLCD.h FOR SETUP.

// Modified for SPFD5408 Library by Joao Lopes
// Version 0.9.2 - Rotation for Mega and screen initial

// *** SPFD5408 change -- Begin
#include <SPFD5408_Adafruit_GFX.h>    // Core graphics library
#include <SPFD5408_Adafruit_TFTLCD.h> // Hardware-specific library
#include <SPFD5408_TouchScreen.h>
// *** SPFD5408 change -- End


// The control pins for the LCD can be assigned to any digital or
// analog pins...but we'll use the analog pins as this allows us to
// double up the pins with the touch screen (see the TFT paint example).
#define LCD_CS A3 // Chip Select goes to Analog 3
#define LCD_CD A2 // Command/Data goes to Analog 2
#define LCD_WR A1 // LCD Write goes to Analog 1
#define LCD_RD A0 // LCD Read goes to Analog 0

#define LCD_RESET A4 // Can alternately just connect to Arduino's reset pin

// When using the BREAKOUT BOARD only, use these 8 data lines to the LCD:
// For the Arduino Uno, Duemilanove, Diecimila, etc.:
//   D0 connects to digital pin 8  (Notice these are
//   D1 connects to digital pin 9   NOT in order!)
//   D2 connects to digital pin 2
//   D3 connects to digital pin 3
//   D4 connects to digital pin 4
//   D5 connects to digital pin 5
//   D6 connects to digital pin 6
//   D7 connects to digital pin 7
// For the Arduino Mega, use digital pins 22 through 29
// (on the 2-row header at the end of the board).

// Assign human-readable names to some common 16-bit color values:
#define  BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
// If using the shield, all control and data lines are fixed, and
// a simpler declaration can optionally be used:
// Adafruit_TFTLCD tft;

// -- Setup

void setup(void) {
  
  Serial.begin(9600);
  
  progmemPrintln(PSTR("TFT LCD test"));

#ifdef USE_ADAFRUIT_SHIELD_PINOUT
  progmemPrintln(PSTR("Using Adafruit 2.8\" TFT Arduino Shield Pinout"));
#else
  progmemPrintln(PSTR("Using Adafruit 2.8\" TFT Breakout Board Pinout"));
#endif

  tft.reset();
 
  // *** SPFD5408 change -- Begin

// Original code commented

//  uint16_t identifier = tft.readID();
//
//  if(identifier == 0x9325) {
//    Serial.println(F("Found ILI9325 LCD driver"));
//  } else if(identifier == 0x9328) {
//    Serial.println(F("Found ILI9328 LCD driver"));
//  } else if(identifier == 0x7575) {
//    Serial.println(F("Found HX8347G LCD driver"));
//  } else if(identifier == 0x9341) {
//    Serial.println(F("Found ILI9341 LCD driver"));
//  } else if(identifier == 0x8357) {
//    Serial.println(F("Found HX8357D LCD driver"));
//  } else {
//    Serial.print(F("Unknown LCD driver chip: "));
//    Serial.println(identifier, HEX);
//    Serial.println(F("If using the Adafruit 2.8\" TFT Arduino shield, the line:"));
//    Serial.println(F("  #define USE_ADAFRUIT_SHIELD_PINOUT"));
//    Serial.println(F("should appear in the library header (Adafruit_TFT.h)."));
//    Serial.println(F("If using the breakout board, it should NOT be #defined!"));
//    Serial.println(F("Also if using the breakout, double-check that all wiring"));
//    Serial.println(F("matches the tutorial."));
//    return;
//  }
//
//  tft.begin(identifier);

  // Code changed to works 
  
  tft.begin(0x9341); // SDFP5408

  tft.setRotation(0); // Need for the Mega, please changed for your choice or rotation initial

  // *** SPFD5408 change -- End

progmemPrint(PSTR("BMP                    "));
  Serial.println(displayBmp());
}

void loop(void) {
 delay(10000);
}

//REPLACE THIS WITH YOUR IMAGE (update width if necessary)
uint16_t bmp[][20] = {
 {0x7b0e,0x72cd,0x72cc,0x834f,0x72ed,0x6aac,0x834f,0x72cd,0x7b0e,0x832f,0x41a7,0x626a,0x5208,0x00,0x5207,0x8ae8,0x7288,0x3145,0x3965,0x49e7},
 {0x832f,0x7aed,0x830b,0xa329,0x8ae9,0x7b0d,0x832f,0x6aac,0x7b0e,0x832e,0x41a7,0x626a,0x41a7,0x41a5,0x8ae8,0x9264,0x8a64,0x4186,0x2945,0x51e8},
 {0x832f,0x832e,0x8b2a,0x9aa4,0x9a83,0x9309,0x8b6e,0x6aac,0x7b0e,0x834f,0x49e8,0x626a,0x41e7,0x8b4a,0x8225,0x8224,0x8223,0x6206,0x2124,0x5208},
 {0x832f,0x8b6f,0x8b09,0x8a64,0xa327,0x8a22,0x932a,0x72cc,0x72cd,0x7b0e,0x41a7,0x5209,0x72a9,0x8b08,0x8225,0x8a65,0x71c3,0x7266,0x2923,0x49a7},
 {0x626b,0x7b0c,0x82c8,0x8223,0xab68,0x9265,0x8a65,0x8b09,0x6a8a,0x7b0c,0x5a48,0x7aea,0xa3cb,0x7a04,0x92c7,0x92c6,0x6982,0x5184,0x20,0x626a},
 {0x72cd,0x7b0d,0x6a07,0x79c2,0xa348,0xa348,0x8223,0xa368,0xbccf,0x8b6d,0x8b8c,0xbc8f,0xa3a9,0x8244,0x9ae6,0x8a85,0x79c3,0x4102,0x00,0x6aab},
 {0x6269,0x72eb,0x6a06,0x7182,0x92a6,0xab88,0x9284,0x9b27,0xbc8d,0x7288,0x7287,0xb44c,0x9b26,0x9326,0xa3aa,0x9b49,0x92a6,0x6205,0x00,0x5a4a},
 {0x51e4,0x72c8,0x82e8,0x81e2,0x9aa6,0xa328,0xa369,0xac0b,0xcd72,0xde16,0xac4d,0xa3a9,0xc4ef,0xd5d4,0xc531,0xbcaf,0xa3cb,0x7a86,0x28c2,0x4186},
 {0x51e5,0x8b4a,0x8b08,0x9b28,0xb44d,0xb42b,0xb44c,0xcd72,0xe698,0xeef9,0xde15,0xc4ef,0xd5d3,0xd5d4,0xb44d,0xa3a9,0xa3cb,0x7aa7,0x1881,0x3966},
 {0x5a26,0x6a66,0x9b48,0xbc4d,0xbc6e,0xabea,0xc4ad,0xe676,0xf71a,0xee97,0xe655,0xddd3,0xcd30,0xcd51,0xcd52,0xac4e,0xa3a9,0xa3cb,0x7246,0x5208},
 {0x49a4,0x6a04,0x9ae6,0xbc4c,0xb40b,0xac0a,0xcd30,0xeeb7,0xf73a,0xeeb8,0xe655,0xeeb8,0xeeb8,0xe656,0xde36,0xbcf1,0xa3a9,0xabc9,0x82a6,0x7aaa},
 {0x6246,0x8ac5,0xaba9,0xcd0e,0xbc6b,0xabea,0xc4ee,0xe655,0xf6d8,0xee96,0xee76,0xf6f8,0xf6d8,0xeeb7,0xe635,0xbcce,0x9327,0xa388,0x9348,0x51a4},
 {0x7aa6,0xa3a8,0xb40a,0xbc4b,0xa3a9,0xabea,0xd570,0xddf2,0xdd70,0xcccd,0xbc6c,0xccce,0xd52e,0xcced,0xc4ad,0xccee,0xa3ca,0x9306,0x9327,0x5123},
 {0x7ac7,0xbc4b,0xbc2a,0xb42a,0xabca,0xbc6c,0xcd0e,0xcccd,0xb3c9,0xa2c2,0xa2c1,0x9a40,0x9a81,0x9263,0x7a45,0xac0c,0xc4ce,0x9b68,0x8ac5,0x58e3},
 {0x8b29,0xb42a,0xbc6b,0xc4ee,0xb42b,0xbc2b,0xb42c,0x82c8,0x69e6,0x8a65,0xb3a8,0xc48c,0xa327,0x71e5,0x29a7,0x6160,0xbc4d,0xabeb,0x8264,0x6924},
 {0x8308,0xa388,0xbc6b,0xcd71,0xbc6c,0xbc4b,0xa367,0x28e4,0x925,0x69e4,0xb40b,0xddb1,0xccce,0x8ae7,0x59c4,0x71c2,0x8aa6,0xa3aa,0x7204,0x58a3},
 {0x8309,0x9306,0xb46c,0xbcad,0xb3e9,0xab87,0xab47,0x8244,0x5121,0x8286,0xab88,0xb3e9,0xab88,0x8265,0x7a04,0x7a03,0x79e3,0x9328,0x6a05,0x4965},
 {0x72c8,0x7a86,0x9b68,0xaba8,0xaba8,0x9ae5,0x9264,0xa326,0xab89,0xa348,0xab88,0xa367,0x92c5,0x8a85,0x7204,0x71e3,0x8265,0x8ae7,0x4983,0x28e3},
 {0x5a26,0x6204,0x8b27,0xac0a,0xb3a8,0xa2e5,0x92a4,0xab88,0x9b27,0x8244,0xb3a8,0xb3e9,0x9b26,0xa367,0x7a04,0x6183,0x7a24,0x7a44,0x49c4,0x2945},
 {0x49e6,0x6246,0x9348,0xb42b,0xb3c8,0x9ac4,0xab88,0xab88,0xa347,0xb3a8,0xab26,0x8265,0x69e4,0x92a5,0x8a23,0x81e2,0xa3a9,0x9349,0x834b,0x5a69},
 {0x7265,0x7a84,0x9b89,0xb40a,0xa326,0xabc9,0xbc6b,0xb3e9,0xbbe9,0xb3a7,0x7a23,0x20a2,0x10c3,0x5183,0xa326,0x92a4,0xabc9,0xc4cd,0xc533,0x9450},
 {0xac4e,0xbd11,0xac6d,0xabc9,0xab88,0xbc2b,0xa388,0x92e6,0x7a03,0xa2e5,0x8244,0x3964,0x3985,0x6205,0xa327,0x9b26,0xaba8,0xc4ac,0xd593,0xde79},
 {0xde58,0xe6da,0xd637,0xa3eb,0xa346,0x92e6,0x7a24,0x61c3,0x5a03,0x7a65,0x8245,0x7a66,0x6a24,0x8a60,0x9220,0xa368,0xb3ea,0xc4ac,0xcd30,0xde99},
 {0xcd95,0xcdd6,0xde78,0xc594,0x8aa2,0x8aa5,0x82a6,0x72a4,0x8b66,0x6a20,0x6940,0x7a63,0x8b28,0xac2d,0xcd53,0xde36,0xde58,0xc4ef,0xc4ef,0xd638},
 {0xd637,0xde37,0xd5f6,0xd617,0xbd12,0xb48f,0xb4d0,0x7b03,0x8302,0xc573,0xde37,0xde58,0xe6b9,0xef1b,0xf75d,0xf73c,0xf75d,0xddf5,0xbccf,0xcdd6},
 {0xe6ba,0xd617,0xc574,0xcd95,0xd617,0xd5d5,0x9bec,0x6a60,0xbd53,0xf77d,0xf77d,0xf77d,0xf77e,0xf77d,0xf77d,0xef3c,0xef1c,0xde37,0xd637,0xd658},
 {0xcdf7,0xd5f7,0xd5f7,0xcdb5,0xcd95,0xde58,0xa48f,0x8346,0xe6ba,0xef1c,0xe6fb,0xef3c,0xef3d,0xef3c,0xef3c,0xef3c,0xf75d,0xef3c,0xe6db,0xcdf7}
};

unsigned long displayBmp() {

  unsigned long start = micros();
  tft.fillScreen(BLACK);

  for (int i=0;i<20;i++) {
    //tft.drawPixel(i,0, bmp[0][i]);
    tft.drawPixel(i,0, bmp[0][i]);
    for(int j=0;j<27;j++) {

      int scale=12;

      for (int m=0;m<scale;m++) {

        for(int n=0;n<scale;n++) {
          tft.drawPixel(i*scale+m,j*scale+n, bmp[j][i]);
        }
   
      }
    }
  }

  return micros() - start;
}


// Copy string from flash to serial port
// Source string MUST be inside a PSTR() declaration!
void progmemPrint(const char *str) {
  char c;
  while(c = pgm_read_byte(str++)) Serial.print(c);
}

// Same as above, with trailing newline
void progmemPrintln(const char *str) {
  progmemPrint(str);
  Serial.println();
}

