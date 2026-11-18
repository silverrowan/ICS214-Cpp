#include "GridTetromino.h"
#include "Gameboard.h"
#include "TetrisGame.h"
#include <assert.h>

void GridTetromino::move(int xOffset, int yOffset) {
	Point position = getGridLoc();
	Point newPosition{ position.getX() + xOffset, position.getY() + yOffset };
	// how would assert is valid point? all the offset range info is in gameboard; but the check
	// functions are not
	//assert(TetrisGame::getBoard().
		//.get.isValidPoint(newPosition));
	position.setXY(newPosition.getX(), newPosition.getY());
	setGridLoc(position);
}

const std::vector<Point> GridTetromino::getBlockLocsMappedToGrid() const {
	Point newCenter = getGridLoc();
	//same q how assert valid pt

	std::vector<Point> tet_blocks = getBlockLocs();
	for (int i = 0; i < static_cast<int>(tet_blocks.size()); i++) {
		tet_blocks[i].setX(tet_blocks[i].getX() + newCenter.getX());
		tet_blocks[i].setY(tet_blocks[i].getY() + newCenter.getY());
	}
	return tet_blocks;
}