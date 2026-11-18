#include "TetrisGame.h"
#include <cmath>
#include <assert.h>


//any point in marking functions const class-params when all params passed in are const?


	// STATIC CONSTANTS
const int TetrisGame::BLOCK_WIDTH{ 32 };			  // pixel width of a tetris block, init to 32
const int TetrisGame::BLOCK_HEIGHT{ 32 };			  // pixel height of a tetris block, int to 32
const double TetrisGame::MAX_SECONDS_PER_TICK{ 0.75 }; // the slowest "tick" rate (in seconds), init to 0.75
const double TetrisGame::MIN_SECONDS_PER_TICK{ 0.2 }; // the fastest "tick" rate (in seconds), init to 0.20
//const Point TetrisGame::gameboardOffset{ Point(55, 126) };


TetrisGame::TetrisGame(sf::RenderWindow& window, sf::Sprite& blockSprite, const Point& gameboardOffset, const Point& nextShapeOffset) :
		window{ window }, blockSprite{ blockSprite }, gameboardOffset{ gameboardOffset }, nextShapeOffset{ nextShapeOffset } {
	//Gameboard board{ Gameboard() };
	//board.setContent(Gameboard::MAX_X / 2, Gameboard::MAX_Y / 2, 1);
	//currentShape.setShape();
	//Point spawn_loc = board.getSpawnLoc();
	//currentShape.setGridLoc(spawn_loc);
	reset();
} // do i mark as const if initialized in initialization list and not modified after?


void TetrisGame::draw(){
	drawGameboard();
	drawTetromino(currentShape, gameboardOffset);
	drawTetromino(nextShape, nextShapeOffset);
	window.draw(scoreText);
}

// Event and game loop processing
// handles keypress events (up, left, right, down, space)
// - param 1: sf::Event event
// - return: nothing
void TetrisGame::onKeyPressed(const sf::Event& event){
	switch (event.key.code) {
		case sf::Keyboard::Up:
			attemptRotate(currentShape);
			break;
		case sf::Keyboard::Right:
			attemptMove(currentShape, 1, 0);
			break;
		case sf::Keyboard::Left:
			attemptMove(currentShape, -1, 0);
			break;
		case sf::Keyboard::Down:
			if (!attemptMove(currentShape, 0, 1)) {
				lock(currentShape);
			}
			break;
		case sf::Keyboard::Space:
			drop(currentShape);
			lock(currentShape);
	}
	//else if (event.KeyPressed == sf::Keyboard:: )

}

// called every game loop to handle ticks & tetromino placement (locking
// - param 1: float secondsSinceLastLoop
// return: nothing
void TetrisGame::processGameLoop(float secondsSinceLastLoop) {
	secondsSinceLastTick += secondsSinceLastLoop;
	if (secondsSinceLastTick >= secondsPerTick) {
		//std::cout << secondsSinceLastLoop << "   ";
		tick(); 
		secondsSinceLastTick -= secondsPerTick;
	}
	if (shapePlacedSinceLastGameLoop) {
		shapePlacedSinceLastGameLoop = false;
		if (spawnNextShape()) {
			pickNextShape();
			int remove_ct = board.removeCompletedRows();
			total_rows_removed += remove_ct;
			score += std::round( std::pow( 1 / (secondsPerTick), remove_ct ));
			determineSecondsPerTick();
}
		else {
			std::cout << "Game over!\nscore: " << score <<"\n";
			reset();
		}
	}
}

// A tick() forces the currentShape to move (if there were no tick,
// the currentShape would float in position forever). This should
// call attemptMove() on the currentShape.  If not successful, lock() 
// the currentShape (it can move no further).
// - params: none
// - return: nothing
void TetrisGame::tick(){
	if (!attemptMove(currentShape, 0, 1)) {
		lock(currentShape);
	}
}

// reset everything for a new game (use existing functions) 
//  - set the score to 0 and call updateScoreDisplay()
//  - call determineSecondsPerTick() to determine the tick rate.
//  - clear the gameboard,
//  - pick & spawn next shape
//  - pick next shape again (for the "on-deck" shape)
// - params: none
// - return: nothing
void TetrisGame::reset(){
	score = 0;
	updateScoreDisplay();
	determineSecondsPerTick();
	board.empty();
	pickNextShape();
	spawnNextShape();
	pickNextShape();
}

// assign nextShape.setShape a new random shape  
// - params: none
// - return: nothing
void TetrisGame::pickNextShape(){
	nextShape.setShape(Tetromino::getRandomShape());
}

// copy the nextShape into the currentShape (through assignment)
//   position the currentShape to its spawn location.
// - params: none
// - return: bool, true/false based on isPositionLegal()
bool TetrisGame::spawnNextShape() {
	//board.setContent(Gameboard::MAX_X / 2, Gameboard::MAX_Y / 2, 1);
//currentShape.setShape();
//currentShape.setGridLoc(spawn_loc);
	//reset();

	Point spawn_loc = board.getSpawnLoc();
	GridTetromino temp{ nextShape };
	temp.setGridLoc(spawn_loc);
	if (isPositionLegal(temp)) {
		currentShape = temp;
		return true;
	}
	else {
		return false;
	}
}

