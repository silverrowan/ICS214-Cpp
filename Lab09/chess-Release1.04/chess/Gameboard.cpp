#include "Gameboard.h"
#include "Blocker.h"
#include <sstream>

Gameboard::~Gameboard() {
    // return any dynamically allocated GameboardItems to the heap
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            if (grid[y][x]) {
                delete grid[y][x];
                grid[y][x] = nullptr;
            }
        }
    }
}

void Gameboard::draw(sf::RenderWindow& window, const ChessPiece* pActiveChessPiece) const
{
    drawBoard(window);
    drawActiveChessPieceHighlights(window, pActiveChessPiece);  
    drawGameboardItems(window);
}

void Gameboard::drawBoard(sf::RenderWindow& window) const
{
    bool light = true;
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            if (light) {
                drawSquare(window, Point(y, x), Constants::colorLight);
            }
            else {
                drawSquare(window, Point(y, x), Constants::colorDark);
            }
            light = !light;
        }
        light = !light;
    }
}

void Gameboard::drawActiveChessPieceHighlights(sf::RenderWindow& window, const ChessPiece* pActiveChessPiece) const
{
    if (pActiveChessPiece) {
        Point activeSquareLoc = pActiveChessPiece->getPosition();
        drawSquare(window, activeSquareLoc, Constants::colorSelected);

        std::vector<Point> validMoves;

        // TODO: Comment this line in once getValidMoves() has been implemented in concrete ChessPiece classes.
        //validMoves = pActiveChessPiece->getValidMoves();

        for (auto& validMoveLoc : validMoves) {
            drawSquare(window, validMoveLoc, Constants::colorPotentialMove);
        }
    } 
}

void Gameboard::drawGameboardItems(sf::RenderWindow& window) const
{
    for (int y = 0; y < MAX_Y; y++) {
        for (int x = 0; x < MAX_X; x++) {
            GameboardItem* pItem = grid[y][x];
            if (pItem) {
                pItem->draw(window);                
            }
        }
    }
}

void Gameboard::drawSquare(sf::RenderWindow& window, const Point& boardLoc, const sf::Color& color) const {   
    // Use a sf::Vector2f to store the square width & height 
    // This is the SFML equivalent of our Point class - except it uses floats
    sf::Vector2f squareSize(static_cast<float>(squareWidth), static_cast<float>(squareHeight));
    sf::RectangleShape square( squareSize );
    square.setFillColor(color);

    // determine the pixel location that we want to draw a square at
    int pixelX = topLeftOffset.getX() + (boardLoc.getX() * squareWidth);
    int pixelY = topLeftOffset.getY() + (boardLoc.getY() * squareHeight);
          
    // Use a sf::Vector2f to store the X,Y values 
    // This is the SFML equivalent of our Point class - except it uses floats
    sf::Vector2f newPos(static_cast<float>(pixelX), static_cast<float>(pixelY));
    square.setPosition(newPos);   
    window.draw(square);
}


Point Gameboard::convertPixelToBoardLoc(const Point& pixel) {
    Point boardLoc(-1, -1);

    int boardY = -1;
    if (pixel.getX() >= topLeftOffset.getX() &&
        pixel.getY() >= topLeftOffset.getY() &&
        pixel.getX() < topLeftOffset.getX() + (MAX_X * squareWidth) &&
        pixel.getY() < topLeftOffset.getY() + (MAX_Y * squareHeight)) {

        boardLoc.setX( (pixel.getX() - topLeftOffset.getX()) / squareWidth);
        boardLoc.setY( (pixel.getY() - topLeftOffset.getY()) / squareHeight);
    }
    return boardLoc;
}


bool Gameboard::isValid(const Point& squareLoc) const {
    return squareLoc.getX() >= 0 &&
        squareLoc.getX() < MAX_X &&
        squareLoc.getY() >= 0 &&
        squareLoc.getY() < MAX_Y;
}


void Gameboard::setItemAt(const Point& squareLoc, GameboardItem* pItem) {

    // inform the board of the item (or nullptr)
    grid[squareLoc.getY()][squareLoc.getX()] = pItem;

    // inform the item that it is connected to the gameboard at a specific location
    if (pItem) {
        pItem->setGameboard(this);
        pItem->setPosition(squareLoc);
    }
}

void Gameboard::captureItem(const Point& squareLoc) {
    GameboardItem* pItem = getItem(squareLoc);
    if (pItem) {
        std::cout << "captured: " << pItem->getName() << "\n";
        setItemAt(squareLoc, nullptr);
        delete pItem;
        pItem = nullptr;
    }
}

//bool Gameboard::containsBlockerAt(const Point& squareLoc) const {   
//    // TODO
//    return false;
//}
//
//bool Gameboard::containsChessPieceOfColorAt(const Point& squareLoc, ChessPiece::Color color) const {
//    // TODO
//    return false;
//}



//void Gameboard::findValidMovesInDir(std::vector<Point>& validMoves, const Point& startPos, const 
//Point& dir, ChessPiece::Color colorOfMovingPiece) const {
//    Point move = startPos;
//    bool attackingOppositeColor = false;
//
//    do {
//        move = move + dir;
//       
//        if (isValid(move) &&
//            !containsBlockerAt(move) &&
//            !containsChessPieceOfColorAt(move, colorOfMovingPiece))
//        {
//            if (containsChessPieceOfColorAt(move, ChessPiece::getOppositeColor(colorOfMovingPiece))) {
//                attackingOppositeColor = true;
//            }
//        }
//        else {
//            return;  // we ran into a wall or a piece of the same color
//        }
//        validMoves.push_back(move);
//
//        if (attackingOppositeColor) {   // we ran into a piece of the opposite color 
//            return;
//        }
//    } while (true);       
//}
