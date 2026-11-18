#include "TetrisGame.h"
#include <cmath>
#include <assert.h>

//any point in marking functions const class-params when all params passed in are const?

// STATIC CONSTANTS
const int TetrisGame::BLOCK_WIDTH{ 32 };			  // pixel width of a tetris block, init to 32
const int TetrisGame::BLOCK_HEIGHT{ 32 };			  // pixel height of a tetris block, int to 32
const double TetrisGame::MAX_SECONDS_PER_TICK{ 0.75 }; // the slowest "tick" rate (in seconds), init to 0.75
const double TetrisGame::MIN_SECONDS_PER_TICK{ 0.2 }; // the fastest "tick" rate (in seconds), init to 0.20

TetrisGame::TetrisGame(sf::RenderWindow& window, sf::Sprite& blockSprite, const Point& gameboardOffset, const Point& nextShapeOffset) :
		window{ window }, blockSprite{ blockSprite }, gameboardOffset{ gameboardOffset }, nextShapeOffset{ nextShapeOffset } {
	if (!scoreFont.loadFromFile("fonts/RedOctober.ttf"))
	{
		assert(false && "Missing font: RedOctover.ttf");
	};
	scoreText.setFont(scoreFont);
	scoreText.setCharacterSize(18);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(425, 325);

	reset();
} // do i mark as const if initialized in initialization list and not modified after?

void TetrisGame::draw(){
	drawGameboard();
	drawTetromino(currentShape, gameboardOffset);
	drawTetromino(nextShape, nextShapeOffset);
	updateScoreDisplay();
	window.draw(scoreText); //why is this different than the draw we've been using so far?
}

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
}

void TetrisGame::processGameLoop(float secondsSinceLastLoop) {
	secondsSinceLastTick += secondsSinceLastLoop;
	if (secondsSinceLastTick >= secondsPerTick) {
		tick(); 
		secondsSinceLastTick -= secondsPerTick;
	}
	if (shapePlacedSinceLastGameLoop) {
		shapePlacedSinceLastGameLoop = false;
		if (spawnNextShape()) {
			pickNextShape();
			int remove_ct = board.removeCompletedRows();
			calculateScore(remove_ct);
			total_rows_removed += remove_ct;
			//score += std::round( std::pow( 1 / (secondsPerTick), remove_ct ));
			determineSecondsPerTick();
		}
		else {
			std::cout << "Game over!\nscore: " << score <<"\n";
			reset();
		}
	}
}

void TetrisGame::tick(){
	if (!attemptMove(currentShape, 0, 1)) {
		lock(currentShape);
	}
}

void TetrisGame::reset(){
	score = 0;
	updateScoreDisplay();
	determineSecondsPerTick();
	board.empty();
	pickNextShape();
	spawnNextShape();
	pickNextShape();
}

void TetrisGame::pickNextShape(){
	nextShape.setShape(Tetromino::getRandomShape());
}

bool TetrisGame::spawnNextShape() {
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

void TetrisGame::lock(GridTetromino& shape){
	auto newBlocks = shape.getBlockLocsMappedToGrid();
	for (int i = 0; i < newBlocks.size(); i++) {
		board.setContent(newBlocks, static_cast<int>(shape.getColor()));
	}
	shapePlacedSinceLastGameLoop = true;
}

// Graphics methods ==============================================

void TetrisGame::drawBlock(const Point& topLeft, int xOffset, int yOffset, const TetColor color) const {
	topLeft;
	int initSpriteX{};
	int initSpriteY{};

	int spriteStartY{ initSpriteY };
	int spriteEndY{ spriteStartY + BLOCK_HEIGHT };

	int sprite_position{};
		
	//requires the enum order matches the order of sprites in the file
	int spriteStartX{ initSpriteX + (static_cast<int>(color) * BLOCK_WIDTH) };
	int spriteWidth{ BLOCK_WIDTH };
	blockSprite.setTextureRect(  sf::IntRect({ spriteStartX, spriteStartY }, { spriteWidth, spriteEndY }) );

	blockSprite.setPosition(topLeft.getX() + xOffset * BLOCK_WIDTH, topLeft.getY() + yOffset * BLOCK_HEIGHT);
	window.draw( blockSprite );
}

void TetrisGame::drawGameboard() const {
	for (int y = 0; y < Gameboard::MAX_Y; y++) {
		drawGameboardRow(y);
	}  
}

void TetrisGame::drawGameboardRow(int y) const {
	for (int x = 0; x < Gameboard::MAX_X; x++) {
		int block{ board.getContent(x, y) };
		if (block != Gameboard::EMPTY_BLOCK ) {
			drawBlock(gameboardOffset, x, y, static_cast<TetColor>(block));
		}
	}
}

void TetrisGame::drawTetromino(const GridTetromino& tetromino, const Point& topLeft) const {
	std::vector<Point> blocks{ tetromino.getBlockLocsMappedToGrid() };

	for (int i = 0; i < blocks.size(); i++) {
		Point block = blocks[i];
		drawBlock(topLeft, block.getX(), block.getY(), tetromino.getColor());
	}
}

void TetrisGame::updateScoreDisplay(){
	std::stringstream scoreTextBuild{};
	scoreTextBuild << "Score: " << score;
	scoreText.setString(scoreTextBuild.str() );
}

// State & gameplay/logic methods ================================

void TetrisGame::calculateScore(int rows_removed) {
	if (rows_removed) {
		score += std::round((1 / secondsPerTick) * rows_removed * rows_removed);
	}
}

bool TetrisGame::isPositionLegal(const GridTetromino& shape) const {
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

bool TetrisGame::isWithinBorders(const GridTetromino& shape) const {
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