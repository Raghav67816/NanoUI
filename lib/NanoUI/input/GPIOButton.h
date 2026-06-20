#pragma once

#include <functional>

class GPIOButton{
    private:
    
    int pin;
    unsigned long lastChange = 0;
    unsigned long debounceTime = 200;

    unsigned long (*getTime)();

    std::function<void()> _onPress;

    public:
    GPIOButton(int pin, unsigned long (*time)(), 
        signed long debounceTime = 200): 
    pin(pin), debounceTime(debounceTime), getTime(time){}

    bool pressed(int state);
    void setOnPressed(std::function<void()> onPressed);
};
