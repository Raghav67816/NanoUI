#include "OLEDisplay.h"

void OLEDisplay::clear(){
    display->clearDisplay();
}

void OLEDisplay::flush(){
    display->display();
}

void OLEDisplay::drawPixel(int x, int y, uint16_t color){
    if(x < 0 || y < 0 || x > w || y > h){
        return;
    }

    display->drawPixel(
        x, y, color
    );
}

int OLEDisplay::getHeight(){
    return h;
}

int OLEDisplay::getWidth(){
    return w;
}
