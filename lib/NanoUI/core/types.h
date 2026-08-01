#pragma once

#include <stdint.h>

/*
Cordinates

Contains x and y cordinates of the point touched.
ONLY WORKS WHEN USING TOUCH INPUT
 */
struct Cordinates
{
    int16_t x;
    int16_t y;
};

/*
EXPERIMENTAL
*/
enum InputTypes
{
    TOUCH,
    HOVER
};

/*
Define sizes once, use everywhere.
*/
struct SizeMetrics
{
    int button_height;
    int title_bar_height;
    int font_scale_factor;
};

struct Region
{
    int x;
    int y;
    int w;
    int h;

    bool operator==(const Region &other) const
    {
        return x == other.x &&
               y == other.y &&
               w == other.w &&
               h == other.h;
    }
};

struct Header{
    int x;
};
