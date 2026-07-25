#include "Screen.h"

#include "widgets/Button.h"

void Screen::draw(Graphics &gfx, Theme *theme, int offsetX, int offsetY)
{

    this->bgColor = this->theme->background;

    gfx.fillRect(
        0, 0,
        this->display->getWidth(),
        this->display->getHeight(),
        this->theme->background);

    gfx.drawRect(
        0, 0,
        display->getWidth(),
        display->getHeight(),
        this->theme->background);

    setTitle(&gfx, this->title, this->theme->selectionText);

    for (Widget *widget : children)
    {
        widget->draw(gfx, theme);
    }
}

bool Screen::_dirtyCheck()
{
    for (Widget *child : children)
    {
        if (child->isDirty)
        {
            return true;
        }
    }

    return false;
}

void Screen::clearDirty()
{
    for (Widget *child : children)
    {
        child->isDirty = false;
    }
}

void Screen::setTitle(Graphics *gfx, const char *title, Color titleColor)
{
    gfx->fillRect(
        0, 0,
        display->getWidth(),
        this->size_metrics->title_bar_height,
        this->theme->primary);

    gfx->drawText(
        (display->getWidth() - gfx->getTextWidth(title)) / 2,
        (this->size_metrics->title_bar_height - 7) / 2,
        title,
        titleColor);
}

void Screen::setTheme(Theme *theme)
{
    this->theme = theme;
}

void Screen::addDamagedWidget(Widget* widget)
{
    damagedWidgets.push_back(widget);
}

void Screen::removeDamagedWidget(Widget* widget){
    for(size_t i = 0; i < damagedWidgets.size(); i++)
    {
        if(damagedWidgets[i] == widget)
        {
            damagedWidgets[i] = damagedWidgets.back();
            damagedWidgets.pop_back();
            return;
        }
    }
}

bool Screen::hasDamagedWidgets(){
    bool dw = false;
    if(this->damagedWidgets.size() > 0){
        dw = true;
    }
    return dw;
}

void Screen::processInput(InputTypes inputType, Cordinates points) {}
