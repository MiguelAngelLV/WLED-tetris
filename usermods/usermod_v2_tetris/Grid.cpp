#include "Grid.h"

#include <cmath>
#include <cstring>

Grid::Grid(const int width, const int height) {
    this->width = width;
    this->height = height;
    this->pixels = new uint8_t[width * height];
    this->backup = new uint8_t[width * height];
    clear();
}

Grid::~Grid() {
    delete[] pixels;
}

uint8_t Grid::getPixel(const int x, const int y) const {
    return this->pixels[y * this->width + x];
}

void Grid::setPixel(const int x, const int y, const uint8_t value) const {
    this->pixels[y * this->width + x] = value;
}

int Grid::getColumnHeight(const int x) const {
    for (int y = 0; y < height; y++)
        if (getPixel(x, y) > 0)
            return height - y;

    return 0;
}

int Grid::getMaxHeight() const {
    int max = 0;
    for (int x = 0; x < width; x++) {
        const int height = getColumnHeight(x);
        if (height > max) max = height;
    }

    return max;
}

int Grid::getLines() const {
    int lines = 0;
    for (int y = 0; y < height; y++)
        if (isLine(y)) lines++;

    return lines;
}

int Grid::getHoles() const {
    int holes = 0;
    for (int x = 0; x < width; x++)
        holes += getHoles(x);

    return holes;
}

int Grid::getBumpiness() const {
    int bumpiness = 0;
    for (int x = 1; x < width; x++) {
        bumpiness += abs(getColumnHeight(x) - getColumnHeight(x-1));
    }
    return bumpiness;
}

int Grid::getHoles(const int x) const {
    int holes = 0;
    int max = getColumnHeight(x);
    for (int y = 0; y < max; y++) {
        if (getPixel(x, height - y - 1) == 0) holes++;
    }

    return holes;
}

void Grid::clearLines() const {
    int distance = 0;

    for (int y = height - 1; y >= 0; y--) {
        if (isLine(y)) {
            distance++;
            for (int x = 0; x < width; x++)
                setPixel(y, x, 0);
        }
        else if (distance > 0) {
            for (int x = 0; x < width; x++) {
                setPixel(x, y + distance, getPixel(x, y));
                setPixel(y, x, 0);
            }
        }
    }
}


bool Grid::isLine(const int y) const {
    for (int x = 0; x < width; x++)
        if (getPixel(x, y) == 0)
            return false;

    return true;
}

bool Grid::canAddPiece(const Piece& piece) const {
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++) {
            if (piece.pixels[x][y] > 0) {
                const int px = piece.x + x;
                const int py = piece.y + y;
                if (px >= width || py >= height)
                    return false;

                if (getPixel(px, py) > 0)
                    return false;
            }
        }

    return true;
}

bool Grid::move(Piece& piece, int x, int y) const {
    if (piece.x + x < 0 || piece.y + y < 0)
        return false;

    piece.x += x;
    piece.y += y;

    if (canAddPiece(piece))
        return true;

    piece.x -= x;
    piece.y -= y;
    return false;
}

bool Grid::moveLeft(Piece& piece) const {
    return move(piece, -1, 0);
}

bool Grid::moveRight(Piece& piece) const {
    return move(piece, 1, 0);
}

bool Grid::moveDown(Piece& piece) const {
    return move(piece, 0, 1);
}

bool Grid::hasLines() const {
    for (int y = 0; y < height; y++)
        if (isLine(y)) return true;

    return false;
}


void Grid::addPiece(const Piece& piece) const {
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (piece.pixels[x][y] > 0) {
                const int px = piece.x + x;
                const int py = piece.y + y;
                setPixel(px, py, piece.pixels[x][y]);
            }
}

void Grid::removePiece(const Piece& piece) const {
    for (int x = 0; x < 4; x++)
        for (int y = 0; y < 4; y++)
            if (piece.pixels[x][y] > 0) {
                const int px = piece.x + x;
                const int py = piece.y + y;
                setPixel(px, py, 0);
            }
}


void Grid::clear() const {
    memset(pixels, 0, width * height * sizeof(uint8_t));
}

void Grid::createBackup() const {
    memcpy(backup, pixels, width * height * sizeof(uint8_t));
}

void Grid::restoreBackup() const {
    memcpy(pixels, backup, width * height * sizeof(uint8_t));
}
