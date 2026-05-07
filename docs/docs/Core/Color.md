# Color

The framework supports both monochrome and colored displays. To support both types of display the framework provides a common absrtaction to define colors that works across displays.

```cpp
struct Color{
    uint8_t r;
    uint8_t g;
    uint8_t b;
};
```

To define a color:
```
// Black
Color black = {0, 0, 0};

// White
Color white = {255, 255, 255};

// and so on 
```

However, monochrome displays only support black and white color only. If you try to pass **red** color it will be ignored and passed as black.

# For Monochrome Displays
If **RED+GREEN+BLUE** < 255: Color is Black
If **RED+GREEN+BLUE** >= 255: Color is White
