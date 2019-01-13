#include "board.h"
#include "tetromino.h"
#include "piece.h"
#include <stdlib.h>
#include <math.h>

Board::Board() {
	Tetromino tet = NULL;
	score = 0;                      //points for putting down a piece and for clearing lines
	lines_cleared = 0;              //track lines cleared, use to determine speed?
	speed = 0;						//the pace of the game "pulses"
	level = 0;                      //or use size_t (can't be negative)
	item_id = 0;                    //if there's an item, store its id. 0 if none (or negative), then different ints for each item
	Tetromino held_piece = NULL;    //held piece (use either a tetronimo class, or an int)
	shape_queue = Queue();			//Queue for upcoming pieces (either use Piece class or ints). Size of 6.
	swap_hold = false;              //keep track of whether a piece was swapped with the held
	pieceInPlay = false;            //track whether a tetronimo piece is currently in play
	gameMode = 0;					//current play mode: 0 is menu, 1 is basic, 2 is item, 3 is 2-player basic, 4 is 2-player item
}

//NOTE: srand should only be called once; can be problematic if 2 player is implemented. call srand in main and generate within the board
void Board::startGame(){
	//fill the queue
	for (int i = 0; i < 6; i++) {
		int r = rand() % 7; //0 to 6
		Tetromino temp = Tetromino(r);
		shape_queue.add(temp);
	}

	//set starting piece
	tet = Tetromino(rand() % 7);

	//depending on game mode and options, may need to change other variables like level and speed
}

//TODO: Finish implementing function
bool Board::rotateRight(){
    //check if it can be rotated
	for (int i = 0; i < 4; i++) {
		int new_x = rotateXRight(i);
		int new_y = rotateYRight(i);
		//if the new position is occupied or oob
			//return false
		//else do nothing
		if (new_x > 9 || new_x < 0 || new_y < 0 || new_y > 23 || grid[new_x][new_y].getIsSet()) {
			return false;
		}
	}
    //rotate it
	for (int i = 0; i < 4; i++) {
		int new_x = rotateXRight(i);
		int new_y = rotateYRight(i);
		tet.setCoords(i, new_x, new_y);
	}

	return true; //temp
}

//TODO: Finish implementing function
bool Board::rotateLeft() {
	//check if it can be rotated
	for (int i = 0; i < 4; i++) {
		int new_x = rotateXLeft(i);
		int new_y = rotateYLeft(i);
		//if the new position is occupied or oob
		//return false
		//else do nothing
		if (new_x > 9 || new_x < 0 || new_y < 0 || new_y > 23 || grid[new_x][new_y].getIsSet()) {
			cout << "\nRotation Failed\n"; //DEBUG
			return false;
		}
	}
	//rotate it
	for (int i = 0; i < 4; i++) {
		int new_x = rotateXLeft(i);
		int new_y = rotateYLeft(i);
		tet.setCoords(i, new_x, new_y);
	}

	return true; //temp
}

int Board::rotateXLeft(int i) {
	return int(tet.getX(i) * cos(atan(1)*4/2) - tet.getY(i) * sin(atan(1) * 4 /2));
}

int Board::rotateYLeft(int i) {
	return int(tet.getX(i) * sin(atan(1) * 4 /2) + tet.getY(i) * cos(atan(1) * 4 /2));
}

//x' = x * cos(PI/2) - y * sin(PI/2) and y' = x * sin(PI / 2) + y * cos(PI / 2) .
//NVM THIS IS FOR LEFT ROTATION. try reversing cos and sin for each?
int Board::rotateXRight(int i) {
	return int(tet.getX(i) * cos((atan(1) * 4) / 2) + tet.getY(i) * sin(atan(1) * 4 / 2));
}

int Board::rotateYRight(int i) {
	return int(tet.getX(i) * sin((atan(1) * 4) / 2) - tet.getY(i) * cos(atan(1) * 4 / 2));
}

