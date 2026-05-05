#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/Button.h"
#include "widgets/Screen.h"

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

// Home Screen
Screen homeScreen(&display);
Button click(20, 20, 40, 20, "Click", white, black);

void onButtonClicked(){
  Serial.println("Hello from click");
}

void setup() {

  pinMode(BTN_PIN, INPUT_PULLUP);

  Serial.begin(9600);
  if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
    return;
  }

  click.bindEvent(BUTTON_PRESSED, onButtonClicked);

  display.clear();
  homeScreen.setTitle(&gfx, "Home", black);
  homeScreen.addChild(&click);
  homeScreen.draw(gfx);
  display.flush();
}

void loop() {
  if(digitalRead(BTN_PIN) == LOW){
    Serial.println("Btn Pressed");
    click.onEvent(BUTTON_PRESSED);
    delay(200);
  }
}