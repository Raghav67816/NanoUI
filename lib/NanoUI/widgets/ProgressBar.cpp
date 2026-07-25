#include "Screen.h"
#include "ProgressBar.h"

void ProgressBar::draw(Graphics &gfx, Theme* theme, int offsetX, int offsetY)
{
    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    if (!gfx.boundCheck(drawX, drawX + w, drawY, drawY + h)) return;

    Color white = {255, 255, 255};

    if(this->parent != nullptr){
        this->bgColor = this->parent->bgColor;
    }

    gfx.drawRect(drawX, drawY, w, h, theme->accent);

    if (progress > 0 && progress <= maxValue)
    {
        int clamped_prog = (progress > 100) ? 100 : progress;
        int _prog = (w * progress) / 100;
        if (_prog > 0){
            gfx.fillRect(drawX, drawY, _prog, h, theme->foreground);
        }
    }

    if(progress > maxValue){
        gfx.fillRect(drawX, drawY, this->w, this->h, white);
    }
}

int ProgressBar::getProgress()
{
    return progress;
}

void ProgressBar::setProgress(int value)
{
    progress = value;
    Widget* tParent = this->getTopLevelParent();
    Screen* tScreen = static_cast<Screen*>(tParent);
    this->invalidate(tScreen, this);
}

void ProgressBar::measureGeo(Graphics &gfx){
    if(this->h < 10){
        this->h = 10;
    }
}

void ProgressBar::processInput(InputTypes inputType, Cordinates point){}
