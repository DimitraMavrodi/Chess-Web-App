#include "Board.hpp"
#include "Pawns.hpp"
#include "Queen.hpp"
#include "Soldier.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "King.hpp"
#include "Bishop.hpp"
#include "Soldier.hpp"
#include <iostream>
#include <fstream>

// Comstructor, Init Board
Board::Board(int height, int width, char playerColor)
{
    int i = 0, j = 0;

    this -> width = width;
    this -> height = height;
    this -> playerColor = playerColor;

    this -> board = new Pawns**[this -> height];

    if(this -> board == NULL)
    {
        cerr << "Memory allocation failure!" << endl;
        std::exit(-1);
    }

    for(i = 0; i < this -> height; i++)
    {
        this -> board[i] = new Pawns*[this -> width];

        if(this -> board[i] == NULL)
        {
            cerr << "Memory allocation failure!" << endl;
            std::exit(-1);
        }
    }

    for(i = 0; i < this -> height; i++)
    {
        for(j = 0; j < this -> width; j++)
        {
            this -> board[i][j] = NULL;
        }
    }

    if(playerColor == 'w')
    {
        this -> board[0][0] = new Rook('r', 'b', 5, 0, 0);
        this -> board[0][7] = new Rook('r', 'b', 5, 0, 7);
        this -> board[0][1] = new Knight('n', 'b', 3, 0, 1);
        this -> board[0][6] = new Knight('n', 'b', 3, 0, 6);
        this -> board[0][2] = new Bishop('b', 'b', 3, 0, 2);
        this -> board[0][5] = new Bishop('b', 'b', 3, 0, 5);
        this -> board[0][3] = new Queen('q', 'b', 9, 0, 3);
        this -> board[0][4] = new King('k', 'b', 100, 0, 4);

        // for(i = 0; i < this -> width; i++)
        // {
        //     this -> board[1][i] = new Soldier('s', 'b', 1, false, 1, i);
        // }

        this -> board[1][0] = new Soldier(playerColor, 's', 'b', 1, false, 1, 0);
        this -> board[1][1] = new Soldier(playerColor, 's', 'b', 1, false, 1, 1);
        this -> board[1][2] = new Soldier(playerColor, 's', 'b', 1, false, 1, 2);
        this -> board[1][3] = new Soldier(playerColor, 's', 'b', 1, false, 1, 3);
        this -> board[1][4] = new Soldier(playerColor, 's', 'b', 1, false, 1, 4);
        this -> board[1][5] = new Soldier(playerColor, 's', 'b', 1, false, 1, 5);
        this -> board[1][6] = new Soldier(playerColor, 's', 'b', 1, false, 1, 6);
        this -> board[1][7] = new Soldier(playerColor, 's', 'b', 1, false, 1, 7);


        this -> board[7][0] = new Rook('R', 'w', 5, 7, 0);
        this -> board[7][7] = new Rook('R', 'w', 5, 7, 7);
        this -> board[7][1] = new Knight('N', 'w', 3, 7, 1);
        this -> board[7][6] = new Knight('N', 'w', 3, 7, 6);
        this -> board[7][2] = new Bishop('B', 'w', 3, 7, 2);
        this -> board[7][5] = new Bishop('B', 'w', 3, 7, 5);
        this -> board[7][3] = new Queen('Q', 'w', 9, 7, 3);
        this -> board[7][4] = new King('K', 'w', 100, 7, 4);

        // for(i = 0; i < this -> width; i++)
        // {
        //     this -> board[6][i] = new Soldier('S', 'w', 1, false, 6, i);
        // }

        this -> board[6][0] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 0);
        this -> board[6][1] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 1);
        this -> board[6][2] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 2);
        this -> board[6][3] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 3);
        this -> board[6][4] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 4);
        this -> board[6][5] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 5);
        this -> board[6][6] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 6);
        this -> board[6][7] = new Soldier(playerColor, 'S', 'w', 1, false, 6, 7);
    }

    if(playerColor == 'b')
    {
        this -> board[7][0] = new Rook('r', 'b', 5, 7, 0);
        this -> board[5][4] = new Rook('r', 'b', 5, 5, 4);
        this -> board[7][1] = new Knight('n', 'b', 3, 7, 1);
        this -> board[7][6] = new Knight('n', 'b', 3, 7, 6);
        this -> board[7][2] = new Bishop('b', 'b', 3, 7, 2);
        this -> board[7][5] = new Bishop('b', 'b', 3, 7, 5);
        this -> board[1][5] = new Queen('q', 'b', 9, 1, 5);
        this -> board[7][4] = new King('k', 'b', 100, 7, 4);

        // for(i = 0; i < this -> width; i++)
        // {
        //     this -> board[6][i] = new Soldier('s', 'b', 1, false, 6, i);
        // }

        this -> board[6][0] = new Soldier(playerColor, 's', 'b', 1, false, 6, 0);
        this -> board[6][1] = new Soldier(playerColor, 's', 'b', 1, false, 6, 1);
        this -> board[6][2] = new Soldier(playerColor, 's', 'b', 1, false, 6, 2);
        this -> board[6][3] = new Soldier(playerColor, 's', 'b', 1, false, 6, 3);
        this -> board[6][4] = new Soldier(playerColor, 's', 'b', 1, false, 6, 4);
        this -> board[6][5] = new Soldier(playerColor, 's', 'b', 1, false, 6, 5);
        this -> board[6][6] = new Soldier(playerColor, 's', 'b', 1, false, 6, 6);
        this -> board[6][7] = new Soldier(playerColor, 's', 'b', 1, false, 6, 7);

        this -> board[0][0] = new Rook('R', 'w', 5, 0, 0);
        this -> board[0][7] = new Rook('R', 'w', 5, 0, 7);
        this -> board[0][1] = new Knight('N', 'w', 3, 0, 1);
        this -> board[0][6] = new Knight('N', 'w', 3, 0, 6);
        this -> board[0][2] = new Bishop('B', 'w', 3, 0, 2);
        this -> board[0][5] = new Bishop('B', 'w', 3, 0, 5);
        this -> board[0][3] = new Queen('Q', 'w', 9, 0, 3);
        this -> board[0][4] = new King('K', 'w', 100, 0, 4);

        // for(i = 0; i < this -> width; i++)
        // {
        //     this -> board[1][i] = new Soldier('S', 'w', 1, false, 1, i);
        // }

        this -> board[1][0] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 0);
        this -> board[1][1] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 1);
        this -> board[1][2] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 2);
        this -> board[1][3] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 3);
        //this -> board[1][4] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 4);
        //this -> board[1][5] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 5);
        this -> board[1][6] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 6);
        this -> board[1][7] = new Soldier(playerColor, 'S', 'w', 1, false, 1, 7);
    }
}

