#include "tetromino.h"
#include "piece.h"
#include "board.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <random>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	cout << "Hey world";
	Tetromino t1 = Tetromino();
	Piece p1 = Piece();

	Tetromino t2 = Tetromino(3);
	Queue piece_queue = Queue();
	piece_queue.add(t2);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1); //extra

	Tetromino t3 = piece_queue.pop();
	cout << t3.getType();



	_getch();
}
