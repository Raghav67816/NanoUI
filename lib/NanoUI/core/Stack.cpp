#include "Stack.h"
#include <Arduino.h>

void Stack::addScreen(Screen &screen){
    screens.push_back(&screen);
};

void Stack::removeScreen(Screen &screen){
    for(int i=0; i<screens.size(); i++){
        if(screens[i] == &screen){
            screens[i] = screens.back();
            screens.pop_back();
            return;
        }
    }
}

void Stack::goTo(Display &display, Screen &screen, Graphics &gfx){
    for(int i=0; i<screens.size(); i++){
        if(screens[i] == &screen){
            screenIndex = i;
            activeScreen = &screen;
            onCurrentScreenChanged(display, gfx);
            return;
        }
    }
}

void Stack::forward(){
    if(screenIndex + 1 > screens.size()){
        return;
    }

    screenIndex += 1;

    Screen* _screen = screens.at(screenIndex);
    goTo(display, *_screen, gfx);
}

void Stack::back(){
    if(screenIndex - 1 < 0){
        return;
    }

    screenIndex -= 1;
    Screen* _screen = screens.at(screenIndex);
    goTo(display, *_screen, gfx);
}

void Stack::onCurrentScreenChanged(Display &display, Graphics &gfx){
    Color black = {0, 0, 0};

    activeScreen->measureGeo(gfx);
    activeScreen->setTitle(&gfx, activeScreen->title, black);
    activeScreen->draw(gfx);

}

Screen* Stack::getActiveScreen(){
    return activeScreen;
}

void Stack::renderApp(Graphics &gfx){
    activeScreen->regionCheck();
    if(activeScreen->requireUpdate()){
        Serial.println("window is dirty");
        display.clear();
        activeScreen->draw(gfx);
        display.flush();
    }
}
