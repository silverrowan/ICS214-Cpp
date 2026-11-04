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

    //std::cout << "-----------copyRow--------\n";

    //b.copyRowIntoRow(3,5);
    //std::cout << b.getContent(0, 3) << "\n";
    //std::cout << b.getContent(5, 3) << "\n";
    //std::cout << b.getContent(9, 3) << "\n";
    //std::cout << b.isValidPoint(10, 3) << "\n";
    //b.printToConsole();
    //
    //std::cout << "-----------removeRow--------\n";
    //b.removeRow(3);
    ////b.removeRow(2); //throws error as it should
    //b.copyRowIntoRow(5, 6);
    //b.copyRowIntoRow(5, 7);
    //b.copyRowIntoRow(5, 8);
    //b.printToConsole();
    //std::cout << "-----------removeFullRow--------\n";
    //std::vector<int> completed{ b.getCompletedRowIndices() }
    //b.removeRows({7,8});
}