// Input for a file
Board::Board(std::string fileName)
{
    fstream file;
    char charRead;
    int i, j, x, y, intRead;

    file.open(fileName, ios::in);

    if(!file)
    {
        std::cout << "No such file";
    }

    file >> intRead;
    this -> height = intRead;
    file >> intRead;
    this -> width = intRead;
    file >> charRead;
    this -> playerColor = charRead;

    this -> board = new Pawns**[this -> height];

    if(this -> board == NULL)
    {
        cerr << "Memory allocation failure!" << endl;
        std::exit(-1);
    }

    for(i = 0; i < this -> height; i++)
    {
        this -> board[i] = new Pawns*[this -> width];

        if(this -> board[i] == NULL)
        {
            cerr << "Memory allocation failure!" << endl;
            std::exit(-1);
        }
    }

    for(i = 0; i < this -> height; i++)
    {
        for(j = 0; j < this -> width; j++)
        {
            this -> board[i][j] = NULL;
        }
    }

    while(file >> x >> y >> charRead)
    {   
        if(charRead == 's')
        {
            this -> board[x][y] = new Soldier(this -> playerColor, 's', 'b', 1, false, x, y);
        }
        else if(charRead == 'S')
        {
            this -> board[x][y] = new Soldier(this -> playerColor, 'S', 'w', 1, false, x, y);
        }
        else if(charRead == 'r')
        {
            this -> board[x][y] = new Rook('r', 'b', 5, x, y);
        }
        else if(charRead == 'R')
        {
            this -> board[x][y] = new Rook('R', 'w', 5, x, y);
        }
        else if(charRead == 'N')
        {
            this -> board[x][y] = new Knight('N', 'w', 3, x, y);
        }
        else if(charRead == 'n')
        {
            this -> board[x][y] = new Knight('n', 'b', 3, x, y);
        }
        else if(charRead == 'B')
        {
            this -> board[x][y] = new Bishop('B', 'w', 3, x, y);
        }
        else if(charRead == 'b')
        {
            this -> board[x][y] = new Bishop('b', 'b', 3, x, y);
        }
        else if(charRead == 'Q')
        {
            this -> board[x][y] = new Queen('Q', 'w', 9, x, y);
        }
        else if(charRead == 'q')
        {
            this -> board[x][y] = new Queen('q', 'b', 9, x, y);
        }
        else if(charRead == 'K')
        {
            this -> board[x][y] = new King('K', 'w', 100, x, y);
        }
        else if(charRead == 'k')
        {
            this -> board[x][y] = new King('k', 'b', 100, x, y);
        }
    }

    file.close();
}

