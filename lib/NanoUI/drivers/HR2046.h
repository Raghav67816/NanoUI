#pragma once

#include <Arduino.h>
#include "core/types.h"

class HR2046
{
private:
    uint8_t _clk;
    uint8_t _miso;
    uint8_t _mosi;
    uint8_t _cs;

    uint16_t transfer16(uint8_t cmd);

public:
    HR2046(
        uint8_t clk,
        uint8_t mosi,
        uint8_t miso,
        uint8_t cs) : _clk(clk), _miso(miso), _mosi(mosi), _cs(cs) {}

    void begin();
    
    uint16_t readX();
    uint16_t readY();
    bool touched();

    Cordinates readCordinates();
};
