#ifndef DISPLAY_H
#define DISPLAY_H
#include <cstdint>


class Display
{
public:
    virtual ~Display() = default;
    virtual void setColor(uint8_t x, uint8_t y, int color) = 0;
    virtual void show() = 0;
    virtual int getHeight() = 0;
    virtual int getWidth() = 0;
};


#endif //DISPLAY_H
