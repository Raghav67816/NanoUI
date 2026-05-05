#include "OLEDisplay.h"

void OLEDisplay::clear(){
    display->clearDisplay();
}

void OLEDisplay::flush(){
    display->display();
}

void OLEDisplay::drawPixel(int x, int y, Color color){
    if(x < 0 || y < 0 || x > w || y > h){
        return;
    }

    int _color = 0;
    if(color.r + color.g + color.b == (3*255)){
        _color = 1;
    } else{
        _color = 0;
    }

    display->drawPixel(
        x, y, _color
    );
}

int OLEDisplay::getHeight(){
    return h;
}

int OLEDisplay::getWidth(){
    return w;
}
