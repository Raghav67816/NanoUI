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
        printf("pixel out of index (%d, %d) \n", x, y);
        return;
    }

    int index = (y*w + x) * 3;

    frameBuffer[index] = color.r;
    frameBuffer[index + 1] = color.g;
    frameBuffer[index + 2] = color.b;
}

void SDLDisplay::clear() {
    for (int i=0; i<w*h; i++) {
        frameBuffer[i] = 0;
    }
}

std::vector<uint8_t>& SDLDisplay::getFrameBuffer() {
    return frameBuffer;
}

void SDLDisplay::flush() {
    // stays empty,
    // framebuffer updates every frame automatically
}

int SDLDisplay::getHeight() {
    return h;
}

int SDLDisplay::getWidth() {
    return w;
}
