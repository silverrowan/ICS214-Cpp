#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChessGame.h"
#include "ConcreteChessPieces.h"
#include "Blocker.h"
#include <algorithm>
#include "Constants.h"
#include <fstream>


ChessGame::ChessGame() 
    : board{ Constants::gameboardSquareWidth, Constants::gameboardSquareHeight }
{      
    board.setTopLeftOffset(Constants::gameboardOffset);    
}

ChessGame::~ChessGame() {
    // We don't need to delete this pointer to the active chess piece.  It is a 
    // second pointer to a heap object that the Gameboard owns.
    pActiveChessPiece = nullptr;
}

void ChessGame::addItemToBoard(GameboardItem* pNewItem, const Point& loc) {
    // Ensure the board location is not occupied  (if occupied, assert!)
    // 2 items can't occupy the same location
    GameboardItem* pExistingItem = board.getItem(loc);
    assert(!pExistingItem && "addItemToBoard() position already occupied!");

    // inform the board of a new item at that location
    // (note: this will also inform the new item of the board, and its location)
    board.setItemAt(loc, pNewItem);
}

void ChessGame::draw(sf::RenderWindow& window) {
    board.draw(window, pActiveChessPiece);
}

void ChessGame::setActiveChessPiece(ChessPiece* pChessPiece) {  
    std::cout << "setting active piece to :" << pChessPiece->getName() << ".\n";
    pActiveChessPiece = pChessPiece;    
}

void ChessGame::clearActiveChessPiece() {
    std::cout << "clearing active piece.\n";
    pActiveChessPiece = nullptr;
}

bool ChessGame::moveActiveChessPiece(const Point& pos)
{
    // if the position we want to move to is off the board (invalid) or occupied, return false
    if (!board.isValid(pos) || board.getItem(pos) ) {
        return false;
    }
    else // the position is available
    {
        // inform the board that the active piece is no longer in the old position
        board.setItemAt(pActiveChessPiece->getPosition(), nullptr);

        // inform the board of the position of the new piece
        // (note: this will also inform the piece of it's new position)
        board.setItemAt(pos, pActiveChessPiece);

        // make it so the active chess piece is no longer active.
        clearActiveChessPiece();
        return true;
    }
}

void ChessGame::update(const std::optional<sf::Event>& event) {

    if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
    {
        if (keyPressed->scancode == sf::Keyboard::Scancode::S)
            saveToFile();
    }

    // detect left mouse button clicks
    if (auto* mouseBtn = event->getIf<sf::Event::MouseButtonPressed>()) {
        if (mouseBtn->button == sf::Mouse::Button::Left) {

            // convert the click location to a board location
            Point clickedBoardLoc = board.convertPixelToBoardLoc(Point(mouseBtn->position.x, mouseBtn->position.y));
            std::cout << "clicked on board loc: [" << clickedBoardLoc.getX() << "," << clickedBoardLoc.getY() << "]\n";

            // Check if there was an item at the click location (via board.Item())
            GameboardItem* pItemClicked = board.getItem(clickedBoardLoc);

            if (!pActiveChessPiece) { // if no active chess piece
                if (pItemClicked && !dynamic_cast<Blocker*>(pItemClicked) ) { // if something thats not a blocker is clicked
                    setActiveChessPiece(dynamic_cast<ChessPiece*>(pItemClicked));
                    return;
                }
            }
            else { // there *is* an active chess piece
                if (pActiveChessPiece->isValidMove(clickedBoardLoc)) {
                    if (pItemClicked) { // if item is clicked; is validMove contains check for blocker (->invalid move)
                        board.captureItem(clickedBoardLoc);
                    } // not blocker check already done... take piece & move
                    moveActiveChessPiece(clickedBoardLoc);
                }
                clearActiveChessPiece();
            }
            clearActiveChessPiece();
            return;
        }
    }
}

void ChessGame::saveToFile(const char* filename)
{
    std::ofstream saveFile(filename = "save.txt");
    if (saveFile) {
        // TODO: once Chessboard implements ISerializable, comment this next line back in.
        //saveFile << board.toString();
        //std::cout << "saving to file: " << filename << "\n";
        //std::cout << board.toString() << "\n";
        saveFile.close();
    }
    else {
        std::cout << "Error writing to savefile.\n";
    }
}
