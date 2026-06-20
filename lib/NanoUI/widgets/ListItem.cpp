#include "ListItem.h"

void ListItem::draw(Graphics &gfx, int offsetX, int offsetY)
{
    if (this->isFocused)
    {
        setColor(black);
        gfx.fillRect(this->x -2, this->y - 2, this->w + 2, this->h + 2, white);
    }
    Label::draw(gfx);
}

void ListItem::setFocused(bool isFocused)
{
    this->isFocused = isFocused;
}
