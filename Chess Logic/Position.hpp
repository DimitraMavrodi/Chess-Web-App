#include <iostream>

#ifndef _POSSITION_HPP_
#define _POSSITION_HPP_

class Position
{
    public:
        int inX;
        int inY;
        int outX;
        int outY;
    public:
        Position();
        Position(int inX, int inY, int outX, int outY);
        Position(const Position& position);
        int getInX()const;
        int getInY()const;
        int getOutX()const;
        int getOutY()const; 
        void setPos(int inX, int inY, int outX, int outY);
        bool isEqual(const Position& position)const; 
        friend std::ostream& operator<<(std::ostream& os, const Position& position);
};

#endif