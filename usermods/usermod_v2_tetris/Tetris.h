#ifndef TETRIS_H
#define TETRIS_H
#include "Display.h"
#include "Grid.h"
#include "IA.h"

#define MOVING 1
#define NEW_GAME 2
#define NEW_PIECE 3
#define FLASHING 4

class Tetris {
    Grid* grid;
    Display* display;
    IA* ia;

    Piece piece;
    IATarget target{};

    Piece createPiece() const;
    void moving();
    void flash();
    void newPiece();

    uint8_t state;
    uint8_t flashing;

public:
    explicit Tetris(Display* display);
    ~Tetris();

    void draw();
};


#endif //TETRIS_H
