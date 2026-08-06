#include <LittleFS.h>

#define ENTRY_SIZE 40

class FileManager{

    private:
    File asset_pack;
    AssetHeader header;

    public:

    void begin(const String &asset_path);
    void load_asset(String filename);
};
