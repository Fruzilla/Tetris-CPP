#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics/Color.hpp>

using namespace sf;

//The pieces that will fill the board grid.

class Piece{
	friend class Board;			//Allow board to access and manipulate the piece
public:
    Piece();						//default. white, no item, not set
	Piece(Color color);				//pass a color
    Piece(Color color, int i_id);	//pass color, item id

private:
    //  private variables
    Color piece_color;	//the piece color
    int item_id;		//0 if no item, the item id if there is. Define items in main? Or separate cpp
    bool is_set;		//whether this piece is filled or not

    //  private functions
    void reset();       //resets this particular piece's state
};

#endif // PIECE_H
