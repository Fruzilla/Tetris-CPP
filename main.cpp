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

void test();

int main()
{
	test();
}

void test() {
	cout << "Hey world" << endl;
	Tetromino t1 = Tetromino();
	Piece p1 = Piece();

	Tetromino t2 = Tetromino(3);
	Queue piece_queue = Queue();

	Tetromino t_null = piece_queue.pop();

	cout << "Popping new queue: " << t_null.getType() << endl;
	cout << "New piece from queue is null: " << (t_null == NULL) << endl;
	cout << t_null;

	piece_queue.add(t2);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1);
	piece_queue.add(t1); //extra

	Tetromino t3 = piece_queue.pop();
	cout << "t3 type: " << t3.getType() << endl;

	Tetromino t4 = NULL;
	if (t4 == NULL) {
		cout << "t4 is null" << endl;
	}
	else {
		cout << "t4 is NOT null (should be null)" << endl;
	}
	Tetromino t5 = t3;
	cout << "t5 type: " << t5.getType() << endl;
	if (t3 == t5) {
		cout << "t3 and t5 are identical.";
	}
	else {
		cout << "t3 and t5 are NOT identical.";
	}

	cout << t3;

	_getch();
}