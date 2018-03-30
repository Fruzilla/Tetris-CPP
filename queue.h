#ifndef QUEUE_H
#define QUEUE_H

#include "tetromino.h"

class Queue{
public:
	Queue();
	Queue(int c);
	Tetromino pop();		//remove from front of queue
	void add(Tetromino t);	//add to end of queue

	int getCapacity();	
	bool isFull();
	bool isEmpty();
	
	Tetromino getFront();	//returns the item at the front of the queue (does not alter queue)
	Tetromino getRear();	//returns the item at the rear of the queue (does not alter queue)

private:
	int front, rear, size, capacity;
	Tetromino* tet_queue[];
};

#endif // QUEUE_H
