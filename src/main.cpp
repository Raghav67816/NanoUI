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

Color white = {255, 255, 255};
Color black = {0, 0, 0};

int currentVal = 0;

Stack screenStack(display, gfx);

Screen screen(&display, "Scroll Demo");

Column layout(
    0,
    0,
    SCREEN_WIDTH,
    SCREEN_HEIGHT - 10
);

ScrollWidget scrollWidget(
    100,
    60
);

Label label(
    20,
    10,
    "Label 1",
    white
);

Label label_b(
    20,
    10,
    "Label 2",
    white
);

ProgressBar progressBar(
    100,
    10
);

void dirtyCheck(){
    Serial.print("Scroll Width is Dirty ?: ");
    Serial.println(screen.children.at(1)->isDirty);
}

void setup(){

    pinMode(BTN_PIN, INPUT_PULLUP);
    Serial.begin(9600);

    if(!oled.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
        return;
    }

    layout.addChild(&label);

    Serial.println("When adding to sw");
    Serial.print("X: ");
    Serial.println(progressBar.x);
    Serial.print("Y: ");
    Serial.println(progressBar.y);

    scrollWidget.addChild(&progressBar);
    layout.addChild(&scrollWidget);
    // layout.addChild(&progressBar);
    screen.addChild(&layout);

    screenStack.addScreen(screen);

    display.clear();
    screenStack.goTo(
        display,
        screen,
        gfx
    );
    display.flush();
}

void updateProgress(){
    currentVal++;
    progressBar.setProgress(currentVal);
    label.setText("Writing Prog...");
}

void loop(){
    if(digitalRead(BTN_PIN) == LOW){
        Serial.println("Button Pressed");
        delay(200);
    }

    updateProgress();
    screenStack.renderApp(gfx);
    delay(1000);

    dirtyCheck();
}