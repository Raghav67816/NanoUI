//
// Created by cooper on 5/10/26.
//

#include "SDLDisplay.h"

#include <utility>

/*
 * drawPixel
 *
 * the color might be visible in simulated display however this will be
 * ignored in monochrome displays
 */
void SDLDisplay::drawPixel(int x, int y, Color color) {
    if (x < 0 || x >= w || y < 0 || y >= h) {
        printf("pixel out of index");
        return;
    }
    frameBuffer[y*w + x] = color;
}

void SDLDisplay::clear() {
    Color blackPixel = {0, 0, 0};
    for (int i=0; i<w*h; i++) {
        frameBuffer[i] = blackPixel;
    }
    printf("framebuffer cleared");
}

std::vector<Color> SDLDisplay::getFrameBuffer() {
    return frameBuffer;
}

void SDLDisplay::onFlush(std::function<void(SDLDisplay&)> callback) {
    flushCallback = callback;
}

void SDLDisplay::flush() {
    flushCallback(*this);
}

int SDLDisplay::getHeight() {
    return h;
}

int SDLDisplay::getWidth() {
    return w;
}
