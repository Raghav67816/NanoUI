#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "OLEDisplay.h"
#include "Display.h"
#include "Graphics.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OLEDisplay display(
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    &oled
);

Graphics gfx(&display);

void setup() {

  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clear();
  gfx.fillRect(2, 2, 20, 20, SSD1306_WHITE);
  display.flush();
}

void loop() {}
