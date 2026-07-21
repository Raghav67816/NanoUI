#pragma once

#include <stdint.h>
#include <string>

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
    int font_scale_factor;
};


struct FileInfo{
    String filename;
    size_t file_size;
};

struct PacketHeader{
    uint16_t packetId;
    uint8_t type;
    uint16_t length;
};

enum FileM_PacketType: uint8_t{
    LIST_START,
    LIST_END,
    FILE_INFO,
    UPLOAD_FILE,
    DELETE_FILE,
    FORMAT_FLASH,
    ERROR
};
