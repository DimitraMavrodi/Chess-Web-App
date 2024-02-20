#include "Pawns.hpp"

char Pawns::getName()
{
    return(this -> name);
}

void Pawns::setName(char name)
{
    this -> name = name;
}

char Pawns::getColor()
{
    return(this -> color);
}

void Pawns::setColor(char color)
{
    this -> color = color;
}

unsigned int Pawns::getValue()
{
    return(this -> value);
}

void Pawns::setValue(unsigned int value)
{
    this -> value = value;
}

int Pawns::getPosX()
{
    return(this -> posX);
}

void Pawns::setPosX(int posX)
{
    this -> posX = posX;
}

int Pawns::getPosY()
{
    return(this -> posY);
}

void Pawns::setPosY(int posY)
{
    this -> posY = posY;
}