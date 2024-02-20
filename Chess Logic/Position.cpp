#include "Position.hpp"

Position::Position()
{

}

Position::Position(int inX, int inY, int outX, int outY)
{
    this -> inX = inX;
    this -> inY = inY;
    this -> outX = outX;
    this -> outY = outY;
}

Position::Position(const Position& position)
{
    this -> inX = position.inX;
    this -> inY = position.inY;
    this -> outX = position.outX;
    this -> outY = position.outY;
}

int Position::getInX() const
{
    return(this -> inX);
}

int Position::getInY() const
{
    return(this -> inY);
}

int Position::getOutX() const
{
    return(this -> outX);
}

int Position::getOutY() const
{
    return(this -> outY);
}

void Position::setPos(int inX, int inY, int outX, int outY)
{
    this -> inX = inX;
    this -> inY = inY;
    this -> outX = outX;
    this -> outY = outY;
}

bool Position::isEqual(const Position &position) const
{
    return (this->getInX() == position.getInX()) &&
           (this->getInY() == position.getInY()) &&
           (this->getOutX() == position.getOutX()) &&
           (this->getOutY() == position.getOutY());
}


std::ostream& operator<<(std::ostream& os, const Position& position)
{
    os << "Inner Position: (" << position.inX << ", " << position.inY << ") ";
    os << "Outer Position: (" << position.outX << ", " << position.outY << ")";
    return os;
}