#include <LittleFS.h>
#include <vector>

#define ENTRY_SIZE 40

class FileManager{

    private:
    File asset_pack;
    AssetHeader header;
    std::vector<uint32_t> data_pos;

    
    public:
    
    void begin(const String &asset_path);
    void load_asset(String filename);
};
