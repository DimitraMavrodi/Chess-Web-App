#include "Pawns.hpp"

#ifndef _SOLDIER_HPP_
#define _SOLDIER_HPP_

class Soldier : public Pawns
{
    private:
        bool hasMoved;
    public:
        Soldier(char playerColor, char name, char color, unsigned int value, bool hasMoved, int posX, int posY);
        Soldier(Soldier& soldier);
        bool getHasMoved();
        void setHasMoved(bool hasMoved);
        list<Position> possiblePosToMove(Board *board);
};

#endif