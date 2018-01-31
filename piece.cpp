#include "piece.h"

Piece::Piece(){
    piece_color = Color::White;
    item_id = 0;
    is_set = false;
}

Piece::Piece(Color color, int i_id, bool) {
	piece_color = color;
	item_id = i_id;
}

void Piece::reset(){
    piece_color = Color::White;
    item_id = 0;
    is_set = false;
}
