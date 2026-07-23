#include "App.h"

void App::addScreen(Screen &screen){
    screen.setTheme(this->_theme);
    screen.setSizeMetrics(this->size_metrics);
    screens.push_back(&screen);
};

void App::removeScreen(Screen &screen){
    for(int i=0; i<screens.size(); i++){
        if(screens[i] == &screen){
            screens[i] = screens.back();
            screens.pop_back();
            return;
        }
    }
}

void App::goTo(Display &display, Screen &screen, Graphics &gfx){
    for(int i=0; i<screens.size(); i++){
        if(screens[i] == &screen){
            screenIndex = i;
            activeScreen = &screen;
            onCurrentScreenChanged(display, gfx);
            return;
        }
    }
}

void App::forward(){
    if(screenIndex + 1 > screens.size()){
        return;
    }

    screenIndex += 1;

    Screen* _screen = screens.at(screenIndex);
    goTo(display, *_screen, gfx);
}

void App::back(){
    if(screenIndex - 1 < 0){
        return;
    }

    screenIndex -= 1;
    Screen* _screen = screens.at(screenIndex);
    goTo(display, *_screen, gfx);
}

void App::onCurrentScreenChanged(Display &display, Graphics &gfx){
    Color black = {0, 0, 0};

    activeScreen->measureGeo(gfx);
    activeScreen->setTitle(&gfx, activeScreen->title, black);
    display.clear();
    activeScreen->draw(gfx, this->_theme);

}

Screen* App::getActiveScreen(){
    return activeScreen;
}

void App::renderApp(Graphics &gfx){

    if (activeScreen == nullptr) {
        this->screenIndex = 0;
        this->activeScreen = screens.at(this->screenIndex);
    }

    if(activeScreen->_dirtyCheck()){
        display.clear();
        activeScreen->draw(gfx, this->_theme);
        activeScreen->clearDirty();
        display.flush();   
    }
}

void App::setTheme(Theme* theme){
    this->_theme = theme;
}

void App::setSizes(SizeMetrics *size_metrics){
    this->size_metrics = size_metrics;
}
