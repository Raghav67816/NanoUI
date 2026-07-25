#include "ListItem.h"

void ListItem::draw(Graphics &gfx, Theme& theme, int offsetX, int offsetY)
{
    if (this->isFocused)
    {
        int drawX = this->x - INNER_PADDING;
        int drawY = this->y - INNER_PADDING - offsetY;

        setColor(theme.selectionText);
        
        gfx.fillRect(
            drawX,
            drawY,
            this->w + INNER_PADDING,
            this->h + INNER_PADDING,
            theme.selection
        );
    }
    Label::draw(gfx, theme, 0, offsetY);
}

void ListItem::setFocused(bool isFocused)
{
    this->isFocused = isFocused;
}

void ListItem::processInput(InputTypes inputType, Cordinates point){
    if(this->x + this->w <= point.x && this->y + this->h <= point.y){
        if(inputType == TOUCH){
            this->onSelect.broadcast(this->_text);
        }
    }
}
