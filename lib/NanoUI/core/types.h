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
enum InputTypes{
    TOUCH,
    HOVER
};

/*
Define sizes once, use everywhere.
*/
struct SizeMetrics{
    int button_height;
    int title_bar_height;
    int font_size;
};