bool TetrisGame::attemptRotate(GridTetromino& shape) { 
	GridTetromino temp{ shape };
	temp.rotateClockwise();

	if (isPositionLegal(temp)) {
		shape = temp;
		return true;
	}
	else {
		return false;
	}
}

bool TetrisGame::attemptMove(GridTetromino& shape, int x, int y) {
	GridTetromino temp{ shape };
	temp.move(x, y);

	if (isPositionLegal(temp)) {
		shape = temp;
		return true;
	}
	else {
		return false;
	}
}

void TetrisGame::drop(GridTetromino& shape) {
	while (attemptMove(shape, 0, 1)) {}
}

// copy the contents (color) of the tetromino's mapped block locs to the grid.
	//	 1) get the tetromino's mapped locs via tetromino.getBlockLocsMappedToGrid()
	//   2) use the board's setContent() method to set the content at the mapped locations.
	//   3) record the fact that we placed a shape by setting shapePlacedSinceLastGameLoop
	//      to true
	// - param 1: GridTetromino shape
	// - return: nothing
void TetrisGame::lock(GridTetromino& shape){
	auto newBlocks = shape.getBlockLocsMappedToGrid();
	for (int i = 0; i < newBlocks.size(); i++) {
		board.setContent(newBlocks, static_cast<int>(shape.getColor()));
	}
	shapePlacedSinceLastGameLoop = true;
} // ? modified gridtet or no?

// Graphics methods ==============================================

void TetrisGame::drawBlock(const Point& topLeft, int xOffset, int yOffset, const TetColor color){
		
	topLeft; //  of gameboard (in pixels
	int initSpriteX{};
	int initSpriteY{};

	int spriteStartY{ initSpriteY };
	int spriteEndY{ spriteStartY + BLOCK_HEIGHT };

	int sprite_position{};
		
	//requires the enum order matches the order of sprites in the file
	int spriteStartX{ initSpriteX + (static_cast<int>(color) * BLOCK_WIDTH) };
	//int spriteWidth{ spriteStartX + BLOCK_HEIGHT };
	int spriteWidth{ BLOCK_WIDTH };
	blockSprite.setTextureRect(  sf::IntRect({ spriteStartX, spriteStartY }, { spriteWidth, spriteEndY }) );

	blockSprite.setPosition(topLeft.getX() + xOffset * BLOCK_WIDTH, topLeft.getY() + yOffset * BLOCK_HEIGHT);
	window.draw( blockSprite );
}

void TetrisGame::drawGameboard(){
	for (int y = 0; y < Gameboard::MAX_Y; y++) {
		drawGameboardRow(y);
	}  
}

void TetrisGame::drawGameboardRow(int y) {
	for (int x = 0; x < Gameboard::MAX_X; x++) {
		int block{ board.getContent(x, y) };
		if (block != Gameboard::EMPTY_BLOCK ) {
			drawBlock(gameboardOffset, x, y, static_cast<TetColor>(block));
		}
	}
}

// Draw a tetromino on the window
//	 Iterate through each mapped loc & drawBlock() for each.
//   The topLeft determines a 'base point' from which to calculate block offsets
//      If the Tetromino is on the gameboard: use gameboardOffset
// param 1: GridTetromino tetromino
// param 2: Point topLeft
// return: nothing
void TetrisGame::drawTetromino(const GridTetromino& tetromino, const Point& topLeft){
	//tetromino.getBlockLocs();
	std::vector<Point> blocks{ tetromino.getBlockLocsMappedToGrid() };

	for (int i = 0; i < blocks.size(); i++) {
		Point block = blocks[i];
		drawBlock(topLeft, block.getX(), block.getY(), tetromino.getColor());
	}
}

// update the score display
// form a string "score: ##" to display the current score
// user scoreText.setString() to display it.
// params: none:
// return: nothing
void TetrisGame::updateScoreDisplay(){
	std::stringstream scoretext{};
	scoretext << "Score: " << score;
	scoreText.setString( scoretext.str() );
}

// State & gameplay/logic methods ================================

bool TetrisGame::isPositionLegal(GridTetromino& shape) const {
	if (!isWithinBorders(shape)) {
		return false;
	}
	if (board.areAllLocsEmpty(shape.getBlockLocsMappedToGrid())) {
		return true;
	}
	else {
		return false;
	}
}

bool TetrisGame::isWithinBorders(GridTetromino& shape) const {
	std::vector<Point> shapes{ shape.getBlockLocsMappedToGrid() };
	for (int i = 0; i < shapes.size(); i++) {
		if (shapes[i].getX() >= Gameboard::MAX_X || shapes[i].getX() < 0) {
			return false;
		}
		if (shapes[i].getY() >= Gameboard::MAX_Y ) {
			return false;
		}
	}
	return true; }


// set secsPerTick 
//   - basic: use MAX_SECS_PER_TICK
//   - advanced: base it on score (higher score results in lower secsPerTick)
// params: none
// return: nothing
void TetrisGame::determineSecondsPerTick(){}