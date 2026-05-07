#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Stack.h"
#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/ProgressBar.h"
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

int currentVal = 0;

Graphics gfx(&display);

Color white = {255, 255, 255};
Color black = {0, 0, 0};

Stack screenStack(display, gfx);

Screen screen_a(&display, "Screen A");
Column col(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 10);
ProgressBar progBar(100, 10);
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

  screenStack.addScreen(screen_a);

  col.addChild(&label);
  col.addChild(&progBar);
  screen_a.addChild(&col);

  display.clear();
  screenStack.goTo(display, screen_a, gfx);
  display.flush();
}

void updateProg(){
  currentVal += 1;
  progBar.setProgress(currentVal);
  Serial.println("Writing prog....");
  delay(1000);
}


void loop() {
  if(digitalRead(BTN_PIN) == LOW){
    Serial.println("Btn Pressed");
    delay(200);
  }

  updateProg();

  screenStack.renderApp(gfx);
}