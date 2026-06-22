#include "ListItem.h"

void ListItem::draw(Graphics &gfx, int offsetX, int offsetY)
{
    if (this->isFocused)
    {
        int drawX = this->x - INNER_PADDING;
        int drawY = this->y - INNER_PADDING - offsetY;

        setColor(black);
        
        gfx.fillRect(
            drawX,
            drawY,
            this->w + INNER_PADDING,
            this->h + INNER_PADDING,
            white
        );
    }
    Label::draw(gfx, 0, offsetY);
}

void ListItem::setFocused(bool isFocused)
{
    this->isFocused = isFocused;
}
