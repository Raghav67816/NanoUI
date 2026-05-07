Stack is recommended to be as the root widget in the application UI tree. It allows you to create multiple screen and manage navigation easily.

Stack manages it's own array of child array.

# Stack::Stack()
Params:

 - Display* display;
 - Graphics &gfx;

Creates an instance of a stack that acts as the root widget in the widget tree.

You can also you screen as a root widget, but a screen widget does not support navigation. Even if you are working on a single screen application you should use a stack as root widget.

# Stack::addScreen()
Params:

 - Screen &screen

Inherits from Widget::addChild().
Adds a child screen to the stack.


# Stack::removeScreen()
Params:

 - Screen &screen;

Inherits from Widget::removeScreen().
Remove a child screen from the stack.

# Stack::forward();

Renders the next screen in the stack.

# Stack::back();

Renders previous screen in the stack.

# Stack::goTo()
Params:

 - Display* display;
 - Screen &screen;
 - Graphics &gfx;

Renders the specified screen. Please note that the screen must be added to the stack before calling this method. Also, call this method once in **void setup()** or where your code inits the application.

# Stack::getActiveScreen()

Returns the currently active screen.
Returns: Screen* activeScreen;

# Stack::renderApp()
Params:

 - Graphics &gfx

Renders the application. Must be called in **void loop() ** or must be called in an infinite loop.
