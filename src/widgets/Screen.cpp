#include "Screen.h"
#include "Graphics.h"
#include "Adafruit_SSD1306.h"
#include "Color.h"

#define TITLE_BAR_HEIGHT 10

void Screen::draw(Graphics &gfx){
    Color color = {255, 255, 255};
    gfx.drawRect(0, display->getWidth(), display->getHeight(), color);

    for(Widget *widget: children){
        widget->draw(gfx);
    }
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

void Screen::addChild(Widget *child){
    children.push_back(child);
}

void Screen::bindEvent(EventType event, std::function<void()> callback){}
void Screen::onEvent(EventType event){}
