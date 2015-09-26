#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "Queue.h"
#include <cstdlib>
using std::cout;
using std::endl;

/**
* An array-based queue implementation.
*/
template<typename T>
class ArrayQueue : public Queue<T> {
// instance/state variables

T * array;
int head = -1;
int tail = -1;
int max_size;

public:
// Default Constructor
ArrayQueue(void)
{
	max_size = 100;
	array = new T[max_size];
}

// Copy Constructor
ArrayQueue(const ArrayQueue<T> & other) {
	max_size = other.max_size;
	array = new T[max_size];
	for (int index = 0; index < other.size(); index++)
	//for (int index : other.max_size)
	{
		array[index] = other.array[index];
		tail++;
	}
} // ArrayQueue


// Destructor
virtual ~ArrayQueue(void) {
	delete [] array;
} // ~ArrayQueue


/**
* Adds an item to the rear of this queue.
*
* @param data the item to be enqueued
*/
void enqueue(T data)
{
	if (tail == max_size - 1)
	{
		cout << "full array" << endl;
		T  * new_array = new T[max_size + 100];
		for (int index = 0; index < max_size; index++)
		{
			new_array[index] = array[index];
		}
		array = new_array;
		max_size += 100;
		printf("max size is now: %d\n", max_size);
	}
	tail++;
	array[tail] = data;
}

/**
* Removes the item at the front of this queue and returns that item
*/
T dequeue(void)
{
	if (tail == -1)
	{
		cout << "Empty Stack ";
		return -1;
	}
	T item = array[0];
	//check this
	for (int index = 0; index < max_size ; index++)
	{
		array[index] = array[index+1];
	}
	tail--;
	return item;
}

/**
* Returns the item at the front of this queue without removing it from the
* queue.
*/
T peek(void) const
{
	if (tail == -1)
	{
		cout << "Empty Stack" << endl;
		return -1;
	}
	return array[0];
}

/**
* Returns the number of elements in this queue.
*/
const int size(void) const
{
	return tail+1;
}

/**
* Returns whether or not this queue is empty.
*/
const bool empty() const {
return size() == 0;
} // empty

void print()
{
	if (tail == -1)
	{
		cout << "Empty Stack";
	}
	else
	{
		for (int index = 0; index < size(); index++)
		{
			cout << array[index] << " ";
		}
	}

	cout << endl;
}

void printAtIndex(int index)
{
		cout << array[index] << endl;
}

}; // ArrayQueue
#endif /* ARRAY_QUEUE_H */

