#include "board.h"
#include "tetromino.h"

Board::startGame(){

}

Board::rotateRight(){
    //check if it can be rotated
    //rotate it

}

Board::rotateLeft(){
    //check if it can be rotated
    //rotate it
}

Board::dropPiece(){
    //keep dropping the piece until its pieces can't go any further.
    while(true){
        //check if it can be moved down
        //move it down
    }

}

Board::moveLeft(){
    //check if piece can be moved
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) - 1 < 0){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(tet.getX(i) - 1);
    }

    return true;
}

Board::moveRight(){
    //check if piece can be moved
    for(int i = 0; i < 4; i++){
        if(tet.getX(i) + 1 > (GRID_WIDTH-1) ){
            return false;
        }
    }

    //move the pieces
    for(int i = 0; i < 4; i++){
        tet.setX(tet.getX(i) + 1);
    }

    return true;
}


Board::clearLines(){
    int numRowsCleared = 0;
    int startingRow = -1;
    //for each row
        //for each column
            //check that the whole row is filled (look for a run, or count how many in the row are filled)
            //if it's filled
                //clear the row
                //numRowsCleared++;

    //shift the rows downward
}

Board::holdPiece(){
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
}

Board::nextPiece(){
    //randomly generate the type of the next piece and add to queue.
}

Board::initPiece(){
    //check that the piece's spaces are full. return false if they're not.
    for(int i = 0; i < 4; i++){

    }

    //otherwise set the spaces to the piece's color and mark them as occupied.
}
