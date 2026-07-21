#include "FileManager.h"
#include "types.h"

void FileManager::begin()
{
    if (!LittleFS.begin(true))
    {
        Serial.println("Failed to attach file manager.");
        return;
    }

    Serial.println("File manager attached.");
}

void FileManager::list(uint16_t packetId)
{
    send_packet(
        packetId,
        FileM_PacketType::LIST_START,
        0,
        nullptr
    );

    File root = LittleFS.open("/");

    if (!root || !root.isDirectory())
    {
        send_packet(
            packetId,
            FileM_PacketType::ERROR,
            0,
            nullptr
        );

        return;
    }

    File file = root.openNextFile();

    while (file)
    {
        FileInfo info;

        info.filename = file.name();
        info.file_size = file.size();

        send_packet(
            packetId,
            FileM_PacketType::FILE_INFO,
            sizeof(info),
            &info
        );

        file = root.openNextFile();
    }

    send_packet(
        packetId,
        FileM_PacketType::LIST_END,
        0,
        nullptr
    );
}

void FileManager::send_packet(
    uint16_t packetId,
    uint8_t FileM_PacketType,
    uint16_t payloadLength,
    const void* payload
)
{
    PacketHeader header;

    header.packetId = packetId;
    header.type = FileM_PacketType;
    header.length = payloadLength;

    Serial.write(
        reinterpret_cast<uint8_t*>(&header),
        sizeof(PacketHeader)
    );

    if (payload != nullptr && payloadLength > 0)
    {
        Serial.write(
            reinterpret_cast<const uint8_t*>(payload),
            payloadLength
        );
    }
}