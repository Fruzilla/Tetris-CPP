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
    static const int GRID_WIDTH = 10;
    static const int GRID_HEIGHT = 24;

    Piece grid[GRID_WIDTH][GRID_HEIGHT];             //the grid
    Tetromino tet;                //the current piece
    int score;                      //points for putting down a piece and for clearing lines
    int lines_cleared;              //track lines cleared, use to determine speed
    int level;                      //or use size_t (can't be negative)
    int item_id;                    //if there's an item, store its id. 0 if none (or negative), then different ints for each item
    Tetromino held_piece;           //held piece (use either a tetronimo class, or an int)
    QQueue<Tetronimo> shape_queue;  //Queue for upcoming pieces (either use Piece class or ints). Size of 6.
    bool swap_hold;                 //keep track of whether a piece was swapped with the held
    bool pieceInPlay;               //track whether a piece is currently in play
    //limit the number of ratations

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

#endif // BOARD_H
