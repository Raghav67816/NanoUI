#include "Touch.h"
#include "core/Widget.h"
#include "widgets/Screen.h"

#include <vector>

void Touch::processInput(){
    Screen* activeScreen = this->_app->getActiveScreen();
    for(Widget* child: activeScreen->children){
        TS_Point point = _touchSPI->getPoint();
        Cordinates cords = {point.x, point.y};
        child->processInput(TOUCH, cords);
    }
}
