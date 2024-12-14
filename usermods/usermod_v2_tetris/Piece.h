
#ifndef PIECE_H
#define PIECE_H

#include <cstdint>

#define O     1
#define J     2
#define L     3
#define Z     4
#define S     5
#define T     6
#define I     7


class Piece {
    uint8_t type;
    void createI();
    void createJ();
    void createL();
    void createO();
    void createS();
    void createT();
    void createZ();
public:
    int x;
    int y;
    uint8_t rotations;
    uint8_t pixels[4][4]{};
    Piece(uint8_t piece, int x, int y);
    void rotate();
};



#endif //PIECE_H