// Copy Constructor
Board::Board(Board& board)
{
    int i = 0, j = 0;

    this -> width = board.width;
    this -> height = board.height;
    this -> playerColor = board.playerColor;

    this -> board = new Pawns**[this -> height];

    if(this -> board == NULL)
    {
        cerr << "Memory allocation failure!" << endl;
        std::exit(-1);
    }

    for(i = 0; i < this -> height; i++)
    {
        this -> board[i] = new Pawns*[this -> width];

        if(this -> board[i] == NULL)
        {
            cerr << "Memory allocation failure!" << endl;
            std::exit(-1);
        }
    }

    for(i = 0; i < this -> height; i++)
    {
        for(j = 0; j < this -> width; j++)
        {
            if(board.board[i][j] != NULL)
            {
                if(Soldier* soldier = dynamic_cast<Soldier*>(board.board[i][j]))
                {       
                    this -> board[i][j] = new Soldier(*soldier);
                }
                else if(Rook* rook = dynamic_cast<Rook*>(board.board[i][j]))
                {
                    this -> board[i][j] = new Rook(*rook);
                }
                else if(Queen* queen = dynamic_cast<Queen*>(board.board[i][j]))
                {
                    this -> board[i][j] = new Queen(*queen);
                }
                else if(Knight* knight = dynamic_cast<Knight*>(board.board[i][j]))
                {
                    this -> board[i][j] = new Knight(*knight);
                }
                else if(King* king = dynamic_cast<King*>(board.board[i][j]))
                {
                    this -> board[i][j] = new King(*king);
                }
                else if(Bishop* bishop = dynamic_cast<Bishop*>(board.board[i][j]))
                {
                    this -> board[i][j] = new Bishop(*bishop);
                }
            }
            else
            {
                this -> board[i][j] = NULL;
            }
        }
    }
}

Board::~Board()
{
    int i, j;

    // Delete Pawns
    for(i = 0; i < this -> height; i++)
    {
        for(j = 0; j < this -> width; j++)
        {
            delete(this -> getBoardPos(i, j));
        }
    }

    for(i = 0; i < this -> height; i++)
    {
        delete[] this -> board[i];
    }

    delete[] this -> board;
}

char Board::getPlayerColor()
{
    return(this -> playerColor);
}

void Board::setPlayerColor(char playerColor)
{
    this -> playerColor = playerColor;
}

bool Board::IsPosEmpty(int PosX, int PosY)
{
    if(this -> board[PosX][PosY] == NULL) // There is no pawn in this position
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

Pawns*** Board::getBoard()
{
    return(this -> board);
}

void Board::setBoard(Pawns*** board)
{
    this -> board = board;
}

Pawns* Board::getBoardPos(int posX, int posY)
{
    return(this -> board[posX][posY]);
}

void Board::setBoardPos(int posX, int posY, Pawns* pawn)
{
    this -> board[posX][posY] = pawn;
}

int Board::getHeight()
{
    return(this -> height);
}

int Board::getWidth()
{
    return(this -> width);
}

bool Board::checkInBounds(int posX, int posY)
{
    if(((posX >= 0) && (posX <= this -> height - 1)) && ((posY >= 0) && (posY <= this -> width - 1)))
    {
        return(true);
    }
    else
    {
        return(false);
    }
}

list<Position> Board::getAllMoves(char color)
{
    std::list<Position> allMoves, moves;
    std::list<Position>::iterator it;
    int i, j;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(!(this -> IsPosEmpty(i, j)))
            {
                if((this -> getBoardPos(i, j) -> getColor()) == color)
                {   
                    moves = this -> getBoardPos(i, j) -> possiblePosToMove(this);

                    for(it = moves.begin(); it != moves.end(); ++it)
                    {
                        allMoves.push_back(*it);
                    }
                }
            }
        }
    }

    return(allMoves);
}

