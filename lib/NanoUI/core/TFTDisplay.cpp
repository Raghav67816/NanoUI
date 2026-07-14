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

    display->drawPixel(x, y, display->color565(color.r, color.g, color.b));
}

int TFTDisplay::getHeight(){
    return h;
}

int TFTDisplay::getWidth(){
    return w;
}
