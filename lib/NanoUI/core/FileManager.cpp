#include "core/types.h"
#include "FileManager.h"

#include <LittleFS.h>

bool FileManager::begin(const char* image_name){
    bool isMounted = LittleFS.begin(true);
    if(!isMounted){
        Serial.println("Failed to mount littlefs.");
    }

    char path[64];
    snprintf(path, sizeof(image_name), "/%s", image_name);

    File file = LittleFS.open(path);
    if(file && file.available()){
        Serial.println("File found");
    }

    return isMounted;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}