//TODO: Finish implementing function
void Board::dropPiece(){
    //keep dropping the piece until its pieces can't go any further.
    while(true){
        //check if it can be moved down
        //move it down
    }
	//set the piece
}

bool Board::moveLeft(){
    //check if piece can be moved. return false if out of bounds or piece is occupied
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) - 1 < 0 || grid[tet.getX(i)-1][tet.getY(i)].is_set){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(i, tet.getX(i) - 1);
		//change the new position's color
		//remove the old position's color
    }

    return true;
}

bool Board::moveRight(){
    //check if piece can be moved. return false if out of bounds or piece is occupied
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) + 1 > (GRID_WIDTH-1) || grid[tet.getX(i)+1][tet.getY(i)].is_set ){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(i, tet.getX(i) + 1);
		//change the new position's color
		//reset the old piece
    }

    return true;
}

//TODO: Finish implementing function
int Board::clearLines(){
    int numRowsCleared = 0;
    int startingRow = -1;
    //for each row
        //for each column
            //check that the whole row is filled (look for a run, or count how many in the row are filled)
            //if it's filled
                //clear the row
                //numRowsCleared++;

    //shift the rows downward
	return numRowsCleared;
}

void Board::holdPiece(){
    //swap out the existing piece with the held piece, if any.
    //if swap_hold == false
    //if no piece is being held
        //held_piece = tet;
        //change its coordinates
        //make sure the spaces the piece were in are cleared
        //swap_hold = true;
    //else
        //temp = held_piece;
        //held_piece = tet;
        //tet = temp;
        //re-init the piece.
        //swap_hold = true;
    if(swap_hold == false){
        if(!has_held_piece){ //no piece being held
            held_piece = tet;
            for(int i = 0; i < 4; i++){
                held_piece.setCoords(i, -1, -1);
            }
            //clear pieces if they weren't already?
			nextPiece();
			has_held_piece = true;
        }

        else{   //piece being held; need to swap
            Tetromino temp = held_piece;
            held_piece = tet;
            tet = temp;
            //change piece coordinates
            for(int i = 0; i < 4; i++){
                held_piece.setCoords(i, -1, -1);
                tet.setCoords(i, tet.starting_coords[tet.getType()][i][0], tet.starting_coords[tet.getType()][i][1]);
            }
            //handle items?
        }
    }
    swap_hold = true;
}

//get piece from queue and set it to current piece; refill queue.
void Board::nextPiece(){
	tet = shape_queue.pop();

    //randomly generate the type of the next piece and add to queue.
	int r = rand() % 7; //0 to 6
	Tetromino temp = Tetromino(r);
	shape_queue.add(temp);
}

//TODO: Finish implementing function. Not needed?
bool Board::initPiece(){
    //check that the piece's spaces are full. return false if they're not, ending the game.
	//scratch that. the pulse function should handle the game being over. this should display the tetromino over the occupied piece.

	return true; //temp
}

void Board::setPiece() {
	//change coordinates of the grid and color
	for (int i = 0; i < 4; i++) {
		Piece& temp = grid[tet.getX(i)][tet.getY(i)];
		temp.setColor(tet.getColor());
	}

	swap_hold = false;
	nextPiece();
}

//DEBUG FUNCTION
Queue Board::getQueue() {
	return shape_queue;
}

//DEBUG FUNCTION
Tetromino Board::getCurrentPiece() {
	return tet;
}

//DEBUG FUNCTION
Tetromino Board::getHeldPiece() {
	return held_piece;
}

//DEBUG FUNCTION
void Board::setPiece(int i) {
	tet = Tetromino(i);
}

//DEBUG FUNCTION
int Board::testRotateXLeft(int i) {
	return rotateXLeft(i);
}

//DEBUG FUNCTION
int Board::testRotateYLeft(int i) {
	return rotateYLeft(i);
}

//DEBUG FUNCTION
int Board::testRotateXRight(int i) {
	return rotateXRight(i);
}

//DEBUG FUNCTION
int Board::testRotateYRight(int i) {
	return rotateYRight(i);
}