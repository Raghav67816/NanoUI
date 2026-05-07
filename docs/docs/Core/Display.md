# Displays

Display is the base class that defines the fundamental class from which other classes like **OLEDisplay** inherits to provide an abstracted way to communicate with the display.

The class has following virtual methods:


# Display::clear()

Clears the framebuffer.

# Display::flush()

Pushes the framebuffer to the display.

# Display::drawPixel()

Params:

 - int x: X Cordinate
 - int y: Y Cordinate
 - Color color: Pixel Color

# Display::getHeight()

Returns: Height of the display (int)

# Display::getWidth()

Returns: Width of the display (int)
