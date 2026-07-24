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

/*
General packet types
*/
enum PacketType
{
    START,
    END,
    ERROR,
    FILE_INFO
};

struct PacketHeader
{
    uint16_t packet_id;
    PacketType packet_type;
    uint16_t length;
};

struct FileInfo
{
    char filename[32];
    size_t filesize;
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
