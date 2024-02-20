#include "Pawns.hpp"

#ifndef _QUEEN_HPP_
#define _QUEEN_HPP_

class Queen : public Pawns
{
    public:
        Queen(char name, char color, unsigned int value, int posX, int posY);
        Queen(Queen& queen);
        list<Position> possiblePosToMove(Board *board)override;
};

#endif

