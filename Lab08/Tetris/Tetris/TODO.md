Point

Tetromino

LAB 7 : Gameboard
- [x] setters should check validity / ADD ASSERTS TO FUNCTIONS AS NEEDED
	- [x] completed from top to last func()
- [x] check for constant, reference etc (best practice passing)
- [x] check Gameboard::MAX_ y & x use correct <,>,= - max is INDEX not count
	- [x] only isRowCompleted(), fillRow(), removeRow() checked
	- [x] reverse this, apparently the MAX is meant to be a size
- [x] test
- [x] printToConsole();
- [x] areAllLocsEmpty();
- [x] removeCompletedRows();
- [x] getCompletedRowIndices();
- [x] copyRowIntoRow();
- [x] removeRow();
- [x] removeRows();

Lab 08:

- [x] seed randomizer (for Tetromino::getRandomShape, in main ln 38)
- [x] comments:
	- [x]Gameboard::getSpawnLoc()
	- [x] gameboard??? fill row helper funct
- [x] re-comment gameboard 'private' functions - breaks testing until added 'friend'
- [x] check each header for complete comments - each function and variable
	- [x] Gameboard
	- [x] GridTetromino
	- [x] Point
	- [x] TetrisGame
	- [x] Tetromino
- [x] check each function for const/ref/etc
	- [x] Gameboard
	- [x] GridTetromino
	- [x] Point
	- [x] TetrisGame
	- [x] Tetromino
- [x] check all asserts needed are present
	- [x] Gameboard
	- [x] GridTetromino
	- [x] Point
	- [x] TetrisGame
	- [x] Tetromino