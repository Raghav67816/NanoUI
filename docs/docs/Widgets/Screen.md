Screen inherits from widget and is a container to hold layouts and widget. You can use a screen without layouts, but it is recommended to use layouts.

# Screen::Screen()
Params:

 - Display* display
 - Graphics &gfx

Creates a display with specified title.

# Screen::setTitle()
Params:

 - char* title

Sets window title to specified text

# Screen::addChild()
Params:

 - Widget *child

Adds a child widget to screen. This method only changes the ownership of the child.

# Screen::removeChild()
Params:

 - Widget *child

Removes a child widget from screen. This method only changes the ownership of the child.
