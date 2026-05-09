#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "core/Stack.h"
#include "core/Graphics.h"
#include "core/OLEDisplay.h"

#include "widgets/Screen.h"
#include "widgets/Label.h"
#include "widgets/ScrollWidget.h"
#include "widgets/ProgressBar.h"

#include "layouts/Column.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BTN_PIN 4

int scrollX = 0;

int currentProg = 0;

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

ScrollWidget scrollWidget(0, 0, 100, 50);

Color white = {255, 255, 255};

Stack screenStack(display, gfx);

Screen screen_a(&display, "Screen A");

Column root_layout(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT - 10);

Label label(20, 10, "Label 1", white);
Label label_b(20, 10, "Label 2", white);
Label label_c(20, 10, "Label 3", white);

void setup(){

    pinMode(BTN_PIN, INPUT_PULLUP);
    Serial.begin(9600);

    if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
        return;
    }

    root_layout.addChild(&scrollWidget);
    screen_a.addChild(&root_layout);
    screenStack.addScreen(screen_a);

    display.clear();
    screenStack.goTo(display, screen_a, gfx);
    screenStack.renderApp(gfx);
    display.flush();

    screen_a.debugTree(0);
}


void loop(){
    if(digitalRead(BTN_PIN) == LOW){
        Serial.println("Button Pressed");
        delay(200);
    }

    screenStack.renderApp(gfx);
    delay(500);
}