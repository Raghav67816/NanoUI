Label is nothing fancy but **Graphics::drawText()** wrapped in widget that allows it to follow geometry and lets you update text.

Graphics::drawText() is similar but **Label** is recommended.

# Label::Label()

Params:

 - int w
 - int h
 - char* labelText

Creates an instance of label with specified labelText. If you are using layouts geometry might get modified relatives to the layout.

```cpp

Label label(40, 20, "Label 1");
```

# Label::setText()
Params:

 - char* labelText

Sets label text to specified char.

```cpp

Label label(40, 20, "Label 1");

label.setText("New Label");
```

# Label::setColor()
Params:
 - Color color;


If color other than black and white are passed, they will ignored for monochrome displays.
