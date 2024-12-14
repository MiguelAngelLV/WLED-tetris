//
// Created by miguel on 12/12/24.
//

#include "Piece.h"

#include <cstring>

Piece::Piece(const uint8_t type, const int x, const int y)
{
    this->x = x;
    this->y = y;
    this->type = type;
    this->rotations = 0;

    memset(pixels, 0, sizeof(pixels));
    switch (type)
    {
    case I:
        createI();
        break;
    case J:
        createJ();
        break;
    case L:
        createL();
        break;
    case O:
        createO();
        break;
    case S:
        createS();
        break;
    case T:
        createT();
        break;
    case Z:
        createZ();
        break;
    default: ;
    }
}

void Piece::rotate()
{

    if (type == O)
        return;

    uint8_t newPixels[4][4] = {};

    if (type == I)
    {
        newPixels[0][0] = pixels[3][0];
        newPixels[0][1] = pixels[2][0];
        newPixels[0][2] = pixels[1][0];
        newPixels[0][3] = pixels[0][0];
        newPixels[1][3] = pixels[0][1];
        newPixels[2][3] = pixels[0][2];
        newPixels[3][3] = pixels[0][3];
        newPixels[3][2] = pixels[1][3];
        newPixels[3][1] = pixels[2][3];
        newPixels[3][0] = pixels[3][3];
        newPixels[2][0] = pixels[3][2];
        newPixels[1][0] = pixels[3][1];
        newPixels[1][1] = pixels[2][1];
        newPixels[1][2] = pixels[1][1];
        newPixels[2][2] = pixels[1][2];
        newPixels[2][1] = pixels[2][2];
    } else {
        newPixels[0][0] = pixels[2][0];
        newPixels[0][1] = pixels[1][0];
        newPixels[0][2] = pixels[0][0];
        newPixels[1][0] = pixels[2][1];
        newPixels[1][1] = pixels[1][1];
        newPixels[1][2] = pixels[0][1];
        newPixels[2][0] = pixels[2][2];
        newPixels[2][1] = pixels[1][2];
        newPixels[2][2] = pixels[0][2];
    }
    memcpy(&pixels, &newPixels, sizeof(pixels));
    rotations++;
}

void Piece::createI()
{
    pixels[0][0] = I;
    pixels[1][0] = I;
    pixels[2][0] = I;
    pixels[3][0] = I;
}

void Piece::createO()
{
    pixels[0][0] = O;
    pixels[0][1] = O;
    pixels[1][0] = O;
    pixels[1][1] = O;
}

void Piece::createJ()
{
    pixels[0][0] = J;
    pixels[1][0] = J;
    pixels[1][1] = J;
    pixels[1][2] = J;
}

void Piece::createL()
{
    pixels[0][2] = L;
    pixels[1][0] = L;
    pixels[1][1] = L;
    pixels[1][2] = L;
}

void Piece::createZ()
{
    pixels[0][0] = Z;
    pixels[0][1] = Z;
    pixels[1][1] = Z;
    pixels[1][2] = Z;
}

void Piece::createS()
{
    pixels[0][1] = S;
    pixels[0][2] = S;
    pixels[1][0] = S;
    pixels[1][1] = S;
}

void Piece::createT()
{
    pixels[0][1] = T;
    pixels[1][0] = T;
    pixels[1][1] = T;
    pixels[1][2] = T;
}
