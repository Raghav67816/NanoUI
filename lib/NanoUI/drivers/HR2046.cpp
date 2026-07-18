#include "HR2046.h"


void HR2046::begin()
{
    pinMode(_clk, OUTPUT);
    pinMode(_mosi, OUTPUT);
    pinMode(_miso, INPUT);
    pinMode(_cs, OUTPUT);

    digitalWrite(_clk, LOW);
    digitalWrite(_mosi, LOW);
    digitalWrite(_cs, HIGH);
}

uint16_t HR2046::transfer16(uint8_t cmd)
{
    uint16_t data = 0;

    digitalWrite(_cs, LOW);

    for (int i = 7; i >= 0; i--)
    {
        digitalWrite(_mosi, (cmd >> i) & 1);

        digitalWrite(_clk, HIGH);
        digitalWrite(_clk, LOW);
    }

    for (int i = 0; i < 16; i++)
    {
        digitalWrite(_clk, HIGH);

        data <<= 1;
        if (digitalRead(_miso))
            data |= 1;

        digitalWrite(_clk, LOW);
    }

    digitalWrite(_cs, HIGH);

    Serial.printf("Raw = 0x%04X\n", data);

    return (data >> 3) & 0x0FFF;
}

uint16_t HR2046::readX()
{
    return transfer16(0xD0);
}

uint16_t HR2046::readY()
{
    return transfer16(0x90);
}

bool HR2046::touched()
{
    uint16_t x = readX();
    uint16_t y = readY();

    return (x > 50 && y > 50);
}

Cordinates HR2046::readCordinates()
{
    return { readX(), readY() };
}