#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics/Color.hpp>

using namespace std;
using namespace sf;

//The pieces that will fill the board grid.

class Piece{
public:
    Piece();
    Piece(Color color, bool is_set = true, int item_id = 0){piece_color = color;}
    Piece(Color color, bool is_set = true, int i_id);


private:
    //  private variables
    Color piece_color; //the piece color. String which equals color tuple (ie RED = (255, 0, 0). Use Color (r, g b)
    int item_id;        //0 if no item, the item id if there is. Define items in main? Or separate cpp
    bool is_set;        //whether this piece is filled or not
    //int x;              //x coordinate. might not be necessary?
    //int y;              //y coordinate

    //  private functions
    void reset();       //resets this particular piece's state
};

#endif // PIECE_H
