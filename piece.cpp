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

void Piece::setPiece(Color color, int i_id) {
	piece_color = color;
	item_id = i_id;
	is_set = true;
}

void Piece::setColor(Color color) {
	piece_color = color;
}

void Piece::setColorSolid(Color color) {
	piece_color;
	is_set = true;
}

void Piece::setItem(int i_id) {
	item_id = i_id;
}

void Piece::setItemSolid(int i_id) {
	item_id = i_id;
	is_set = true;
}

void Piece::setIsSet(bool set) {
	is_set = set;
}

Color Piece::getColor() {
	return piece_color;
}

int Piece::getItem() {
	return item_id;
}

bool Piece::getIsSet() {
	return is_set;
}



