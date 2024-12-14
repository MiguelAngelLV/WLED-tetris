// Created by miguel on 12/12/24.
//

#include "Tetris.h"

#include <cstdlib>
#include <stdlib.h>

#include "IA.h"

Tetris::Tetris(Display* display): piece(0, 0, 0) {
    this->display = display;
    grid = new Grid(display->getWidth(), display->getHeight());
    ia = new IA(grid);
    piece = createPiece();
    target = ia->calculatePosition(piece);
    state = MOVING;
    flashing = 6;
}

Tetris::~Tetris() {
    delete grid;
}

Piece Tetris::createPiece() const {
    uint8_t type = rand() % 7 + 1;
    return Piece(type, display->getWidth() / 2, 0);
}

void Tetris::moving() {
    grid->removePiece(piece);

    if (piece.x > target.x) {
        grid->moveLeft(piece);
    }

    if (piece.x < target.x) {
        grid->moveRight(piece);
    }

    if (piece.rotations < target.rotation) {
        piece.rotate();
    }

    if (!grid->moveDown(piece)) {
        grid->addPiece(piece);

        if (grid->hasLines())
            state = FLASHING;
        else
            state = NEW_PIECE;
    }

    grid->addPiece(piece);

}

void Tetris::flash() {
    flashing--;

    if (flashing == 0) {
        flashing = 6;
        state = NEW_PIECE;
    }
}

void Tetris::newPiece() {
    grid->clearLines();
    piece = createPiece();
    if (!grid->canAddPiece(piece)) {
        grid->clear();
    }
    target = ia->calculatePosition(piece);

    state = MOVING;
}

void Tetris::draw() {

    if (state == MOVING)
        moving();

    if (state == FLASHING)
        flash();

    if (state == NEW_PIECE)
        newPiece();


    for (int y = 0; y < display->getHeight(); y++) {
        for (int x = 0; x < display->getWidth(); x++) {
            if (flashing % 2 == 0)
                display->setColor(x, y, grid->getPixel(x, y));
            else if (grid->isLine(y))
                display->setColor(x, y, 0);
        }
    }

    display->show();
}
