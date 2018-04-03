#ifndef TETROMINO_H
#define TETROMINO_H

#include <SFML/Graphics/Color.hpp>
#include <random>
#include <iostream>

using namespace std;
using namespace sf;

//The shapes we'll control and generate to play the game.

class Tetromino {
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

	//move to board?
	const Color colors[7] = {
		Color::Cyan,		//cyan for line
		Color::Yellow,		//yellow for square
		Color::Magenta,		//purple for T (try Magenta, otherwise make a purple)
		Color(255, 165, 0),	//orange for L
		Color::Blue,		//blue for reverse L
		Color::Green,		//green for S
		Color::Red			//red for Z
	};

	const string names[7] = {	//may not need
		"Line",
		"Square",
		"T",
		"L",
		"Reverse L",
		"S",
		"Z"
	};

	//constructors
	Tetromino();															//default. may not be called.
	Tetromino(int type);													//passes in piece type (t, z, l, ect.)
	Tetromino(int type, Color color);										//piece type and custom color (color is already made)
	//copy constructor?

	Tetromino(int type, Color color, int piece_id);							//piece with item, set color, and which piece contains the item. random item
	Tetromino(int type, int piece_id);										//piece with item, uses default shape color, which piece for the item. random item

	Tetromino(int type, Color color, int piece_id, int item_id);			//set color and item
	Tetromino(int type, int piece_id, int item_id);							//set item but not color

	//gets
	int getX(int piece) { return piece_coords[piece][0]; };		//returns the x coordinate of a specific piece
	int getY(int piece) { return piece_coords[piece][1]; };		//returns the y coordinate of a specific piece
	Color getColor() { return shape_color; }					//returns the piece color
	int getType() { return shape_type; };						//returns the piece type

	//sets
	void setX(int piece, int x) { piece_coords[piece][0] = x; };	//sets the x of a piece
	void setY(int piece, int y) { piece_coords[piece][1] = y; };	//sets the y of a piece
	void setColor(Color c) { shape_color = c; };					//sets the piece color
	void setType(int type) { shape_type = type; };					//sets the piece type
	void setCoords(int piece, int x, int y) { piece_coords[piece][0] = x; piece_coords[piece][1] = y; };	//sets the x and y of a piece

	//operators
	Tetromino& operator =(Tetromino& t);	//copy the coords, type, color, items
	bool operator ==(Tetromino& t);			//check if equal, and also check if null
	bool operator ==(int t);				//check for null
	friend std::ostream & operator <<(ostream &os, const Tetromino& t);

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
	void reset_piece();		//resets the piece coordinates to its default
	bool rotate_right();	//counter-clockwise rotation. Should this be handled here, or by the board?
	bool rotate_left();		//clockwise rotation

	//deconstructor
};
#endif // TETROMINO_H
