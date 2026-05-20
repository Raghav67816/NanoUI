# Nano UI 

A minimal user-interface framework for micro-controllers and low memory devices.

![alt text](images/banner.jpg)


Documentation [here](https://raghav67816.github.io/NanoUI/)


## Features
 - Wide range of widgets
 - Event System
 - Low memory footprint
 - Supports SPI/TFT Displays


This set of features allows developers to make reactive UI for micro-controllers. 

Bind your widgets to events, trigger then with your physical components.

## Example

![alt text](images/demo.png)

```cpp
#include <string>

#include "Label.h"
#include "ProgressBar.h"
#include "ScrollWidget.h"
#include "platform/sdl/SDLDisplay.h"
#include "platform/sdl/SDLWindow.h"

#include "widgets/Label.h"
#include "core/Graphics.h"
#include "widgets/Screen.h"
#include "core/Stack.h"

#include "layouts/Column.h"

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600


SDLDisplay display(
    128,
    64
);

Color white = {255, 255, 255};
Color black = {0, 0, 0, };

Graphics gfx(&display);

SDLWindow window(&display);

int currentProg = 0;

Stack screenStack(display, gfx);

Column root_layout(0, 0, display.getWidth(), display.getHeight() - 10);

Label prog(20, 10, "0%", white);
ProgressBar progress_bar(100, 10);

Screen screen_a(&display, "Screen A");

void updateProg() {
    currentProg += 1;
    progress_bar.setProgress(currentProg);
    prog.setText("Writing data....");
}

void setup() {
    root_layout.addChild(&prog);
    root_layout.addChild(&progress_bar);

    screen_a.addChild(&root_layout);
    screenStack.addScreen(screen_a);

    display.clear();
    screenStack.goTo(display, screen_a, gfx);
    display.flush();
}

void loop() {
    screenStack.renderApp(gfx);
    updateProg();
    display.flush();
}

int main() {
    window.create();
    window.loop(loop, setup);
}
```

## Installation

1. Install dependencies
```bash
# Ubuntu/Debian
sudo apt install libsdl2-dev

# macOS
brew install sdl2
```

2. Install library
Go to **Releases** install the latest **LIBRARY** file.

3. Include headers

for example

```cpp
#include "NanoUI/core/Display.h"
...
```

## Example
An example is provided with SDL backend, make sure you have SDL2 installed.

Now, go to releases and install [example file](https://github.com/Raghav67816/NanoUI/releases/download/ui/NanoUI_SDL.zip).

in terminal type:
```bash
chmod +x ./executable-name
./executable-name
```
