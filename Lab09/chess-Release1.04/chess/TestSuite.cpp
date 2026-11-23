#include <cassert>
#include <iostream>
#include "TestSuite.h"
#include <algorithm>

#ifdef POINT
#include "Point.h"
#include "SFML\System\Vector2.hpp"
#endif

#ifdef GAMEBOARDITEM
#include "Point.h"
#include "GameboardItem.h"
#endif

#ifdef CHESSGAME
#include "Point.h"
#include "GameboardItem.h"
#include "ConcreteChessPieces.h"
#include "ChessGame.h"
#endif


#ifdef CONCRETE_CHESS_PIECES
#include "ConcreteChessPieces.h"
#include "Gameboard.h"
#include "Blocker.h"

enum TestPieceTypes { king, knight };

void testValidMoves(Gameboard& board, TestPieceTypes type, const Point& loc, std::vector<Point> expectedMoves) {
	//Gameboard board;

	ChessPiece* pChessPiece = nullptr;
	if (type == TestPieceTypes::knight) {
		pChessPiece = new Knight(ChessPiece::Color::white);
	}
	else if (type == TestPieceTypes::king) {
		pChessPiece = new King(ChessPiece::Color::white);
	}
	assert(pChessPiece && " invalid chess piece");

	std::cout << "Testing getValidMoves() for " << pChessPiece->toString() << " at " << loc << "\n";

	board.setItemAt(loc, pChessPiece);
	std::cout << board.toString() << "\n";
	std::vector<Point> actualMoves = pChessPiece->getValidMoves();

	// output expected moves
	std::cout << "expected: ";
	for (auto& pt : expectedMoves) {
		std::cout << pt << " ";
	}
	std::cout << "\n";
	// output actual moves
	std::cout << "actual:   ";
	for (auto& pt : actualMoves) {
		std::cout << pt << " ";
	}
	std::cout << "\n\n";
	assert(actualMoves.size() == expectedMoves.size());
	// verify actual == expected
	for (auto& actualPoint : actualMoves) {
		auto it = std::find(expectedMoves.begin(), expectedMoves.end(), actualPoint);
		assert(it != expectedMoves.end());
	}
	// remove the piece
	board.setItemAt(loc, nullptr);

	delete pChessPiece;
	pChessPiece = nullptr;
}
#endif


bool TestSuite::runTestSuite()
{
	std::cout << "=== Running TestSuite =========================" << "\n";
	// run some sanity tests on our classes to ensure they're working as expected.
	std::cout << "Uncomment appropriate #define statements in TestSuite.h to test each class.\n\n";
	testPointClass();
	testConcreteChessPieces();
	testChessGame();
	
	std::cout << "=== TestSuite complete ========================" << "\n\n";
	return true;
}

