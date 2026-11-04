#include <iostream>
#include "TestSuite.h"
#include "Tetromino.h"
#include "Point.h"

int main()
{
    TestSuite::runTestSuite();

    std::cout << "==================================================\n";
    std::cout << "=====================Test Bed=====================\n";
    std::cout << "==================================================\n";

    Tetromino t;

    char choice{};

    while (true) {
        //options: 
        std::cout << "choose: rotate (r), new shape( s, z, l, j, o, i, or t ), or exit(q)\n";
        std::cin >> choice;
        switch (choice) {
        case 'r':
            t.rotateClockwise();
            break;
        case 's':
            t.setShape(TetShape::S);
            break;
        case 'z':
            t.setShape(TetShape::Z);
            break;
        case 'l':
            t.setShape(TetShape::L);
            break;
        case 'j':
            t.setShape(TetShape::J);
            break;
        case 'o':
            t.setShape(TetShape::O);
            break;
        case 'i':
            t.setShape(TetShape::I);
            break;
        case 't':
            t.setShape(TetShape::T);
            break;
        case 'q':
            return 0;
            break;
        default:
            std::cout << "try again\n";
            continue;
            break;
        }
        t.printToConsole();
    }
}