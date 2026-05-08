#include "Button.h"

#define PADDING 2

void Button::draw(Graphics &gfx){
    if(!gfx.boundCheck(x, x + w, y, y + h)) return;

    int textLen = gfx.getTextWidth(labelText);

    int textX = x + (w - textLen) / 2;
    int textY = y + (h - 7) / 2;
    
    gfx.fillRect(x, y, w, h, bgColor);
    gfx.drawText(
        textX,
        textY,
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
    isDirty = true;
}

char* Button::text(){
    return labelText;
}

void Button::bindEvent(EventType event, std::function<void()> callback){
    if(event == BUTTON_PRESSED){
        _onPress = callback;
    }
}

void Button::onEvent(EventType event){
    if(event == BUTTON_PRESSED && _onPress){
        _onPress();
    }
}