bool TestSuite::testPointClass()
{
#ifdef POINT
	std::cout << "---------------------------\n";
	std::cout << " testPointClass() called...\n";

	Point p;

	// test our initial values are 0,0
	assert(p.getX() == 0 && "Point ctor - x not initialized to 0");
	assert(p.getY() == 0 && "Point ctor - y not initialized to 0");

	// test setX()
	p.setX(1);
	assert(p.getX() == 1 && "Point::setX() failed");
	p.setX(-1);
	assert(p.getX() == -1 && "Point::setX() failed");

	// test setY()
	p.setY(2);
	assert(p.getY() == 2 && "Point::setY() failed");
	p.setY(-2);
	assert(p.getY() == -2 && "Point::setY() failed");

	// test setXY()
	p.setXY(3, 4);
	assert(p.getX() == 3 && p.getY() == 4 && "Point::setXY() failed");
	p.setXY(-3, -4);
	assert(p.getX() == -3 && p.getY() == -4 && "Point::setXY() failed");

	// test constructor with 2 params
	Point q(3, 4);
	assert(q.getX() == 3 && q.getY() == 4 && "Point::ctor failed to set default params");

	// test swapXY()
	q.swapXY();
	assert(q.getX() == 4 && q.getY() == 3 && "Point::swapXY() failed");

	// test multiplyX()
	q.multiplyX(-1);
	assert(q.getX() == -4 && "Point::multiplyX() failed");

	// test multiplyY()
	q.multiplyY(-1);
	assert(q.getY() == -3 && "Point::multiplyY() failed");

	// test copy constructor
	q.setXY(1, 2);
	Point r = q;
	assert(r.getX() == q.getX() && r.getY() == q.getY() && "Point copy ctor failed");
	r.setXY(3, 4);
	assert(r.getX() == 3 && r.getY() == 4
		&& q.getX() == 1 && q.getY() == 2 && "Point::setXY() failed");

	Point s{ 5,6 };
	std::cout << "expected:\t[5,6]\n";
	std::cout << "actual: \t" << s.toString() << "\n";

	// ensure const methods are actually const
	// These lines will cause compile time errors you have methods in your Point class that
	// should be labelled as const (because the methods don't change the internal member
	// variables of yoru class).
	// The solution: make these const methods!  (see LearnCpp 13.2- const class objects and member functions)
	const Point cPoint{};
	cPoint.getX();
	cPoint.getY();
	cPoint.toString();

	// Testing Point operator overloads

	// testing Point.operator+()
	Point ptSum = Point(2, 3) + Point(4, 5);
	assert(ptSum.getX() == 6);
	assert(ptSum.getY() == 8);

	// testing Point.operator==()
	assert((Point(2, 3) == Point(2, 3)));
	assert((Point(2, 3) == Point(4, 5)) == false);

	// testing Point.operator<<()
	const Point pt1(7, 8);
	std::cout << "expected: [7,8]\n";
	std::cout << "actual:   " << pt1 << '\n';

	std::cout << "...passed!" << "\n\n";
	
	sf::Vector2i pt2i = Point(2, 3);
	sf::Vector2f pt2f = Point(2, 3);

#else
	std::cout << "Point class not tested.\n";
#endif
	return true;
}




bool TestSuite::testConcreteChessPieces()
{
#ifdef CONCRETE_CHESS_PIECES
	std::cout << "---------------------------\n";
	std::cout << " testConcreteChessPieces() called...\n";

	Gameboard board; // we need a board to test chess pieces

	// ensure that methods that should be const actually are.

	const std::vector<Point> v{ Point(0, 0) };

	const Knight constKnight(ChessPiece::Color::white);
	constKnight.toString();
	constKnight.getPosition();
	constKnight.getValidMoves();
	constKnight.isValidMove(Point(0, 0));

	const King constKing(ChessPiece::Color::white);
	constKing.toString();
	constKing.getPosition();
	constKing.getValidMoves();
	constKing.isValidMove(Point(0, 0));

	// test toString()
	assert(constKnight.toString() == std::string("k"));
	assert(constKing.toString() == std::string("K"));

	// test that we can set a board to contain an object (at a given location)
	Knight* pKnight = new Knight(ChessPiece::Color::white);
	Point samplePt(1, 1);
	board.setItemAt(samplePt, pKnight);
	// test that the object knows of its position
	assert(pKnight->getPosition() == Point(1, 1));
	// clear the object
	board.setItemAt(samplePt, nullptr);
	// note: the chess piece's position will still be set (expected)
	delete pKnight;
	pKnight = nullptr;


	std::vector<Point> expectedMoves;
	Gameboard board2;

	// Test Knight moves on empty board
	expectedMoves = { {3,2}, {5,2}, {6,3}, {6,5}, {5,6}, {3,6}, {2,5}, {2,3} };
	testValidMoves(board2, TestPieceTypes::knight, { 4,4 }, expectedMoves);

	expectedMoves = { {0,3}, {2,3}, {3,2}, {3,0} };
	testValidMoves(board2, TestPieceTypes::knight, { 1,1 }, expectedMoves);

	expectedMoves = { {1,6}, {2,5}, {4,5}, {5,6} };
	testValidMoves(board2, TestPieceTypes::knight, { 3,7 }, expectedMoves);

	expectedMoves = { {6,5}, {5,6} };
	testValidMoves(board2, TestPieceTypes::knight, { 7,7 }, expectedMoves);

	// Test King moves on empty board
	expectedMoves = { {3,3}, {4,3}, {5,3}, {3,4}, {5,4}, {3,5}, {4,5}, {5,5} };
	testValidMoves(board2, TestPieceTypes::king, { 4,4 }, expectedMoves);

	expectedMoves = { {1,0}, {1,1}, {0,1} };
	testValidMoves(board2, TestPieceTypes::king, { 0,0 }, expectedMoves);

	expectedMoves = { {7,6}, {6,6}, {6,7} };
	testValidMoves(board2, TestPieceTypes::king, { 7,7 }, expectedMoves);


	// Put a blocker on the board, and retest
	Blocker* pBlocker = new Blocker();
	board2.setItemAt({ 1,1 }, pBlocker);

	expectedMoves = { { 0,1 }, { 1,0} };
	testValidMoves(board2, TestPieceTypes::king, { 0,0 }, expectedMoves);

	expectedMoves = { {2,2 }, {4,2 }, {5,1 }  };
	testValidMoves(board2, TestPieceTypes::knight, { 3,0 }, expectedMoves);

	// remove the blocker from the board
	board2.setItemAt({ 1,1 }, nullptr);
	// delete the blocker
	delete pBlocker;
	pBlocker = nullptr;
	
	std::cout << "...passed!" << "\n\n";

#else
	std::cout << "ConcreteChessPieces not tested.\n";
#endif
	return true;
}




