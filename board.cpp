#include "board.h"
#include "tetromino.h"

//TODO: Finish implementing functions

void Board::startGame(){

}

bool Board::rotateRight(){
    //check if it can be rotated
    //rotate it

	return true; //temp
}

bool Board::rotateLeft(){
    //check if it can be rotated
    //rotate it

	return true; //temp
}

void Board::dropPiece(){
    //keep dropping the piece until its pieces can't go any further.
    while(true){
        //check if it can be moved down
        //move it down
    }

}

bool Board::moveLeft(){
    //check if piece can be moved
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) - 1 < 0){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(i, tet.getX(i) - 1);
    }

    return true;
}

bool Board::moveRight(){
    //check if piece can be moved
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) + 1 > (GRID_WIDTH-1) ){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(i, tet.getX(i) + 1);
    }

    return true;
}


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
        if(held_piece == NULL){ //no piece being held
            held_piece = tet;
            for(int i = 0; i < 4; i++){
                held_piece.setCoords(i, -1, -1);
            }
            //clear pieces if they weren't already?
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

void Board::nextPiece(){
    //randomly generate the type of the next piece and add to queue.
}

bool Board::initPiece(){
    //check that the piece's spaces are full. return false if they're not, ending the game.
    for(int i = 0; i < 4; i++){

    }

    //otherwise set the spaces to the piece's color and mark them as occupied.

	return true; //temp
}
