#include "tetromino.h"
#include "piece.h"
#include "board.h"
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <stdlib.h>
#include <conio.h>
#include <iostream>

using namespace std;
using namespace sf;

void debugClasses();	//starts a simple text ui to test classes and functions
void tetTest();			//test Tetromino class and functions
void boardTest();		//test Board class and functions

int main()
{
	debugClasses();
}

void debugClasses() {
	cout << "Welcome to the Tetris class tester and debugger.\n\n\nSelect an option:\n\n\t1. Tetromino testing\n\t2. Board testing\n\tq. Quit";
	while (true){
		char input = _getch();
		switch (input) {
			case '1':
				cout << "\n\nStarting the Tetromino test.\n\n";
				tetTest();
				cout << "\nWelcome to the Tetris class tester and debugger.\n\n\nSelect an option:\n\n\t1. Tetromino testing\n\t2. Board testing\n\tq. Quit";
				break;
			case '2': 
				cout << "\n\nStarting the Board test.\n\n";
				boardTest();
				cout << "\nWelcome to the Tetris class tester and debugger.\n\n\nSelect an option:\n\n\t1. Tetromino testing\n\t2. Board testing\n\tq. Quit";
				break;
			case 'q':
				return;
			default:
				cout << "\n\nBad input, try again";
				break;
		}
	}
}

void tetTest() {
	cout << "Hey world" << std::boolalpha << endl;
	Tetromino t1 = Tetromino();
	Piece p1 = Piece();

	Tetromino t2 = Tetromino(3);
	Queue piece_queue = Queue();
	cout << "New queue is empty: " << piece_queue.isEmpty() << endl;

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
	cout << "\nt3 type: " << t3.getType() << endl;

	Tetromino t4 = NULL;
	if (t4 == NULL) {
		cout << "t4 is null" << endl;
	}
	else {
		cout << "t4 is NOT null (should be null)" << endl << t4 << endl;
	}
	Tetromino t5 = t3;
	cout << "t5 type: " << t5.getType() << endl;
	if (t3 == t5) {
		cout << "t3 and t5 are identical.\n";
	}
	else {
		cout << "t3 and t5 are NOT identical.\n";
	}

	cout << t3;

}

void boardTest() {
	srand(time(NULL));
	Board b1 = Board();

	cout << "\nTesting new piece generation.";
	b1.startGame();

	cout << "\nThe current piece is:\n" << b1.getCurrentPiece();

	cout << "\nThe queue currently contains: \n";
	Queue q = b1.getQueue();
	int temp = q.getCapacity();
	for (int i = 0; i < q.getCapacity(); i++) {
		cout << q.pop();
	}

	cout << "\nResetting the queue and current piece.";
	b1.startGame();

	cout << "\nCurrent piece is: \n" << b1.getCurrentPiece();
	cout << "\nNext piece in queue is: \n" << b1.getQueue().getFront();

	cout << "\nProgressing the game.";
	b1.nextPiece();
	
	cout << "\nNew current piece is: \n" << b1.getCurrentPiece();
	cout << "\nNew next piece in queue is: \n" << b1.getQueue().getFront();

	cout << "\nHeld piece is: " << b1.getHeldPiece();
	cout << "\nUsing hold function.";
	b1.holdPiece();

	cout << "\nNew current piece is: \n" << b1.getCurrentPiece();
	cout << "\nNew held piece is: " << b1.getHeldPiece();
	cout << "\nNew next piece in queue is: \n" << b1.getQueue().getFront();

	cout << "\nSwapping held again.";
	b1.holdPiece();

	cout << "\nNew current piece is: \n" << b1.getCurrentPiece();
	cout << "\nNew held piece is: " << b1.getHeldPiece();
	cout << "\nNew next piece in queue is: \n" << b1.getQueue().getFront();

	cout << "\nAttempting to swap again (should not change anything)";
	b1.holdPiece();

	cout << "\nNew current piece is: \n" << b1.getCurrentPiece();
	cout << "\nNew held piece is: " << b1.getHeldPiece();
	cout << "\nNew next piece in queue is: \n" << b1.getQueue().getFront();
}