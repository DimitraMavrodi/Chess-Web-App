#include "Pawns.hpp"

#ifndef _KNIGHT_HPP_
#define _KNIGHT_HPP_

class Knight : public Pawns
{
    public:
        Knight(char name, char color, unsigned int value, int posX, int posY);
        Knight(Knight& knight);
        list<Position> possiblePosToMove(Board *board);
};

#endif