bool TestSuite::testChessGame()
{
#ifdef CHESSGAME
	std::cout << "---------------------------\n";
	std::cout << " testChessGame() called...\n";
	ChessGame game;
	Point ptKnightStart(1, 0);
	Point ptBlockerStart(3, 1);
	Point ptKingStart(4, 0);
	game.addItemToBoard(new Knight(ChessPiece::Color::white), ptKnightStart);
	game.addItemToBoard(new Blocker(), ptBlockerStart);
	game.addItemToBoard(new King(ChessPiece::Color::black), ptKingStart);
	std::cout << "!!!\n";
	std::cout << game.board.toString() << "\n";
	std::cout << "!!!\n";

	// . k . . K . . .
	// . . . # . . . .
	// . . . . . . . .
	// . . . . . . . .
	// . . . . . . . .
	// . . . . . . . .
	// . . . . . . . .
	// . . . . . . . .

	// This section tests if we can set the active chess piece properly
	// It starts by attepmting to set the active piece to 2 illegal positions (both should return false)
	// The (successful) moves we plan to make make:
	// knight to d7 (fail because d7 contains a blocker - return false)
	// knight to a8 (fail because it isn't a valid move - return false)
	// knight to c6 (success - return true)
	// knight to e7 (success - return true)
	// king to e7 (success - king captures knight - return true)

	std::cout << "testing setActiveChessPiece()\n";

	// Test moveActiveChessPiece() 
	std::cout << "\n\ntesting moveActiveChessPiece()\n";
	std::cout << game.board.toString() << "\n";
	
	// set the knight as active
	GameboardItem* pItem = game.board.getItem(ptKnightStart);
	Knight* pKnight = dynamic_cast<Knight*>(pItem);
	game.setActiveChessPiece(pKnight);  

	// ensure knight is where we expect it to be (to start with)
	//Knight* pKnight = dynamic_cast<Knight*>(game.board.getContent(ptKnightStart));
	assert(pKnight && "board expected knight here");
	// ensure starting knight position has 2 valid moves
	assert(pKnight->getValidMoves().size() == 2);

	// ensure king is where we expect it to be (to start with)
	King* pKing = dynamic_cast<King*>(game.board.getItem(ptKingStart));
	assert(pKing && "board expected king here");
	// starting king has 4 valid moves
	assert( pKing->getValidMoves().size() == 4);

	
	std::cout << "attempting invalid move to blocker: knight from: " << ptKnightStart << " to :" << ptBlockerStart << "\n";
	GameboardItem* pInvalidMoveContent = game.board.getItem(ptBlockerStart);
	// ensure the move to a blocker failed
	assert(!game.moveActiveChessPiece(ptBlockerStart));
	// ensure the knight is still where it started
	assert(game.board.getItem(ptKnightStart) == pKnight);
	// ensure the blocker is still where it started
	assert(game.board.getItem(ptBlockerStart) == pInvalidMoveContent);

	Point ptTopLeft(-1, -1);
	std::cout << "attempting invalid move to invalid loc: knight from: " << ptKnightStart << " to " << ptTopLeft  << "\n";
	//pInvalidMoveContent = game.board.getItem(ptTopLeft);
	// ensure the move to an invalid move failed
	assert(!game.moveActiveChessPiece(ptTopLeft));
	// ensure the knight is still where it started
	assert(game.board.getItem(ptKnightStart) == pKnight);
	// ensure the content of the invalid move is still what it started
	//assert(game.board.getItem(ptTopLeft) == pInvalidMoveContent);

	Point ptKnightMove1(2, 2);
//	// knight to c6 (success - return true)
	std::cout << "attempting valid move: knight from: " << ptKnightStart << " to " << ptKnightMove1 << "\n";

	// this move should succeed
	assert(game.moveActiveChessPiece(ptKnightMove1));	

	// ensure knight has vacated starting position
	assert(game.board.getItem(ptKnightStart) == nullptr);
	std::cout << "knight vacated position: " << ptKnightStart << '\n';

//	// ensure knight is now on the board at the position we just moved to.
	assert(game.board.getItem(ptKnightMove1) == pKnight);
	std::cout << "knight is now at: " << ptKnightMove1 << '\n';

	std::cout << game.board.toString() << "\n";

// The board should now be in this state:
//  . . . . K . . .
//  . . . # . . . .
//  . . k . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//
//	// moving knight to right next to king (should succeed - returns true)
//	assert(game.moveActiveChessPiece(crPairKnightMove2));
//
//	// ensure the knight left the position it was in
//	std::cout << "knight vacated position: " << crPairKnightMove1.col << crPairKnightMove1.row << " : " << ptKnightMove1 << '\n';
//	assert(game.board.getContent(ptKnightMove1) == nullptr);
//
//	// ensure the knight is in the new position
//	std::cout << "knight is now at: " << crPairKnightMove2.col << crPairKnightMove2.row << " : " << ptKnightMove2 << '\n';
//	assert(game.board.getContent(ptKnightMove2) == pKnight);
//
//	std::cout << game.board.toString() << "\n";
// 
//	The board should now be in this state:
//  . . . . K . . .
//  . . . # k . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//
//	// Test the king capturing the knight
//	
//	// set the king as the active piece
//	assert(game.setActiveChessPiece(crPairKingStart));
//
//	// move the king to capture the knight
//	assert(game.moveActiveChessPiece(crPairKingMove1));
//
//	// ensure the board's content (where the king moved to), is no longer the knight
//	assert(game.board.getContent(ptKingMove1) != pKnight);
//
//	// ensure the board's content (where the king moved to), is the king
//	assert(game.board.getContent(ptKingMove1) == pKing);
//
//	std::cout << game.board.toString() << "\n";
// 
//	// The board should now be in this state:
//  . . . . . . . .
//  . . . # K . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .
//  . . . . . . . .



	std::cout << "...passed!" << "\n\n";

#else
	std::cout << "ChessGame not tested.\n";
#endif
	return true;
}





