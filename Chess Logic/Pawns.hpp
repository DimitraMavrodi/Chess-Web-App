#include <iostream>
#include <list>
#include "Position.hpp"
using namespace std;

#ifndef _PAWNS_HPP_
#define _PAWNS_HPP_

class Board;  // Forward declaration

class Pawns
{
    protected:
        char name;
        char color;            // b -> black and w -> white
        unsigned int value;
        int posX;
        int posY;
    public:
        virtual ~Pawns()= default;
        char getName();
        void setName(char name);
        char getColor();
        void setColor(char color);
        unsigned int getValue();
        void setValue(unsigned int value);
        int getPosX();
        void setPosX(int posX);
        int getPosY();
        void setPosY(int posY);
        virtual std::list<Position> possiblePosToMove(Board *board) = 0;
};

#endif