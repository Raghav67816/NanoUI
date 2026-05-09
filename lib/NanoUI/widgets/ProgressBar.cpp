#include <Arduino.h>
#include "ProgressBar.h"

void ProgressBar::draw(Graphics &gfx, int offsetX, int offsetY)
{
    int drawX = this->x - offsetX;
    int drawY = this->y - offsetY;

    if (!gfx.boundCheck(drawX, drawX + w, drawY, drawY + h))
        return;

    Color white = {255, 255, 255};

    gfx.drawRect(drawX, drawY, w, h, white);

    if (progress > 0 && progress <= maxValue)
    {
        int clamped_prog = (progress > 100) ? 100 : progress;
        int _prog = (w * progress) / 100;
        if (_prog > 0){
            gfx.fillRect(drawX, drawY, _prog, h, white);
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
    invalidate();
}

void ProgressBar::measureGeo(Graphics &gfx){
    if(this->h < 10){
        this->h = 10;
    }
}

void ProgressBar::bindEvent(EventType event, std::function<void()> callback){
    if(event == PROGRESS_CHANGED){
        onValueChanged = callback;
    }
}

void ProgressBar::onEvent(EventType event) {
    if(event == PROGRESS_CHANGED){
        onValueChanged();
    }
}
