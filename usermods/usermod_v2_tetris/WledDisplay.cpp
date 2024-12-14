#include "WledDisplay.h"


WledDisplay::WledDisplay() {
    colors[0] = CRGB(0, 0, 0);
    colors[1] = CRGB(136, 87, 10);
    colors[2] = CRGB(60, 60, 252);
    colors[3] = CRGB(242, 160, 27);
    colors[4] = CRGB(239, 242, 45);
    colors[5] = CRGB(0, 242, 44);
    colors[6] = CRGB(164, 0, 237);
    colors[7] = CRGB(244, 0, 2);
}

int WledDisplay::getHeight() {
    return SEGMENT.virtualHeight();
}

int WledDisplay::getWidth() {
    return SEGMENT.virtualWidth();
}

void WledDisplay::setColor(uint8_t x, uint8_t y, int color) {
    SEGENV.setPixelColorXY(x, y, colors[color]);
}
void WledDisplay::show() {

}


