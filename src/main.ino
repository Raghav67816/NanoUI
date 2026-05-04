#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "OLEDisplay.h"
#include "widgets/Screen.h"
#include "widgets/Label.h"

#include "widgets/Color.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OLEDisplay display(
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    &oled
);

Graphics gfx(&display);

Screen home(&display);
Color black = {0, 0, 0};
Color white = {255, 255, 255};
Label label(20, 20, "Nano UI", white);


void setup() {

  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    for(;;); // Don't proceed, loop forever
  }
  display.clear();
  home.addChild(&label);
  home.setTitle(&gfx, "Home", black);
  home.draw(gfx);
  display.flush();
}

void loop() {}
