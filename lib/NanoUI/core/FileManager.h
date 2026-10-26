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
    void load(const char* filename, uint32_t filesize);
    
    uint32_t get_filesize(String filename);

    int count();
};
