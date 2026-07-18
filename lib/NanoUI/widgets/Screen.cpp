#include "Screen.h"

#include "widgets/Button.h"

#define TITLE_BAR_HEIGHT 10

void Screen::draw(Graphics &gfx, Theme* theme, int offsetX, int offsetY){
    Color white = {255, 255, 255};
    gfx.drawRect(0, 0, display->getWidth(), display->getHeight(), white);

    Color black = Color {0, 0, 0};
    setTitle(&gfx, this->title, black);

    for(Widget *widget: children){
        widget->draw(gfx, theme);
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

    gfx->fillRect(0, 0, display->getWidth(), this->title_bar_height, white);
    gfx->drawText(
        (display->getWidth() - gfx->getTextWidth(title)) / 2,
        (this->title_bar_height - 7)/2,
        title,
        titleColor
    );
}


void Screen::processInput(InputTypes inputType, Cordinates points){}

void Screen::set_title_bar_height(int h){
    this->title_bar_height = h;
}
