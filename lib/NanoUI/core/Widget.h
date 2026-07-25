#pragma once

#include <vector>
#include <functional>

#include "Theme.h"
#include "Graphics.h"

#include "core/types.h"

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

class Screen;

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
    std::vector<Region> regions;
    Widget *parent = nullptr;

    Color bgColor;

    SizeMetrics *size_metrics;

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
    virtual void draw(Graphics &gfx, Theme* theme, int offsetX = 0, int offsetY = 0) = 0;
    
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

    /*
    EXPERIMENTAL

    void processInput

    To support touch input and mouse input, every widget must implement a processInput
    method. When the user touches the screen, or uses joystick with a push button to emulate a mouse click
    the cordinates are propogated down the widget tree, widgets check if the cordinates are in bounds
    if in bounds widget broadcasts events such as pressed/clicked/focused

    */

    virtual void processInput(InputTypes inputType, Cordinates points) = 0;

    /*
    void setSizeMetrics

    This method sets size metric for the widget
    */
    virtual void setSizeMetrics(SizeMetrics *size_metrics);

    /*
    Region getBounds()

    returns a Region(int x, int y, int w, int h)

    see Region in types.h
    */
    Region getBounds();

    /*
    Screen* getTopLevelParent()

    returns the top level parent i.e the screen.
    */
   Widget* getTopLevelParent();

   /*
   void invalidate

   marks the region as damaged and adds to redraw queue.
   */
   void invalidate(Screen* screen, Widget* widget);

   void clear(Graphics &gfx, Color color);
};