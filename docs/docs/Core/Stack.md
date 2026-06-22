Stack is recommended to be as the root widget in the application UI tree. It allows you to create multiple screen and manage navigation easily.

# Stack::Stack()

Params:

 - Display display
 - Graphics gfx

Constructs a Stack with **no** screens.

# Stack::addScreen()

Params:

 - Screen screen

Adds a screen to the stack. Duplicates are ignored. 
Screens that are not added to stack using this method are ignored and can't be rendered.

# Stack::removeScreen()

Params:

 - Screen screen

Remove a screen from the stack, if it exists.

# Stack::forward()

Renders the next screen. This call is ignored if the last screen was being displayed.

# Stack::back()

Renders the previous screen. This call is ignored if the 1st screen was being displayed.

# Stack::goTo()

Params:

 - Display display
 - Screen screen
 - Graphics gfx

Renders the specified screen if it exists in the stack.

# Stack::getActiveScreen()

Returns:

 - Screen* activeScreen

Returns a pointer to the active screen.

# Stack::renderApp()

Params:

 - Graphics gfx

This function is the most important function. This draws your app, if this function is not called in **void loop()** your application will not be rendered. This function call must be followed by **display.flush()**
