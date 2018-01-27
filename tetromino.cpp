#include "tetromino.h"
#include "piece.h"
#include <SFML/Graphics/Color.hpp>

using namespace std;
using namespace sf;

Tetromino::Tetromino(){
   /* int piece_coords[4][2]; //the 4 pieces' x and y coordinates
    int shape_type;         //the shape type. 7 different types. Line, Square, T, L, reverse L, S, Z
    QColor shape_color;     //the shape color
    bool has_item;          //whether or not the shape has an item
    int item_piece;*/
}

Tetromino::Tetromino(int type){
    shape_type = type;
    shape_color = colors[type];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[type][i][j];
            //piece_coords[type][i][j] = -1;
        }
    }
    has_item = false;
    item_piece = -1;
}

Tetromino::Tetromino(int type, Color color){
    shape_type = type;
    shape_color = color;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[type][i][j];
            //piece_coords[i][j] = -1;
        }
    }
    has_item = false;
    item_piece = -1;
}

Tetromino::Tetromino(int type, int piece_id, bool has_item = true){
    shape_type = type;
    shape_color = colors[type];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[type][i][j];
            //piece_coords[type][i][j] = -1;
        }
    }
    item_piece = piece_id;
}

Tetromino::Tetromino(int type, Color color, int piece_id, bool has_item = true){
    shape_type = type;
    shape_color = color;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[type][i][j];
            //piece_coords[i][j] = -1;
        }
    }
    item_piece = piece_id;
}

void Tetromino::create_piece(){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 2; j++){
            piece_coords[i][j] = starting_coords[shape_type][i][j];
        }
    }

}
