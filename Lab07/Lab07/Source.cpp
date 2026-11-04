#include <iostream>
#include "TestSuite.h"
#include "Gameboard.h"
#include "Tetromino.h"
#include "Point.h"

int main()
{
    TestSuite::runTestSuite();

    //Gameboard b;
    //Point pt1{ 1,1 };
    //Point pt2{ 2,2 };

    //b.setContent(pt1, 1);
    //b.setContent(pt2, 2);
    //b.fillRow(3, 3);
    //b.printToConsole();

    //std::cout << b.getContent(pt1);
    //std::cout << b.getContent(3,3);
    //std::cout << b.isRowCompleted(1);
    //std::cout << b.isRowCompleted(3) << "\n";

    //std::cout << "-------------------\n";

    //b.copyRowIntoRow(3,5);
    //std::cout << b.getContent(3,0) << "\n";
    //std::cout << b.getContent(3,5) << "\n";
    //std::cout << b.getContent(3,9) << "\n";
    //std::cout << b.isValidPoint(3,10) << "\n";
    //b.printToConsole();
    
}