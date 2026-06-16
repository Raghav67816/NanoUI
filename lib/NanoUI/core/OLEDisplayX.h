#include <Adafruit_SH110X.h>

#include "Color.h"
#include "Display.h"

class OLEDisplayX: public Display{

    private:
    const int w;
    const int h;

    Adafruit_SH110X *display;

    public:
    OLEDisplayX(int w, int h, Adafruit_SH110X *oled): w(w), h(h), display(oled){}

    void clear() override;
    void flush() override;

    void drawPixel(int x, int y, Color color) override;

    int getHeight() override;
    int getWidth() override;
};
