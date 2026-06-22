#pragma once

#include <functional>

#include "core/Event.h"

class GPIOButton{
    private:
    
    int pin;
    unsigned long lastChange = 0;
    unsigned long debounceTime = 200;

    unsigned long (*getTime)();

    public:

    Event<> onPress;

    GPIOButton(int pin, unsigned long (*time)(), 
        signed long debounceTime = 200): 
    pin(pin), debounceTime(debounceTime), getTime(time){}

    bool pressed(int state);
};

