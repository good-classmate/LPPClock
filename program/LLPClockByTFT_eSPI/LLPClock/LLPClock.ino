#include <SPI.h>
#include <TFT_eSPI.h>       // Hardware-specific library
#include "DancingScriptBold64.h"
TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

void setup() {
  tft.begin();
  
  tft.setRotation(3);
  tft.fillScreen(TFT_BLACK);

  tft.loadFont(DancingScriptBold64); 
  tft.setCursor(8, 13);
  tft.setTextColor(TFT_WHITE, TFT_BLACK); // Set the font colour AND the background colour
                                          // so the anti-aliasing works
  tft.println("12:34");
}

void loop() {
  

}
