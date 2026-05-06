#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Stack.h"
#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/Button.h"
#include "widgets/Screen.h"

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

Stack screenStack(display, gfx);

// Screen 1
Screen screen_a(&display, "Screen 1");
Screen screen_b(&display, "Screen 2");
Screen screen_c(&display, "Screen 3");

Button btn(20, 20, 40, 20, "Button A", white, black);
Button btn(20, 20, 40, 20, "Button B", white, black);

Column col();

void changeScreen(){
  screenStack.goTo(display, screen_b, gfx);
}

void setup() {

  pinMode(BTN_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    return;
  }

  display.clear();

  btn.bindEvent(BUTTON_PRESSED, changeScreen);
  screen_a.addChild(&btn);

  screenStack.addScreen(screen_a);
  screenStack.addScreen(screen_b);
  screenStack.addScreen(screen_c);

  screenStack.goTo(display, screen_a, gfx);
}

void loop() {
  if(digitalRead(BTN_PIN) == LOW){
    btn.onEvent(BUTTON_PRESSED);
    Serial.println("Btn Pressed");
    delay(200);
  }
}