#include "piece.h"

Piece::Piece(){
    piece_color = QColor("white");
    item_id = 0;
    is_set = false;
}

Piece::Piece(QColor color, int i_id){
    piece_color = color;
    item_id = i_id;
}


Piece::reset(){
    piece_color = QColor("white");
    item_id = 0;
    is_set = false;
}
