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

    AssetHeader header;
    size_t bytesRead = this->asset_pack.read(
        (uint8_t*)&header, sizeof(AssetHeader)
    );

    if(bytesRead != sizeof(AssetHeader)){
        Serial.println("Failed to read asset header");
        return;
    }

    for(int i=0; i<4; i++){
        Serial.print(header.magic[i]);
    }
    Serial.println();
    Serial.println(header.table_size);
}

void FileManager::read_table(){
    
}
