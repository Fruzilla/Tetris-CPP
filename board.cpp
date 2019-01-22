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
	timesRotated = 0;
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

bool Board::rotateRight(){
	//gather coordinates
	int coords[4][2];
	for (int i = 0; i < 4; i++) {
		coords[i][0] = rotateXRight(i);
		coords[i][1] = rotateYRight(i);
	}

	//check for out of bounds coordinates and attempt to wallkick (move coordinates back in range)
	for (int i = 0; i < 4; i++) {
		if (coords[i][0] < 0) {	//left side out of bounds
			int t = coords[i][0];
			for (int j = 0; j < 4; j++) {
				coords[j][0] += (t * -1);
			}
		}
		else if (coords[i][0] > GRID_WIDTH-1) {	//right side out of bounds
			int t = coords[i][0];
			for (int j = 0; j < 4; j++) {
				coords[j][0] -= (t - 9);
			}
		}
		if (coords[i][1] < 0) {	//top out of bounds
			int t = coords[i][1];
			for (int j = 0; j < 4; j++) {
				coords[j][1] += (t * -1);
			}
		}
		else if (coords[i][1] > GRID_HEIGHT-1) {	//bottom out of bounds
			int t = coords[i][1];
			for (int j = 0; j < 4; j++) {
				coords[j][0] -= (t - 23);
			}
		}
	}

	//check if the new coordinates are occupied. if they are, return false.
	for (int i = 0; i < 4; i++) {
		if (grid[coords[i][0]][coords[i][1]].getIsSet()) {
			return false;
		}
	}

    //set the coordinates
	for (int i = 0; i < 4; i++) {
		tet.setCoords(i, coords[i][0], coords[i][1]);
	}
	timesRotated++;
	return true;
}

bool Board::rotateLeft() {
	//gather coordinates
	int coords[4][2];
	for (int i = 0; i < 4; i++) {
		coords[i][0] = rotateXLeft(i);
		coords[i][1] = rotateYLeft(i);
	}

	//check for out of bounds coordinates and attempt to wallkick (move coordinates back in range)
	for (int i = 0; i < 4; i++) {	
		if (coords[i][0] < 0) {		//out of bounds (left side)
			int t = coords[i][0];
			for (int j = 0; j < 4; j++) {
				coords[j][0] += (t * -1);
			}
		}
		else if (coords[i][0] > GRID_WIDTH - 1) { //out of bounds (right side)
			int t = coords[i][0];
			for (int j = 0; j < 4; j++) {
				coords[j][0] -= (t - 9);
			}
		}
		if (coords[i][1] < 0) {	//out of bounds (top)
			int t = coords[i][1];
			for (int j = 0; j < 4; j++) {
				coords[j][1] += (t * -1);
			}
		}
		else if (coords[i][1] > GRID_HEIGHT - 1) { //out of bounds (bottom)
			int t = coords[i][1];
			for (int j = 0; j < 4; j++) {
				coords[j][0] -= (t - 23);
			}
		}
	}

	//check if the new coordinates are occupied. if they are, return false.
	for (int i = 0; i < 4; i++) {
		if (grid[coords[i][0]][coords[i][1]].getIsSet()) {
			return false;
		}
	}

	//set the coordinates
	for (int i = 0; i < 4; i++) {
		tet.setCoords(i, coords[i][0], coords[i][1]);
	}
	timesRotated++;
	return true;
}

//x' = (y + px - py) (pivot point is third piece)
int Board::rotateXLeft(int i) {
	return (tet.getY(i) + tet.getX(2) - tet.getY(2));
}

//y' = (px + py - x)
int Board::rotateYLeft(int i) {
	return (tet.getX(2) + tet.getY(2) - tet.getX(i));
}

//x' = (px + py - y)
int Board::rotateXRight(int i) {
	return (tet.getX(2) + tet.getY(2) - tet.getY(i));
}

//y' = (x + py + px)
int Board::rotateYRight(int i) {
	return (tet.getX(i) + tet.getY(2) - tet.getX(2));
}

//TODO: Finish implementing function
void Board::dropPiece(){
    //keep dropping the piece until its pieces can't go any further.
	Tetromino temp = tet;
    while(true){
        //check if it can be moved down
		bool canMove = true;
        //move it down
		for (int i = 0; i < 4; i++) {
			if (tet.getY(i) + 1 > (GRID_HEIGHT - 1) || grid[tet.getX(i)][tet.getY(i) + 1].is_set) {
				canMove = false;
			}
		}
		if (canMove) {	//if the pieces below
			for (int i = 0; i < 4; i++) {
				tet.setY(i, tet.getY(i) + 1);
			}
		}
		else { //if it's at the final position, color in the piece. reset the colors at its previous position (before dropping)

		}
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

bool Board::moveDown() {
	//check if piece can be moved. return false if out of bounds or piece is occupied
	for (int i = 0; i < 4; i++) {
		if (tet.getY(i) + 1 >(GRID_HEIGHT - 1) || grid[tet.getX(i)][tet.getY(i) + 1].is_set) {
			return false;
		}
	}

	//move the pieces
	for (int i = 0; i < 4; i++) {
		tet.setY(i, tet.getY(i) + 1);
		//change the new position's color
		//reset the old piece
	}

	return true;
}

bool Board::moveUp() {
	//check if piece can be moved. return false if out of bounds or piece is occupied
	for (int i = 0; i < 4; i++) {
		if (tet.getY(i) - 1 > 0 || grid[tet.getX(i)][tet.getY(i) - 1].is_set) {
			return false;
		}
	}

	//move the pieces
	for (int i = 0; i < 4; i++) {
		tet.setY(i, tet.getY(i) - 1);
		//change the new position's color
		//reset the old piece
	}

	return true;
}

//TODO: Finish implementing function
//should be called by main program. set piece, clear lines, then next piece.
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
		temp.setColorSolid(tet.getColor());
	}

	swap_hold = false;
	//nextPiece();	//TODO: have main program call this instead
}

void Board::pulse() {
	//if the piece can move down, move down
	if (!moveDown()) {
		//if rotated (check rotation limit) don't lock it
		//if not rotated lock and next piece
	}
	else if (timesRotated > 0) {
		timesRotated = 0;
		return;
	}
	else {
		setPiece();
	}

	//if it can't move down, if the piece hasn't rotated, lock it.

}

//DEBUG FUNCTION
Queue Board::getQueue() {
	return shape_queue;
}

//DEBUG FUNCTION
Tetromino& Board::getCurrentPiece() {
	return tet;
}

//DEBUG FUNCTION
Tetromino Board::getHeldPiece() {
	return held_piece;
}

//DEBUG FUNCTION
void Board::setPieceType(int i) {
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

//DEBUG FUNCTION
void Board::setGridPiece(int x, int y) {
	grid[x][y].setColorSolid(Color::Magenta);
}

//DEBUG FUNCTION
Piece Board::getGridPiece(int x, int y) {
	return grid[x][y];
}