Widget is the base class from which all widgets like Button, Label, Progress Bar etc...

As of now the framework provides the following widget:

 - Button
 - Label
 - Progress Bar
 - Screen
 - More Coming Soon...

A widget has the following base properties:

 - Position (x, y)
 - Size (h, w)
 - Enabled
 - Visible
 - Parent (nullptr by default)
 - IsDirty (false by default)


# Widget::Widget()
Params:

 - int x, y
 - int w, h
 - Widget* parent;

Constructor

# Widget::draw()
Params:

 - Graphics &gfx

Draws a widget.
Please note that if you are writing your custom widgets keep the geometery logic and drawing logic separate to avoid design conflicts later.

# Widget::bindEvent()
Params:

 - EventType event
 - std::function<void()> callback;


This bind the widget to an event specified by the developer. Use **Widget::onEvent()** to trigger the event.

View widgets for specific use cases.

# Widget::onEvent()

Params:

 - EventType eventType

This triggers the specified event only if the event is bound to a callback using Widget::bindEvent()

View widgets for specific use cases.

# Widget::addChild()
Params:
 - Widget *child;

Adds a child widget to the layout and maintains a consistant hierarchy following parent and child relationship.

Some widget override this method to accommodate custom logic.


# Widget::removeWidget()
Params:
 - Widget *child;

Removes a child widget from the layout and maintains a consistant hierarchy following parent and child relationship.

Some widget override this method to accommodate custom logic.

# Widget::measureGeo()
Params:
 - Graphics &gfx

This method is required by layouts such as Column and Row. The layout calculates position and size of widget relatively.
