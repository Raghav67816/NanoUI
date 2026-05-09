#include "Screen.h"
#include "Adafruit_SSD1306.h"

#include "widgets/Button.h"

#include <Arduino.h>

#define TITLE_BAR_HEIGHT 10

void Screen::draw(Graphics &gfx, int offsetX, int offsetY){
    Color white = {255, 255, 255};
    gfx.drawRect(0, 0, display->getWidth(), display->getHeight(), white);

    Color black = Color {0, 0, 0};
    setTitle(&gfx, this->title, black);

    for(Widget *widget: children){
        Serial.print("Is Layout Dirty: ");
        Serial.println(widget->isDirty);
        widget->draw(gfx);
    }
}

bool Screen::_dirtyCheck(){
    for(Widget *child: children){
        if(child->isDirty){
            return true;
        }
    }

    return false;
}


void Screen::setTitle(Graphics *gfx, const char* title, Color titleColor){

    Color white = {255, 255, 255};

    gfx->fillRect(0, 0, display->getWidth(), TITLE_BAR_HEIGHT, white);
    gfx->drawText(
        (display->getWidth() - gfx->getTextWidth(title)) / 2,
        (TITLE_BAR_HEIGHT - 7)/2,
        title,
        titleColor
    );
}

void Screen::bindEvent(EventType event, std::function<void()> callback){}
void Screen::onEvent(EventType event){}
