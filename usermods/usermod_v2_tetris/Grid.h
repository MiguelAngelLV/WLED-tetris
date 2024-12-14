#ifndef GRID_H
#define GRID_H
#include <cstdint>

#include "Piece.h"

class Grid
{
    uint8_t* pixels;
    uint8_t* backup{};
    int width;
    int height;

    bool move(Piece & piece, int x, int y) const;

public:
    Grid(int width, int height);
    ~Grid();
    uint8_t getPixel(int x, int y) const;
    void setPixel(int x, int y, uint8_t value) const;

    int getColumnHeight(int x) const;
    int getMaxHeight() const;
    int getLines() const;
    int getHoles() const;
    int getBumpiness() const;
    int getHoles(int x) const;
    void clearLines() const;
    bool isLine(int y) const;

    bool canAddPiece(const Piece& piece) const;
    bool moveLeft(Piece& piece) const;
    bool moveRight(Piece& piece) const;
    bool moveDown(Piece& piece) const;
    bool hasLines() const;
    void addPiece(const Piece& piece) const;
    void removePiece(const Piece& piece) const;
    void clear() const;
    void createBackup() const;
    void restoreBackup() const;
};

#endif
