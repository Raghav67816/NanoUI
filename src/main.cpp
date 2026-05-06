#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Stack.h"
#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/Button.h"
#include "widgets/Screen.h"
#include "widgets/Label.h"

#include "layouts/Column.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_PIN 4

Adafruit_SSD1306 oled(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

OLEDisplay display(
    SCREEN_WIDTH, 
    SCREEN_HEIGHT,
    &oled
);

Graphics gfx(&display);

Color white = {255, 255, 255};
Color black = {0, 0, 0};

// Stack screenStack(display, gfx);

Screen screen_a(&display, "Screen A");
Column col(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 10);
Button btn(40, 20, "btn", white, black);
Label label(20, 10, "Label 1", white);

void changeScreen(){
  Serial.println("Hello");
}

void setup() {

  pinMode(BTN_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    return;
  }


  col.addChild(&label);
  col.addChild(&btn);
  screen_a.addChild(&col);

  // btn.bindEvent(BUTTON_PRESSED, changeScreen);

  display.clear();
  screen_a.draw(gfx);
  display.flush();
}

void loop() {
  if(digitalRead(BTN_PIN) == LOW){
    // btn.onEvent(BUTTON_PRESSED);
    Serial.println("Btn Pressed");
    delay(200);
  }
}