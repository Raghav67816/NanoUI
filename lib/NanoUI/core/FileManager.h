#include <LittleFS.h>
#include <etl/vector.h>

#define HEADER_SIZE 20
#define ENTRY_SIZE 40

class FileManager{

    private:
    File asset_pack;
    AssetHeader header;
    etl::vector<uint32_t, 5> data_pos;

    
    public:
    
    void begin(const String &asset_path);
    void load_asset(String filename);
};
