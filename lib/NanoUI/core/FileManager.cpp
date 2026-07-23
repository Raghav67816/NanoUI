#include <LittleFS.h>
#include "FileManager.h"

void FileManager::begin()
{
    if (!LittleFS.begin(true))
    {
        Serial.println("Failed to mount file system");
        return;
    }

    Serial.println("LittleFS started successfully");
}

void FileManager::list(uint16_t packet_id)
{
    this->sendPakcet(
        packet_id,
        PacketType::START,
        0,
        nullptr);

    File root = LittleFS.open("/");
    if (!root || !root.isDirectory())
    {
        this->sendPakcet(
            packet_id,
            PacketType::ERROR,
            0,
            nullptr);
        return;
    }

    File file_ = root.openNextFile();
    while(file_){
        FileInfo info;

        strncpy(info.filename, file_.name(), sizeof(info.filename) - 1);
        info.filesize = file_.size();

        sendPakcet(
            packet_id,
            PacketType::FILE_INFO,
            sizeof(info),
            &info
        );

        file_ = file_.openNextFile();
    }

    sendPakcet(
        packet_id,
        PacketType::END,
        0,
        nullptr
    );
}

void FileManager::sendPakcet(
    uint16_t packet_id,
    PacketType packet_type,
    uint16_t length,
    const void* payload
){
    PacketHeader header = {packet_id, packet_type, length};
    Serial.write(
        reinterpret_cast<uint8_t*>(&header),
        sizeof(PacketHeader)
    );

    if(payload != nullptr && length > 0){
        Serial.write(reinterpret_cast<const uint8_t*>(payload),
        sizeof(payload));
    };
}
