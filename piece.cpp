#include "piece.h"

Piece::Piece(){
    piece_color = Color::White;
    item_id = 0;
    is_set = false;
}

Piece::Piece(Color color) {
	piece_color = color;
	item_id = 0;
	is_set = true;
}

Piece::Piece(Color color, int i_id) {
	piece_color = color;
	item_id = i_id;
	is_set = true;
}

void Piece::reset(){
    piece_color = Color::White;
    item_id = 0;
    is_set = false;
}
