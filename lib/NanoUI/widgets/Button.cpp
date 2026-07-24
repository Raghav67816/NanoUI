#include "Button.h"
#include "Screen.h"

#define PADDING 2

void Button::draw(Graphics &gfx, Theme* theme, int offsetX, int offsetY){

    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    if(!gfx.boundCheck(drawX, drawY + w, drawY, drawY + h)) return;

    int textLen = gfx.getTextWidth(labelText);

    int textX = x + (w - textLen) / 2;
    int textY = y + (h - 7) / 2;
    
    gfx.fillRect(drawX, drawY, w, h, bgColor);
    gfx.drawText(
        textX - offsetX,
        textY - offsetY,
        labelText,
        textColor
    );
}

void Button::measureGeo(Graphics &gfx){

    int textLen = gfx.getTextWidth(labelText);

    if(w < textLen + (2 * PADDING)){
        w = textLen + (2 * PADDING);
    }

    if(h < 7 + (2 * PADDING)){
        h = 7 + (2 * PADDING);
    }
}

void Button::setText(Graphics &gfx, char* text){
    labelText = text;
    Widget* tParent = this->getTopLevelParent();
    Screen* tScreen = static_cast<Screen*>(tParent);
    this->invalidate(tScreen, this->getBounds());
}

char* Button::text(){
    return labelText;
}

void Button::processInput(InputTypes inputType, Cordinates point){
    if(this->x + this->w <= point.x && this->y + this->h <= point.y){
        if(inputType == TOUCH){
            this->onPress.broadcast();
        }
    }
}

