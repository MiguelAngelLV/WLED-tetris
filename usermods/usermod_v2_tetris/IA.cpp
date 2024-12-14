#include "IA.h"

#include <stdlib.h>

IA::IA(Grid* grid) {
    this->grid = grid;
}

IATarget IA::calculatePosition(Piece piece) const {
    IATarget target{
        .x = piece.x,
        .rotation = 0,
        .score = -1000
    };

    const int x = piece.x;

    for (uint8_t r = 0; r < 4; r++) {
        piece.x = x;
        piece.y = 0;

        while (grid->moveLeft(piece)) {
        };

        while (grid->canAddPiece(piece)) {
            while (grid->moveDown(piece)) {
            };

            grid->createBackup();
            grid->addPiece(piece);
            int lines = grid->getLines() * LINES;
            grid->clearLines();

            const float score = lines * LINES
                + grid->getMaxHeight() * HEIGHT
                + grid->getHoles() * HOLES
                + grid->getBumpiness() * BUMPINESS;

            if (score > target.score) {
                target.score = score;
                target.x = piece.x;
                target.rotation = piece.rotations;
            }

            grid->restoreBackup();

            piece.x++;
            piece.y = 0;
        }

        piece.rotate();
    }

    return target;
}
