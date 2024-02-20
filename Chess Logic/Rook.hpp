#include "Pawns.hpp"

#ifndef _ROOK_HPP_
#define _ROOK_HPP_

class Rook : public Pawns
{
    public:
        Rook(char name, char color, unsigned int value, int posX, int posY);
        Rook(Rook& rook);
        list<Position> possiblePosToMove(Board *board);
};

#endif