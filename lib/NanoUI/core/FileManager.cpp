#include <stdint.h>
#include <string>
#include "types.h"
#include "FileManager.h"

void FileManager::begin(const String &asset_path)
{
    if (!LittleFS.begin(false))
    {
        Serial.println("Failed to mount LittleFS. File manager will not work");
        return;
    }
    Serial.println("LittleFS mounted");

    this->asset_pack = LittleFS.open(asset_path, "r");
    if (!this->asset_pack || this->asset_pack.isDirectory())
    {
        Serial.println("Asset not found.");
        return;
    }

    this->asset_pack.seek(0);

    size_t bytesRead = this->asset_pack.read(
        (uint8_t *)&this->header, sizeof(AssetHeader));

    if (bytesRead != sizeof(AssetHeader))
    {
        Serial.println("Failed to read asset header");
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        Serial.print(header.magic[i]);
    }

    if (memcmp(header.magic, "NPAK", 4) != 0)
    {
        Serial.println("Id does not match.");
        return;
    }

    Serial.println();
}

uint32_t FileManager::get_filesize(String filename)
{
    if (!this->asset_pack)
    {
        Serial.println("Asset pack not loaded.");
    }

    AssetEntry entry;

    for (int i = 0; i < this->header.count; i += sizeof(AssetEntry))
    {
        size_t bytesRead = this->asset_pack.read(
            (uint8_t *)&entry, sizeof(entry));

        if (bytesRead != sizeof(AssetEntry))
        {
            Serial.println("invalid asset entry");
        }

        if (filename == entry.filename)
        {
            return entry.size;
        }
    }

    return 0;
}

void FileManager::load(char[32] filename, uint32_t filesize)
{
    if (!this->asset_pack)
    {
        Serial.println("Asset pack not loaded.");
        return;
    }

    AssetEntry entry;

    for (int i = 0; i < this->header.count; i += sizeof(AssetEntry))
    {
        size_t bytesRead = this->asset_pack.read(
            (uint8_t *)&entry, sizeof(entry));

        if (bytesRead != sizeof(AssetEntry))
        {
            Serial.println("invalid asset entry");
        }

        if(entry.filename == filename){

        }
    }
}

int FileManager::count()
{
    return header.count;
}
