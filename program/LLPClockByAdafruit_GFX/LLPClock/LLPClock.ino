#define ESP8266

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <SPI.h>
#include "DancingScript_Bold30pt7b.h"

#if defined(ARDUINO_FEATHER_ESP32) // Feather Huzzah32
  #define TFT_CS         14
  #define TFT_RST        15
  #define TFT_DC         32

#elif defined(ESP8266)
  #define TFT_CS         D8
  #define TFT_RST        D4
  #define TFT_DC         D3

#else
  // For the breakout board, you can use any 2 or 3 pins.
  // These pins will also work for the 1.8" TFT shield.
  #define TFT_CS        10
  #define TFT_RST        9 // Or set to -1 and connect to Arduino RESET pin
  #define TFT_DC         8
#endif

// For 1.44" and 1.8" TFT with ST7735 use:
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);



float p = 3.1415926;
// this is the bitmap, change this variable for your specification.
#define TEST_HEIGHT 160
#define TEST_WIDTH 80
// array size is 38400

void setup() 
{
  Serial.begin(115200);
  
  // Use this initializer if using a 1.8" TFT screen:
  tft.initR(INITR_BLACKTAB);      // Init ST7735S chip, black tab
  tft.initR(INITR_MINI160x80_PLUGIN);  // Init ST7735S mini display
  tft.setRotation(3);

  
   // large block of text
  tft.fillScreen(ST77XX_BLACK);
  testdrawtext("12:34", ST77XX_WHITE);


  tft.fillRect(20,20 , 30, 30, 0xFFFF);
  tft.fillRect(50,20 , 30, 30, 0x0821);
  tft.fillRect(80,20 , 30, 30, 0x1863);
}

void loop() {


}

void testdrawtext(char *text, uint16_t color) {
  tft.setCursor(14, 50);
  //tft.setTextSize(4);
  tft.setFont(&DancingScript_Bold30pt7b );
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}
