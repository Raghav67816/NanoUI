#pragma once

#include <vector>
#include <functional>

#include "Graphics.h"

enum EventType
{
    BUTTON_PRESSED,
    PROGRESS_CHANGED
};


/*
base widget from which all widgets inherit
description of properties

bool isDirty;
A widget is marked dirty when it's property changes.
For example, if the text of the label changes, the label is marked as dirty

if a widget is marked dirty it will rendered by the rendering loop

int x, y, w, h;
Basic geometery

bool visible;
not supported currently

bool enabled;
not supported currently

*/

class Widget
{
    public:
    bool isDirty = false;
    int x;
    int y;

    int w;
    int h;

    bool visible;
    bool enabled;

    std::vector<Widget *> children;
    Widget *parent = nullptr;

    /*
    Every widget must define basic geometry.
    leaving them undefined will result in unwanted behaviour.
    */
    Widget(int x = 0, int y = 0, int w = 0, int h = 0)
    {
        this->x = x;
        this->y = y;
        this->w = w;
        this->h = h;
    }

    /*
    void draw()

    Every widget must implement a draw method.
    This method is ONLY respondsible for drawing primitives that 
    together form the desired widget
    */
    virtual void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) = 0;

    /*
    void onEvent()

    This is an optional method, however it is recommended to be implemented 
    in every widget.

    This event fires registered callback. However, if callback is not set 
    the call is ignored.
    */
    virtual void onEvent(EventType event);

    /*
    void bindEvent()
    
    Bind event to specified callback
    */
    virtual void bindEvent(EventType event, std::function<void()> callback);
    
    /*
    Every widget must use the default Widget::addChild method 
    the sole purpose of this function is to add a pointer to the widget 
    into the children vector

    same rule applies for remove child.
    */
    virtual void addChild(Widget *child);
    virtual void removeChild(Widget *child);

    /*

    void measureGeo() calculates the geometry. This function must be implemeted
    by all widgets except layouts.

    This method is called by Layout to calculate position and set minimum
    height and width
    */
    virtual void measureGeo(Graphics &gfx) {};


    void invalidate();

    void debugTree(int depth);
};