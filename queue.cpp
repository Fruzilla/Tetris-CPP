#include "queue.h"
#include "tetromino.h"

Queue::Queue() {
	capacity = 6;
	front = 0;
	rear = capacity - 1;
	size = 0;
	*tet_queue = new Tetromino[capacity];
}

Queue::Queue(int c) {
	capacity = c;
	front = 0;
	rear = capacity - 1;
	size = 0;
	*tet_queue = new Tetromino[capacity];
}

Tetromino Queue::pop() {
	if (isEmpty()) {
		return;
	}
	Tetromino temp = *tet_queue[front];
	front++;
	size--;
	return temp;
}

void Queue::add(Tetromino t) {
	if (isFull()) {
		return;
	}
	rear = (rear + 1) % capacity;
	*tet_queue[rear] = t;
	size++;
}

int Queue::getCapacity() {
	return capacity;
}

bool Queue::isFull() {
	return (size >= capacity);
}

bool Queue::isEmpty() {
	return size <= 0;
}

Tetromino Queue::getFront() {
	return *tet_queue[front];
}

Tetromino Queue::getRear() {
	return *tet_queue[rear];
}

