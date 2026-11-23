#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChessPiece.h"
#include "Point.h"
#include "Constants.h"

class GameboardItem;


class Gameboard {

private:
    static const int MAX_X = 8;		// gameboard x dimension
    static const int MAX_Y = 8;		// gameboard y dimension

    const int squareWidth;          // pixel width of each square
    const int squareHeight;         // pixel height of each square

    Point topLeftOffset = { 0,0 };  // pixel offset of board topLeft

    GameboardItem* grid[MAX_Y][MAX_X] {};	// a 2D array of pointers to GameboardItem

private:
    // draw an individual board square
    void drawSquare(sf::RenderWindow& window, const Point& pos, const sf::Color& color) const;

    // draw all the black & white board squares
    void drawBoard(sf::RenderWindow& window) const;

    // draw highlights for the active chess piece (shows where valid moves are)
    void drawActiveChessPieceHighlights(sf::RenderWindow& window, const ChessPiece* pActiveChessPiece) const;

    // draw all the GameboardItems (blockers and chess pieces)
    void drawGameboardItems(sf::RenderWindow& window) const;

public:     
    // constructor
    Gameboard(int sqWidth = Constants::gameboardSquareWidth, 
              int sqHeight = Constants::gameboardSquareHeight)
        : squareWidth{ sqWidth }, squareHeight{ sqHeight } {
    }

    // destructor
    ~Gameboard();

    // set top left pixel position
    void setTopLeftOffset(const Point& pos) { topLeftOffset = pos; }

    // get top left pixel position
    Point getTopLeftOffset() const { return topLeftOffset; }

    // get the width of a single square
    int getSquareWidth() const { return squareWidth; }

    // get the height of a single square
    int getSquareHeight() const { return squareHeight; }

    // draw the board, the possible moves, and all GameboardItems
    void draw(sf::RenderWindow& window, const ChessPiece* pActiveChessPiece) const;
 
    // given a screen pixel loc, convert it to a square location (XY) onto the board [0..7][0..7]
    Point convertPixelToBoardLoc(const Point& pixel);
   
    // is the point passed in is a valid square location on the board [0..7][0..7]?
    bool isValid(const Point& squareLoc) const;

    // get the GameboardItem at a given board location
    // if the location is invalid - return nullptr
    GameboardItem* getItem(const Point& loc)  const {
        if (isValid(loc)) {
            return grid[loc.getY()][loc.getX()];
        }
        return nullptr;
    }

    // set the GameboardItem at a given square location.
    // note: can also be used to clear the location (in case an item is captured) by setting to nullptr.
    void setItemAt(const Point& squareLoc, GameboardItem* pItem);
  
    // If the loc contains a GameboardItem:
    //  - print a message to indicate the name of the item being captured
    //  - remove it from the board,
    //  - deallocate the memory for it (return it to the heap).
    void captureItem(const Point& squareLoc);


    // return true if there is a blocker at the given square location (false otherwise).
    bool containsBlockerAt(const Point& squareLoc) const;
    // TODO:
    
    // return true if there is a chess piece at the given loc with the specified color. (false otherwise)
    bool containsChessPieceOfColorAt(const Point& squareLoc, ChessPiece::Color color) const;
    // TODO:
     
    
    // This is a helper method that can be used to find valid moves from a starting point and heading 
    // in a certain direction.  If you wanted to attempt implmenting Rook/Queen/Bishop, you could make
    // use of this functionality.  Otherwise it isn't actually used.
    //void findValidMovesInDir(std::vector<Point>& validMoves, const Point& startPt, const Point& dir, ChessPiece::Color colorOfMovingPiece) const;
}; 