list<Position> Board::getAllMovesExceptKing(char color)
{
    std::list<Position> allMoves, moves;
    std::list<Position>::iterator it;
    int i, j;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(!(this -> IsPosEmpty(i, j)))
            {
                if(this -> getBoardPos(i, j) -> getColor() == color)
                {
                    if((this -> getBoardPos(i, j) -> getName() != 'K') && (this -> getBoardPos(i, j) -> getName() != 'k'))
                    {
                        moves = this -> getBoardPos(i, j) -> possiblePosToMove(this);

                        for(it = moves.begin(); it != moves.end(); ++it)
                        {
                            allMoves.push_back(*it);
                        }
                    }
                }
            }
        }
    }

    return(allMoves);
}

// Need to Check if Move is Valid
void Board::MovePawns(Position Move)
{
    Pawns* pawnsToMove = this -> getBoardPos(Move.getInX(), Move.getInY());
    Pawns* pawnsToDest = this -> getBoardPos(Move.getOutX(), Move.getOutY());

    if((pawnsToMove == NULL) && (pawnsToDest == NULL))
    {
        return;
    }

    if(Soldier* soldier = dynamic_cast<Soldier*>(pawnsToMove))
    {
        soldier -> setHasMoved(true);
    }

    if(pawnsToDest != NULL)
    {
        delete(pawnsToDest);
        this -> setBoardPos(Move.getOutX(), Move.getOutY(), NULL);
    }

    if(pawnsToMove -> getName() == 'S')   // Is White Soldier
    {
        if(((this -> getPlayerColor() == 'b') && (Move.getOutX() == this -> height - 1)) || ((this -> getPlayerColor() == 'w') && (Move.getOutX() == 0)))
        {
            Pawns* newPawns = new Queen('Q', 'w', 90, Move.getOutX(), Move.getOutY());
            this -> setBoardPos(Move.getOutX(), Move.getOutY(), newPawns);
            this -> setBoardPos(Move.getInX(), Move.getInY(), NULL);
            delete(pawnsToMove);
            return;
        }
    }
    else if(pawnsToMove -> getName() == 's')  // Is Black Soldier
    {
        if(((this -> getPlayerColor() == 'b') && (Move.getOutX() == 0)) || ((this -> getPlayerColor() == 'w') && (Move.getOutX() == this -> height - 1)))
        {
            Pawns* newPawns = new Queen('q', 'b', 90, Move.getOutX(), Move.getOutY());
            this -> setBoardPos(Move.getOutX(), Move.getOutY(), newPawns);
            this -> setBoardPos(Move.getInX(), Move.getInY(), NULL);
            delete(pawnsToMove);
            return;
        }
    }
    
    this -> setBoardPos(Move.getInX(), Move.getInY(), NULL);
    this -> setBoardPos(Move.getOutX(), Move.getOutY(), pawnsToMove);
    pawnsToMove -> setPosX(Move.getOutX());
    pawnsToMove -> setPosY(Move.getOutY());

    return;
}

int Board::getAllPawnsValues(char color)
{
    int i, j, value = 0;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(this -> IsPosEmpty(i , j) == false)
            {
                if(this -> getBoardPos(i, j) -> getColor() == color)
                {
                    value = value + this -> getBoardPos(i, j) -> getValue();
                }
                else
                {
                    value = value - this -> getBoardPos(i, j) -> getValue();
                }
            }  
        }
    }

    return(value);
}

