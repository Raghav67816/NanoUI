#include "GPIOButton.h"

bool GPIOButton::pressed(int state){
    if(state){
        if(getTime() - lastChange > debounceTime){
            lastChange = getTime();
            onPress.broadcast();
            return true;
        }
    }
    return false;
}
