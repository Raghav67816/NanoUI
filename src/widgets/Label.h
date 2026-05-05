#include "Color.h"
#include "Widget.h"


class Label: public Widget{
    private:

    public:
    char* labelText;
    int x, y;
    Color color;


    Label(int x, int y, char* text, Color color): x(x), y(y), labelText(text), color(color){
        this->x = x;
        this->y = y;
    }

    void draw(Graphics &gfx) override;
    void onEvent(EventType event) override;
    void bindEvent(EventType event, std::function<void()> callback) override;
    void addChild(Widget *widget) override;

    void setText(char* text);
    void setColor(Color color);

    char* text();
};
