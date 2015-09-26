#ifndef LINKED_QUEUE_H
#define LINKED_QUEUE_H
#include <iostream>
#include <cstdlib>
#include "Queue.h"
#include "LinkedList.h"
using std::cout;
using std::endl;
using std::string;

/**
* An queue implementation based on a doubly linked list.
*/
template<typename T>
class LinkedQueue : public Queue<T> {
// instance/state variables
LinkedList<T> * list = new LinkedList<T>;

public:

// Default Constructor
LinkedQueue(void) = default;

// Copy Constructor
LinkedQueue(const LinkedQueue<T> & other) {
// TODO implement a copy constructor
	int other_size = other.list->size();

		if(other_size != 0)
		{
			for (int i = 0; i < other_size; i++)
			{
				T temporary_value = other.list->get(i);
				list->append(temporary_value);
			}
		}
		else
		{
			cout << "Empty Queue " << endl;
		}

} // LinkedQueue

// Destructor
 ~LinkedQueue(void) {
	list->clear();
	delete list;
} // ~LinkedQueue

/**
* Adds an item to the rear of this queue.
*
* @param data the item to be enqueued
*/
void enqueue(T data)
{
	list->append(data);
}

/**
* Removes the item at the front of this queue and returns that item
*/
T dequeue(void)
{
	if (empty() != 1)
	{
		T item = list->get(0);
		list->remove_head();
		return item;
	}
	else
	{
		cout << "Empty Queue" << endl;
		return -1;
	}
}

/**
* Returns the item at the front of this queue without removing it from the
* queue.
*/
T peek(void) const
{
	return list->get(0);
}

/**
* Returns the number of elements in this queue.
*/
const int size(void) const
{
	return list->size();
}

/**
* Returns whether or not this queue is empty.
*/
const bool empty() const {
return size() == 0;
} // empty

void print(void)
{
	list->print();
}

}; // LinkedQueue
#endif /* LINKED_QUEUE_H */