int Board::getAllMobilityValues(char color)
{
    int i, j, value;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(!(this -> IsPosEmpty(i, j)))
            {
                if(this -> getBoardPos(i, j) -> getColor() == color)
                {
                    value = value + (this -> getBoardPos(i, j) -> possiblePosToMove(this).size());
                }
                else
                {
                    value = value - (this -> getBoardPos(i, j) -> possiblePosToMove(this).size());
                }
            }
        }
    }

    return(value);
}

int Board::getAllSoldiersValue(char color)
{
    int i, j, value;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(!(this -> IsPosEmpty(i, j)))
            {
                if(this -> getBoardPos(i, j) -> getColor() == color)
                {
                    if(((this -> getBoardPos(i, j) -> getName() == 'S') && (this -> getPlayerColor() == 'w')) || ((this -> getBoardPos(i, j) -> getName() == 's') && (this -> getPlayerColor() == 'b')))
                    {
                        value = value + (this -> getHeight() - 2 - i);
                    }
                    else if(((this -> getBoardPos(i, j) -> getName() == 's') && (this -> getPlayerColor() == 'w')) || ((this -> getBoardPos(i, j) -> getName() == 'S') && (this -> getPlayerColor() == 'b')))
                    {
                        value = value + (i - 1);
                    }
                }
                else
                {
                    if(((this -> getBoardPos(i, j) -> getName() == 'S') && (this -> getPlayerColor() == 'w')) || ((this -> getBoardPos(i, j) -> getName() == 's') && (this -> getPlayerColor() == 'b')))
                    {
                        value = value - (this -> getHeight() - 2 - i);
                    }
                    else if(((this -> getBoardPos(i, j) -> getName() == 's') && (this -> getPlayerColor() == 'w')) || ((this -> getBoardPos(i, j) -> getName() == 'S') && (this -> getPlayerColor() == 'b')))
                    {
                        value = value - (i - 1);
                    }
                }
            }
        }
    }

    return(value);
}

// This is the opponent's color
bool Board::locateCheck(char color)
{
    list<Position> opponentMoves = this -> getAllMoves(this -> getPlayerColor());  // Exept king, because king dont check king
    char colorOpponent, nameOpponent;
    list<Position>::iterator it;

    for(it = opponentMoves.begin(); it != opponentMoves.end(); ++it)
    {
        if(this -> getBoardPos(it -> getOutX(), it -> getOutY()) != NULL)
        {
            colorOpponent = this -> getBoardPos(it -> getOutX(), it -> getOutY()) -> getColor();
            nameOpponent = this -> getBoardPos(it -> getOutX(), it -> getOutY()) -> getName();

            if((colorOpponent != color) && ((nameOpponent == 'K') || (nameOpponent == 'k')))
            {
                return(true);
            }
        }
        else
        {
            continue;
        }
    }

    return(false);
}

bool Board::locateStalemate(char color)
{
    char OpponentColor = (color == 'w') ? 'b' : 'w';

    if(this -> locateCheck(OpponentColor) == true)
    {
        return(false);
    }

    if(this -> getAllMoves(color).size() == 0)
    {
        return(true);
    }

    return(false);
}

// This is the opponent's color
bool Board::locateCheckmate(char color)
{
    char AnotherColor = (color == 'w') ? 'b' : 'w';

    list<Position> allMyMoves = this -> getAllMoves(AnotherColor);
    list<Position>::iterator it;
    Board* boardCopy;
    
    if(this -> locateCheck(color) == true)
    {
        for(it = allMyMoves.begin(); it != allMyMoves.end(); ++it)
        {
            boardCopy = new Board(*this);
            boardCopy -> MovePawns(*it);

            if(boardCopy -> locateCheck(color) == false)
            {
                delete boardCopy;
                return(false);
            }

            delete boardCopy;
        }

        return(true);
    }

    return(false);
}

bool Board::locateDraw()
{
    int i, j, counter = 0;

    for(i = 0; i < this -> getHeight(); i++)
    {
        for(j = 0; j < this -> getWidth(); j++)
        {
            if(!(this -> IsPosEmpty(i, j)))
            {
                if((this -> getBoardPos(i, j) -> getName() != 'k') || (this -> getBoardPos(i, j) -> getName() != 'K'))
                {
                    return(false);
                }
                else
                {
                    counter = counter + 1;
                }
            }
        }
    }

    if(counter == 2)
    {
        return(true);
    }

    return(false);
}