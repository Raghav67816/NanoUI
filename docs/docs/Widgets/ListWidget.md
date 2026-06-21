ListWidget allows you to stack multiple ListItems vertically. It is ideal for making application menu or settings pages.

# ListWidget::ListWidget()

Params:

 - int x
 - int y 
 - int w
 - int h

ListWidget inherits from **Column** which requires cordinates and geometry as arguments. It is recommended to put your ListWidget under a layout.

For example:

```cpp

#include "NanoUI/layouts/Column.h"
#include "NanoUI/widgets/ListItem.h"
#include "NanoUI/widgets/ListWidget.h"


// assumming you have a Screen menu_screen

Column root_layout(0, 10, DISPLAY_WIDTH, DISPLAY_HEIGHT - 10);
ListWidget list_widget(0, 10, DISPLAY_WIDTH, DISPLAY_HEIGHT - 10);

ListItem item_a("Item A");
ListItem item_b("Item B");
ListItem item_c("Item C");

list_widget.addChild(item_a);
list_widget.addChild(item_b);
list_widget.addChild(item_c);

```

You **MUST** pass ListItem instead of any other widget. Otherwise, you will notice unexpected behaviour.

# ListWidget::getFocusedItem()

Returns:

 - ListItem* focusedItem;

Returns a pointer to the focused item.

# ListWidget::getFocusedItemIndex()

Returns:

 - int focusedItemIndex;

Returns the index of the current focused item.

# ListWidget::focusItem()

Params:

 - int index

Focuses the item corresponding to the provided index.


# Events
 - CURRENT_ITEM_CHANGED

    This is triggered when the current item is changed. The callback function must accept a **ListItem*** as an argument.

Bind to this event by:

```
void onItemChanged(ListItem* item){
    // your logic when progress updates
};

list_widget.bindEvent(CURRENT_ITEM_CHANGED, onItemChanged);
```
