#include "Screen.h"
#include "Graphics.h"
#include "Adafruit_SSD1306.h"
#include "Color.h"

#define TITLE_BAR_HEIGHT 10

void Screen::setTitle(const char* title, Color color){

    Color white = {255, 255, 255};

    gfx->fillRect(0, 0, display->getWidth(), TITLE_BAR_HEIGHT, white);
    gfx->drawText(
        (display->getWidth() - gfx->getTextWidth(title)) / 2,
        (TITLE_BAR_HEIGHT - 7)/2,
        title,
        color
    );
}

void Screen::draw(){
    Color color = {255, 255, 255};
    gfx->drawRect(0, display->getWidth(), display->getHeight(), color);
}

void Screen::onEvent(int event){

}

void Screen::addChild(Widget *widget){

}
