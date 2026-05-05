#include <Adafruit_SSD1306.h>

#include "core/Color.h"
#include "core/Display.h"

class OLEDisplay: public Display{

    private:
    const int w;
    const int h;

    Adafruit_SSD1306 *display;

    public:
    OLEDisplay(int w, int h, Adafruit_SSD1306 *oled): w(w), h(h), display(oled){}

    void clear() override;
    void flush() override;

    void drawPixel(int x, int y, Color color) override;

    int getHeight() override;
    int getWidth() override;
};
