#include <SFML/Graphics.hpp>
#include <iostream>
#include "ChessGame.h"

// for mem leak test
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#include "TestSuite.h"
#include "ConcreteChessPieces.h"
#include "Blocker.h"

int main()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    TestSuite::runTestSuite();

    try {
        sf::RenderWindow window(sf::VideoMode({ 750, 750 }), " Chess Demo");
        window.setFramerateLimit(144);

        ChessGame game;

        // TODO: comment these in once derived classes are concrete.
        game.addItemToBoard(new Blocker(), { 3,1 });
        game.addItemToBoard(new King(ChessPiece::Color::black), { 4,0 });
        game.addItemToBoard(new Knight(ChessPiece::Color::white), {1,0});
        game.addItemToBoard(new Knight(ChessPiece::Color::white), {2,2});

      
        while (window.isOpen())
        {
            while (const std::optional event = window.pollEvent())
            {
                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                game.update(event);     // handle game events (key & mouse clicks)
            }
            window.clear();
            game.draw(window);
            window.display();
        }
    }
    catch (std::exception& ex) {
        std::cout << "caught exception in main(): " << ex.what() << "\n";
    }
    catch (...) {
        std::cout << "caught unknown exception in main()\n";
    }
}
