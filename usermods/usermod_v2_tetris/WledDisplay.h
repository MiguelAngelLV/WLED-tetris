
#ifndef WLEDDISPLAY_H
#define WLEDDISPLAY_H

#include <wled.h>
#include "Display.h"


class WledDisplay : public Display {
    CRGB colors[8]{};
public:
    explicit WledDisplay();

    int getHeight() override;
    int getWidth() override;
    void show() override;
    void setColor(uint8_t x, uint8_t y, int color) override;
};



#endif //WLEDDISPLAY_H
