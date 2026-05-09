#include "../core/Widget.h"
#include "../core/Graphics.h"
#include "../core/Display.h"


class Label: public Widget{
    private:

    public:
    char* labelText;
    Color color;


    Label(int w, int h, char* text, Color color): Widget(0, 0, w, h), labelText(text), color(color){}

    void draw(Graphics &gfx, int offsetX = 0, int offsetY = 0) override;
    void measureGeo(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;

    void setText(char* text);
    void setColor(Color color);

    char* text();
};