#ifndef TETROMINO_H
#define TETROMINO_H

using namespace std;
using namespace sf;

#include<SFML/Graphics/Color.hpp>
#include <random>

//The shapes we'll control and generate to play the game.

class Tetromino{
public:
	//move to board? actually make it a static global. or put it in the board and pass the row into the tetronimo
    const int starting_coords[7][4][2] = { //starting coordinates for each piece type. for consistency, 3rd position is the pivot piece.
        {{5, 1}, {5, 3}, {5, 2}, {5, 4}},
        {{4, 1}, {4, 2}, {5, 1}, {5, 2}},
        {{5, 1}, {4, 2}, {5, 2}, {6, 2}},
        {{4, 3}, {5, 3}, {4, 2}, {4, 1}},
        {{4, 3}, {5, 3}, {5, 2}, {5, 1}},
        {{5, 1}, {5, 2}, {4, 2}, {4, 3}},
        {{4, 1}, {4, 2}, {5, 2}, {5, 3}},
    };

//can't make an array of sfml colors. probably much simpler to make an array of strings instead of color objects.

//   const sf::Color colors[7] = {     //colors for each shape
//       sf::Color("cyan"), sf::Color("yellow"), sf::Color("purple"), sf::Color("orange"), sf::Color("blue"), sf::Color("green"), sf::Color("red")
//   };

//move to board?
	const string colors[7] = {
		"cyan",
		"yelow",
		"purple",
		"orange",
		"blue",
		"green",
		"red"	
	};

	//constructors
    Tetromino();																		//default. may not be called.
    Tetromino(int type);																//passes in piece type (t, z, l, ect.)
    Tetromino(int type, Color color);													//piece type and custom color (color is already made)

	Tetromino(int type, Color color, int piece_id, bool has_item = true);				//piece with item, set color, and which piece contains the item. random item
	Tetromino(int type, int piece_id, bool has_item = true);							//piece with item, uses default shape color, which piece for the item. random item

    Tetromino(int type, Color color, int piece_id, int item_id, bool has_item = true);	//set color and item
    Tetromino(int type, int piece_id, int item_id, bool has_item = true);				//set item but not color

    //gets
    int getX(int piece);					//returns the x coordinate of a specific piece
    int getY(int piece);					//returns the y coordinate of a specific piece
    Color getColor(){return shape_color;}	//returns the piece color
    int getType();							//returns the piece type

	//sets
    void setX(int piece, int x);
    void setY(int piece, int y);
    void setCoords(int piece, int x, int y);

private:
	//variables
    int piece_coords[4][2]; //the 4 pieces' x and y coordinates
    int shape_type;         //the shape type. 7 different types. Line, Square, T, L, reverse L, S, Z
    Color shape_color;		//the shape color
    bool has_item;          //whether or not the shape has an item
	int item_type;			//type of item
    int item_piece;         //which piece contains the item
    int rotation;           //rotation. probably redundant.

	//functions
    //these might all be handled by the board. Create_piece needs access to board pieces. Board should take shape color and colorize pieces.
    void create_piece();    //takes the piece type and assigns it its specific starting coordinates and color
    bool rotate_right();    //counter-clockwise rotation. Should this be handled here, or by the board?
    bool rotate_left();     //clockwise rotation
	//function to hold piece, change its coordinates

    //todo: operators (equals) to copy variables
};

#endif // TETROMINO_H
