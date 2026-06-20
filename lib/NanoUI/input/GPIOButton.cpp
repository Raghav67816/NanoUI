#include "GPIOButton.h"

bool GPIOButton::pressed(int state){
    if(state){
        if(getTime() - lastChange > debounceTime){
            lastChange = getTime();
            if(_onPress){
                _onPress();
            }
            return true;
        }
    }
    return false;
}

void GPIOButton::setOnPressed(std::function<void()> onPressed){
    this->_onPress = onPressed;
}
