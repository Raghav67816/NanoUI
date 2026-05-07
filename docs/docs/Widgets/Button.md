Inherits From: Widget.h

For non-touch displays you can bind the button to a physical button in your circuit and the user-interface will react to button states.

Also, as of now the framework does not support touch displays. However, it's on the development roadmap and will be available soon.

# Button::Button()
Params:

 - int w, int h
 - char* labelText
 - Color bgColor
 - Color textColor

Creates an instance of button with specified height and width. Size and position might be modified if you are using layouts.

```cpp
Button btn(40, 20, "Click Me");
```

# Button::setText()
Params:

 - char* labelText

Sets button text to text provided.

```cpp
Button btn(40, 20, "Click Me");
btn.setText("Changed");
```

# Button::bindEvent()
Params:

 - EventType event
 - std::function<void()> callback

Binds an event to the provided callback.
As of now, there is only 1 event enum defined for the button i.e **BUTTON_PRESSED**.

```

void onButtonPressed(){
    Serial.println("Button Clicked");
}

Button btn(40, 20, "Click Me");
btn.setText("Changed");

btn.bindEvent(BUTTON_PRESSED, onButtonPressed);
```


# Button::onEvent()
Params:

 - EvenType event

Triggers the registered callback for the specified function. However, if you haven't already bound the event to a function this will be ignored.
