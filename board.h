#ifndef BOARD_H
#define BOARD_H

//imports
#include "piece.h"
#include "tetromino.h"
#include "queue.h"

//main class definition
class Board{
public:
    //public variables

    //public functions



private:
    //private variables
    static const int GRID_WIDTH = 10; //might adjust grid size to create an extra "dead zone" at the top
    static const int GRID_HEIGHT = 24;

    Piece grid[GRID_WIDTH][GRID_HEIGHT];             //the grid
    Tetromino tet;					//the current piece (pointer to the piece that's head of the queue/list)
    int score;                      //points for putting down a piece and for clearing lines
    int lines_cleared;              //track lines cleared, use to determine speed?
	int speed;						//the pace of the game "pulses"
    int level;                      //or use size_t (can't be negative)
    int item_id;                    //if there's an item, store its id. 0 if none (or negative), then different ints for each item
    Tetromino held_piece;           //held piece (use either a tetronimo class, or an int)
    Queue<int> shape_queue;			//Queue for upcoming pieces (either use Piece class or ints). Size of 6.
    bool swap_hold;                 //keep track of whether a piece was swapped with the held
    bool pieceInPlay;               //track whether a tetronimo piece is currently in play
	int gameMode;					//current play mode	
    //limit the number of rotations?

    //private functions
    void startGame();               //initialize the pieces, score, level
    bool rotateRight();
    bool rotateLeft();
    void dropPiece();
    bool moveLeft();                //on key event
    bool moveRight();
    int clearLines();               //check for full rows
    void holdPiece();
    void nextPiece();               //get piece from queue and set it to current piece; refill queue.
    bool initPiece();               //give the piece its default position and color, if possible.

    //Graphics
    void drawBoard();
};

/* Functions for:
 * - Advancing the piece
 * - Create piece(?)
 * - Drop piece to bottom
 * - Move piece
 * - Rotating pieces left/right
 * - Clearing lines
 * - Swap pieces w/ held
 *
 *
 * Graphics:
 * - Draw field
 *
 *
 *
 */





/* Need variables for:
 * - Grid (playing field)
 * - Score
 * - Held piece
 * - Current piece(?)
 * - Queue of upcoming pieces
 * - Item
 * - Level/Speed (have speed managed by the main program [use either an array or a calculation for speed])
 * - Lines cleared
 * - Difficulty/starting difficulty?
 *
 *  Others can be stored in the main (ie. using items)
 */


/*
GAME OUTLINE:

Initialize board (and all pieces)

Create tetronimos (for the queue and the first piece) *Pointer to first in queue = player piece

Initialize the held piece(?)

Move the player piece down according to the board's speed

Check for rotation and player input

Once it hits the bottom, lock it. 

Destroy the piece (pop the queue), set the player piece equal to the next in the queue, and initialize it.

Repeat until the initializing piece fails (can't place a tetronimo at its default location)






*/

#endif // BOARD_H
