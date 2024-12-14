#ifndef IA_H
#define IA_H
#include "Grid.h"

#define HEIGHT 		(-0.56569)
#define LINES 		(+0.99275)
#define HOLES   	(-0.86544)
#define BUMPINESS	(-0.14077)

struct IATarget
{
    int x;
    int rotation;
    float score;
};


class IA
{
    Grid* grid;

public:
    IA(Grid* grid);

    IATarget calculatePosition(Piece piece) const;
};


#endif //IA_H
