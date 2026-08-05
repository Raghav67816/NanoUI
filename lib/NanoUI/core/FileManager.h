#include <LittleFS.h>


class FileManager{

    private:
    File asset_pack;

    void read_table();

    public:

    void begin(const String &asset_path);
};
