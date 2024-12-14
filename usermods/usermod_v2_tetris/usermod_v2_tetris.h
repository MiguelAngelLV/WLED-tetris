#pragma once

#include "wled.h"
#include "tetris_includes.h"

static const char data_FX_MODE_TETRIS[] PROGMEM = "Tetris@!,!,!;!;;sx=24";
static Tetris *tetris = nullptr;
static WledDisplay *display = nullptr;

static uint64_t tetris_last = 0;

uint16_t tetris_mode() {
    if (tetris == nullptr) {
        if (!SEGMENT.is2D()) {
            SEGMENT.fill(RED);
            return strip.isOffRefreshRequired() ? FRAMETIME : 350;
        }

        display = new WledDisplay();
        tetris = new Tetris(display);
    }

    if (tetris_last < millis() + SEGMENT.speed) {
        tetris_last = millis() + 255;
        tetris->draw();
    }

    return FRAMETIME;
}

class TetrisUsermod : public Usermod {
    bool enabled = false;
    bool initDone = false;

public:
    inline void enable(bool enable) { enabled = enable; }
    inline bool isEnabled() { return enabled; }

    void setup() {
        initDone = true;
        strip.addEffect(255, &tetris_mode, data_FX_MODE_TETRIS);
    }
    void loop() {

    }
};
