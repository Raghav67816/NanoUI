#include <Arduino.h>
#include "ProgressBar.h"

void ProgressBar::draw(Graphics &gfx)
{
    if (!gfx.boundCheck(this->x, this->x + w, this->y, this->y + h))
        return;

    Color white = {255, 255, 255};

    gfx.drawRect(x, y, w, h, white);

    if (progress > 0 && progress <= maxValue)
    {
        int clamped_prog = (progress > 100) ? 100 : progress;
        int _prog = (w * progress) / 100;
        if (_prog > 0){
            gfx.fillRect(x, y, (w / 100) * progress, h, white);
        }
    }
}

int ProgressBar::getProgress()
{
    return progress;
}

void ProgressBar::setProgress(int value)
{
    progress = value;
    this->isDirty = true;
    parent->isDirty = true;
}

void ProgressBar::measureGeo(Graphics &gfx) {}
void ProgressBar::addChild(Widget *widget) {}
void ProgressBar::removeChild(Widget *widget) {}
void ProgressBar::onEvent(EventType event) {}
void ProgressBar::bindEvent(EventType event, std::function<void()> callback) {}
