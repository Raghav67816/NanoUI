Graphics is the base class that provides methods to draw basic shapes and text. This is an important part of the framework because it is respondsible for drawing pixels.

# Graphics::Graphics()
Params:
 - Display*

Constructor

# Graphics::boundCheck()
Params:
 - int x1
 - int x2
 - int y1
 - int y2

Checks if the specified vertices together as shape exist within the limits of display geometery.

Returns: bool

# Graphics::drawLine()
Params:
 - int x1
 - int x2
 - int y1
 - int y2
 - Color color

Draws a line using [Bresenham's Line Algorithm](https://en.wikipedia.org/wiki/Bresenham%27s_line_algorithm).

# Graphics::drawRect()
Params:
 - int x
 - int y
 - int w
 - int h
 - Color color

Draws a rectangle using the specified geometery.

# Graphics::fillRect()
Params:
 - int x
 - int y
 - int w
 - int h
 - Color color

Draws and fills a rectangle using the specified geometery.

# Fonts
The framework uses the **5x7** bitmap font provided by **Adafruit GFX** library.

# Graphics::drawText()
Params:
 - int x
 - int y
 - const char* title
 - Color color

Draws text on the screen.

# Graphics::getTextWidth()
Params:
const char* text

Determines the length of text.

Returns: Lenght of text (int)
