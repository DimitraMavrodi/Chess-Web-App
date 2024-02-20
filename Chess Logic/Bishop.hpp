#include "Pawns.hpp"

#ifndef _BISHOP_HPP_
#define _BISHOP_HPP_

class Bishop : public Pawns
{
    public:
        Bishop(char name, char color, unsigned int value, int posX, int posY);
        Bishop(Bishop& bishop);
        list<Position> possiblePosToMove(Board *board);
};

#endif