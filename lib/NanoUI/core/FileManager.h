#pragma once

#include <LittleFS.h>

class FileManager{

    private:

    void list(uint16_t packetId);
    void upload();
    void remove();
    void format();

    void send_packet(uint16_t packet_id = 0x4E55, uint8_t packet_type, uint16_t length, const void* payload);

    public:

    FileManager(){}

    void begin();
};
