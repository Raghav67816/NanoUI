#include "TFTDisplay.h"

void TFTDisplay::clear(){
    this->display->clear();
}

void TFTDisplay::flush(){
    display->display();
}

void TFTDisplay::drawPixel(int x, int y, Color color){
    if(x < 0 || y < 0 || x > w || y > h){
        return;
    }

    int _color = 0;
    if(color.r + color.g + color.b == (3*255)){
        _color = 1;
    } else{
        _color = 0;
    }

    display->drawPixel(x, y, display->color565(color.r, color.g, color.b));
}

int TFTDisplay::getHeight(){
    return h;
}

int TFTDisplay::getWidth(){
    return w;
}
