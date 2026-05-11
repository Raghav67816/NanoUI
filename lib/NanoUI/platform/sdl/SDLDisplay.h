//
// Created by cooper on 5/10/26.
//

#ifndef NANOUI_SDLDISPLAY_H
#define NANOUI_SDLDISPLAY_H

#include <cstdio>
#include <functional>

#include "core/Display.h"
#include "core/Color.h"

#include <vector>

/*
 * SDLDisplay.h
 *
 * Inherits from Display.h
 * Allows better debugging
 * Implements its own methods to mimic display
 * */
class SDLDisplay: public Display {
private:
    std::vector<uint8_t> frameBuffer;
    int w;
    int h;

    std::function<void(SDLDisplay&)> flushCallback;

public:
    SDLDisplay(int width, int height): w(width), h(height) {
        frameBuffer.resize(w*h * 3);
        printf("frame buffer resized to %dx%d", w, h);
    }

    int getHeight() override;
    int getWidth() override;

    void drawPixel(int x, int y, Color color) override;

    void flush() override;
    void clear() override;

    void onFlush(std::function<void(SDLDisplay&)> callback);
    std::vector<uint8_t>& getFrameBuffer();
};



#endif //NANOUI_SDLDISPLAY_H
