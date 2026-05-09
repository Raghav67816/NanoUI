#include "core/Widget.h"

class ProgressBar: public Widget{

    private:
    int maxValue = 100;
    int progress = 0;

    std::function<void()> onValueChanged;

    public:

    ProgressBar(int w, int h): Widget(0, 0, w, h){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void measureGeo(Graphics &gfx) override;

    int getProgress();
    void setProgress(int value);
};
