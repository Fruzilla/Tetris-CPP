#include "queue.h"
#include "tetromino.h"

Queue::Queue() {
	front = 0;
	rear = CAPACITY - 1;
	size = 0;
}

Tetromino Queue::pop() {
	if (isEmpty()) {
		return NULL;
	}
	Tetromino temp = tet_queue[front];
	front++;
	size--;
	return temp;
}

void Queue::add(Tetromino t) {
	if (isFull()) {
		return;
	}
	rear = (rear + 1) % CAPACITY;
	tet_queue[rear] = t;
	size++;
}

int Queue::getCapacity() {
	return CAPACITY;
}

bool Queue::isFull() {
	return (size >= CAPACITY);
}

bool Queue::isEmpty() {
	return size <= 0;
}

Tetromino Queue::getFront() {
	return tet_queue[front];
}

Tetromino Queue::getRear() {
	return tet_queue[rear];
}

