#include "Graphics.h"
#include "Display.h"

#include <math.h>


bool Graphics::boundCheck(int x1, int x2, int y1, int y2){

    int w = display->getWidth();
    int h = display->getHeight();

    if(
        x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0 || x1 > w || x2 > w || y1 > h || y2 > h 
    ){
        return false;
    }
    return true;
}

void Graphics::drawLine(int x1, int y1, int x2, int y2){
    if(!boundCheck(x1, x2, y1, y2)){
        return;
    }

    int dx = abs(x2-x1);
    int dy = abs(y2-y1);

    int sx = (x1 < x2) ? 1: -1;
    int sy = (y1 < y2) ? 1: -1;

    int error = dx-dy;

    while(true){
        display->drawPixel(x1, y1, true);

        if(x1 == x2 && y1 == y2){break;}

        int e_itr = 2*error;

        if (e_itr > -dy){
            error -= dy;
            x1 += sx;
        }

        if(e_itr < dx){
            error += dx;
            y1 += sy;
        }
    }
}
