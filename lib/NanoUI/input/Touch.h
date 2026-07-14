#pragma once

#include <SPI.h>
#include <XPT2046_Touchscreen.h>

#include "core/Event.h"
#include "core/InputDevice.h"
#include "core/Stack.h"

#include "core/types.h"

class Touch: public InputDevice{

    private: 
    XPT2046_Touchscreen *_touchSPI;
    Stack *_app;

    public:
    Touch(XPT2046_Touchscreen *touchSPI, Stack *app): _touchSPI(touchSPI), _app(app){}

    Event<Cordinates> onTouch;

    void processInput() override;
};
