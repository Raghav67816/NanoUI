#include "OLEDisplay.h"

void OLEDisplay::clear(){
    display->clearDisplay();
}

void OLEDisplay::flush(){
    display->display();
}

void OLEDisplay::drawPixel(int x, int y, bool color){
    if(x < 0 || y < 0 || x > w || y > h){
        return;
    }

    display->drawPixel(
        x, y, color ? SSD1306_WHITE : SSD1306_BLACK
    );
}

int OLEDisplay::getHeight(){
    return h;
}

int OLEDisplay::getWidth(){
    return w;
}
