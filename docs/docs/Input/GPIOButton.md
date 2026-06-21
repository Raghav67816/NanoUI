Unlike **Button** which is a UI component. GPIOButton adds debounce to physical push buttons. This also has similar function calls and a callback can be added to this button.

# GPIOButton::GPIOButton()

Params:

 - int pin
 - unsigned long (*time_provider)()
 - signed long debounceTime

Creates an instance of GPIOButton. Please **note** that you **MUST** provide **time_provider** argument as **millis()** function. The default debounce threshold time is **200 ms**

Also, you **MUST** init pins in the **void setup()** method.

Please see the example below.

```cpp
#include <Arduino.h>
#include "NanoUI/inputs/GPIOButton.h"

#define BTN_OK 8

GPIOButton(BTN_OK, millis);

....
void setup(){
    ...
    pinMode(BTN_OK, INPUT); // can be INPUT_PULLUP, or INPUT_PULLDOWN depending on the use case.
}
```

# GPIOButton::pressed()

Params:

 - int state;

Returns:

 - bool isPressed;

The framework aims to be independent of hardware, that is why we ask you to provide the digital pin state to the function.

If the button was pressed **true** will be returned.

Below is an example:

```cpp

// Your code here

void loop(){
    int ok_btn_state = digitalRead(BTN_OK);
    if(btn.pressed(ok_btn_state)){
        // your logic
    }
}

```
