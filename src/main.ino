#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "OLEDisplay.h"
#include "widgets/Screen.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OLEDisplay display(
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    &oled
);

Graphics gfx(&display);
Screen home(&display, &gfx);

void setup() {

  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clear();
  home.draw();
  home.setTitle("Home", SSD1306_BLACK);
  display.flush();
}

void loop() {}
