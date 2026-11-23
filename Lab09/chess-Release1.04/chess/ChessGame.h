#pragma once

#include <SFML/Graphics.hpp>
#include "ChessPiece.h"
#include "Point.h"
#include "Gameboard.h"
#include <cassert>

class ChessGame
{
    friend class TestSuite;

private:
    Gameboard board;                            // the chess board       
    ChessPiece* pActiveChessPiece{ nullptr };   // the active chess piece (if there is one)

public:
    
    ChessGame();     // constructor  
    ~ChessGame();    // destructor

    // add a new gameboard item to the board (the item is aware of its position already)
    void addItemToBoard(GameboardItem* pNewItem, const Point& loc);

    // The loop responsible for displaying the board, and processing clicks (commands)
    void update( const std::optional<sf::Event>& event );

    // draw the chess game (including the board and all the pieces)
    void draw(sf::RenderWindow& window);

   // move the active chess piece to a new board location
    bool moveActiveChessPiece(const Point& pos);

    // set the active chess piece (results in possible moves being displayed)
    void setActiveChessPiece(ChessPiece* piece);

    // clear the active chess piece (no possible moves displayed)
    void clearActiveChessPiece();

    // save the serialized game to a save file
    void saveToFile(const char* filename = "save.txt");
};