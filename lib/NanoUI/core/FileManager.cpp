#include <stdint.h>

#include "types.h"
#include "FileManager.h"


void FileManager::begin(const String &asset_path){
    if(!LittleFS.begin(true)){
        Serial.println("Failed to mount LittleFS. File manager will not work");
        return;
    }
    Serial.println("LittleFS mounted");

    this->asset_pack = LittleFS.open(asset_path, "r");
    if(!this->asset_pack || this->asset_pack.isDirectory()){
        Serial.println("Asset not found.");
        return;
    }

    this->asset_pack.seek(0);

    size_t bytesRead = this->asset_pack.read(
        (uint8_t*)&this->header, sizeof(AssetHeader)
    );

    if(bytesRead != sizeof(AssetHeader)){
        Serial.println("Failed to read asset header");
        return;
    }

    for(int i=0; i<4; i++){
        Serial.print(header.magic[i]);
    }

    if(memcmp(header.magic, "NPAK", 4) != 0){
        Serial.println("Id does not match.");
        return;
    }

    Serial.println();
}

void FileManager::load_asset(String filename){
    if(!this->asset_pack){
        Serial.println("Asset pack not loaded.");
        return;
    }

    for(int i=0; i<(int)this->header.count; i++){
        AssetEntry entry;
        this->asset_pack.seek(sizeof(this->header) + (sizeof(AssetEntry) * i));
        uint8_t bytesRead = this->asset_pack.read(
            (uint8_t*)&entry, sizeof(AssetEntry)
        );

        if(bytesRead != sizeof(AssetEntry)){
            Serial.println("Invalid size, cannot read asset table.");
        }

        this->asset_pack.seek(entry.offset);

        FontHeader fHeader;
        uint8_t fBytesRead = this->asset_pack.read(
            (uint8_t*)&fHeader, sizeof(FontHeader)
        );

        if(fBytesRead != sizeof(FontHeader)){
            Serial.println("Invalid asset header size, cannot load asset");
            return;
        }

        Serial.println(fHeader.version);
    }
}
