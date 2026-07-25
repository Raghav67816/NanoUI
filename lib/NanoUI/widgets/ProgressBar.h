#include "core/Widget.h"
#include "core/Event.h"

class ProgressBar: public Widget{

    private:
    int maxValue = 100;
    int progress = 0;

    Event<int> onValueChanged;

    public:

    ProgressBar(int w, int h): Widget(0, 0, w, h){}

    void draw(Graphics &gfx, Theme& theme, int offsetX = 0, int offsetY = 0) override;
    void processInput(InputTypes inputType, Cordinates point) override;
    void measureGeo(Graphics &gfx) override;

    int getProgress();
    void setProgress(int value);
};
