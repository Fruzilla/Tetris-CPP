#include "tetromino.h"

Tetromino::Tetromino(){
	shape_type = 0;
	shape_color = colors[shape_type];
	has_item = false;
	item_piece = -1;
	reset_piece();
}

Tetromino::Tetromino(int type){
    shape_type = type;
	shape_color = colors[type];
	reset_piece();
    has_item = false;
    item_piece = -1;
}

Tetromino::Tetromino(int type, Color color){
    shape_type = type;
    shape_color = color;
	reset_piece();
    has_item = false;
    item_piece = -1;
}

Tetromino::Tetromino(int type, int piece_id){
    shape_type = type;
    shape_color = colors[type];
	reset_piece();
    item_piece = piece_id;
	has_item = true;
}

Tetromino::Tetromino(int type, Color color, int piece_id){
    shape_type = type;
    shape_color = color;
	reset_piece();
    item_piece = piece_id;
	has_item = true;
}

Tetromino::Tetromino(int type, Color color, int piece_id, int item_id) {
	shape_type = type;
	shape_color = color;
	reset_piece();
	item_piece = piece_id;
	item_type = item_id;
	has_item = true;
}

Tetromino::Tetromino(int type, int piece_id, int item_id) {
	shape_type = type;
	reset_piece();
	item_piece = piece_id;
	item_type = item_id;
	has_item = true;
}

void Tetromino::reset_piece(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[shape_type][i][j];
        }
    }
}

Tetromino& Tetromino::operator =(Tetromino& t) {	
	//copy coords
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			this->piece_coords[i][j] = t.piece_coords[i][j];
		}
	}
	//copy color
	this->setColor(t.getColor() );
	//copy type
	this->setType(t.getType() );
	//copy items
	this->item_piece = t.item_piece;
	this->item_type = t.item_type;

	return *this;
}

bool Tetromino::operator ==(Tetromino& t) {
	//check if null
	if (&t == NULL) {
		return false;
	}

	//check type
	else if (this->shape_type != t.shape_type) {
		return false;
	}

	//check color
	else if (this->shape_color != t.shape_color) {
		return false;
	}

	//check coords
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			if (this->piece_coords[i][j] != t.piece_coords[i][j]) {
				return false;
			}
		}
	}

	//check items
	if (this->has_item != t.has_item && this->item_piece != t.item_piece && this->item_type != t.item_type) {
		return false;
	}

	return true;
}

bool Tetromino::operator ==(int t) {
	if (this == 0 && t == 0) {
		return true;
	}
	return false;
}