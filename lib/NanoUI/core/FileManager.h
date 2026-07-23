#pragma once

#include <stdint.h>
#include "types.h"

class FileManager{

    private:
    void list(uint16_t packet_id);
    void upload();
    void remove();

    public:
    void begin();
    void sendPakcet(
      uint16_t packet_id,
      PacketType packet_type,
      uint16_t length,
      const void* payload
    );
};
