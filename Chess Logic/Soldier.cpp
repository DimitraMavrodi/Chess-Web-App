#include "Soldier.hpp"
#include "Position.hpp"
#include "Board.hpp"

Soldier::Soldier(char playerColor, char name, char color, unsigned int value, bool hasMoved, int posX, int posY)
{
    this -> name = name;
    this -> color = color;
    this -> value = value;
    this -> hasMoved = hasMoved;
    this -> posX = posX;
    this -> posY = posY;

    if(playerColor == 'w')
    {
        if((color == 'w') && (posX != 6)) { this -> hasMoved = true; }
        if((color == 'b') && (posX != 1)) { this -> hasMoved = true; }
    }

    if(playerColor == 'b')
    {
        if((color == 'w') && (posX != 1)) { this -> hasMoved = true; }
        if((color == 'b') && (posX != 6)) { this -> hasMoved = true; }
    }
}

Soldier::Soldier(Soldier& soldier)
{
    this -> name = soldier.name;
    this -> color = soldier.color;
    this -> value = soldier.value;
    this -> hasMoved = soldier.hasMoved;
    this -> posX = soldier.posX;
    this -> posY = soldier.posY;
}

list<Position> Soldier::possiblePosToMove(Board *board)
{
    std::list<Position> possibleMoves;
    int offset;

    if(((board -> getPlayerColor() == 'w') && (this -> getColor() == 'w')) || ((board -> getPlayerColor() == 'b') && (this -> getColor() == 'b')))
    {
        offset = -1;
    }
    else if(((board -> getPlayerColor() == 'w') && (this -> getColor() == 'b')) || ((board -> getPlayerColor() == 'b') && (this -> getColor() == 'w')))
    {
        offset = 1;
    }

    if((board -> checkInBounds(this -> getPosX() + offset, this -> getPosY())) && (board -> IsPosEmpty(this -> getPosX() + offset, this -> getPosY())))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + offset, this -> getPosY()));
    }
    
    if((board -> checkInBounds(this -> getPosX() + offset, this -> getPosY())) && (board -> checkInBounds(this -> getPosX() + (2 * offset), this -> getPosY())) && (board -> IsPosEmpty(this -> getPosX() + offset, this -> getPosY())) && (board -> IsPosEmpty(this -> getPosX() + (2 * offset), this -> getPosY())) && (!this -> getHasMoved()))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + (2 * offset), this -> getPosY()));
    }
    
    if((board -> checkInBounds(this -> getPosX() + offset, this -> getPosY() + offset)) && (!(board -> IsPosEmpty(this -> getPosX() + offset, this -> getPosY() + offset))) && (board -> getBoardPos(this -> getPosX() + offset, this -> getPosY() + offset) -> getColor() != this -> getColor()))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + offset, this -> getPosY() + offset));
    }
    
    if((board -> checkInBounds(this -> getPosX() + offset, this -> getPosY() - offset)) && (!(board -> IsPosEmpty(this -> getPosX() + offset, this -> getPosY() - offset))) && (board -> getBoardPos(this -> getPosX() + offset, this -> getPosY() - offset) -> getColor() != this -> getColor()))
    {
        possibleMoves.push_back(Position(this -> getPosX(), this -> getPosY(), this -> getPosX() + offset, this -> getPosY() - offset));
    }

    return possibleMoves;
}

bool Soldier::getHasMoved()
{
    return(this -> hasMoved);
}

void Soldier::setHasMoved(bool hasMoved)
{
    this -> hasMoved = hasMoved;
}