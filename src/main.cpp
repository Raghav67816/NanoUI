#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Stack.h"
#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/Screen.h"
#include "widgets/Label.h"
#include "widgets/ProgressBar.h"
#include "widgets/ScrollWidget.h"

#include "layouts/Column.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_PIN 4

Adafruit_SSD1306 oled(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &Wire,
    -1
);

OLEDisplay display(
    SCREEN_WIDTH,
    SCREEN_HEIGHT,
    &oled
);

Graphics gfx(&display);


void setup(){

    pinMode(BTN_PIN, INPUT_PULLUP);
    Serial.begin(9600);

    if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
        return;
    }
}

void loop(){
    if(digitalRead(BTN_PIN) == LOW){
        Serial.println("Button Pressed");
        delay(200);
    }
}