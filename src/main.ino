#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "OLEDisplay.h"
#include "widgets/Screen.h"
#include "widgets/Label.h"
#include "widgets/Button.h"

#include "widgets/Color.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OLEDisplay display(
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    &oled
);

Color black = {0, 0, 0};
Color white = {255, 255, 255};

Graphics gfx(&display);

Screen home(&display);

Button btn(20, 20, 40, 20, "Click", white, black);

void onButtonPressed(){
  gfx.fillRect(10, 10, 20, 20, white);
};

bool lastState = HIGH;

void setup() {
  Serial.begin(115200);
  pinMode(4, INPUT_PULLUP);

  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    return;
  }
  display.clear();
  home.setTitle(&gfx, "Home", black);
  btn.bindEvent(BUTTON_PRESSED, onButtonPressed);
  home.addChild(&btn);
  home.draw(gfx);
  display.flush();
}

void loop() {

  if (digitalRead(4) == LOW) {
    Serial.println("button pressed");
  }

  delay(100);
}
