#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H
#include "Queue.h"
#include <cstdlib>
using std::cout;
using std::endl;

/**
 * An array-based queue implementation.
 * @author - Luis Perea
 * CS2720 - Data Structures
 * 9/27/2015
 */
template<typename T>
class ArrayQueue : public Queue<T> {

	// instance/state variables
	T * array;
	int head = -1;
	int tail = -1;
	int max_size;
	int current_size = 0;


public:
	// Default Constructor
	ArrayQueue(void)
{
		max_size = 2000000;
		array = new T[max_size];
}

	// Copy Constructor
	ArrayQueue(const ArrayQueue<T> & other) {
		max_size = other.max_size;
		array = new T[max_size];
		for (int index = 0; index < other.size(); index++)
		{
			array[index] = other.array[index];
			tail++;
		}
		tail = other.tail;
		head = other.head;
		current_size = other.current_size;
	} // Copy Constructor ArrayQueue


	// Destructor
	~ArrayQueue(void) {
		delete [] array;
		cout << "Array Queue was destructed" << endl;
	} // ~ArrayQueue


	/**
	 * Adds an item to the rear of this queue.
	 *
	 * @param data the item to be enqueued
	 */
	void enqueue(T data)
	{
		//increases the size of the queue if the maximum size is reached
		if (isFull() == 1)
		{
			cout << "Full Queue" << endl;
			max_size = max_size + 10000;
			T * newArray = new T[max_size];
			for (int index = 0; index < max_size; index++)
			{
				newArray[index] = array[index];
			}
			array = newArray;
			tail++;
			array[tail] = data;
			current_size++;
		}
		else
		{
			tail++;
			array[tail] = data;
			current_size++;
		}
	}

	/**
	 * Removes the item at the front of this queue and returns that item
	 */
	T dequeue(void)
	{
		if (empty() == 1)
		{
			cout << "empty queue " << endl;
			return -1;
		}
		current_size = current_size - 1;
		T item = array[head+1];
		head++;
		return item;
	}

	/**
	 * Returns the item at the front of this queue without removing it from the
	 * queue.
	 */
	T peek(void) const
	{
		if (empty() == 1)
		{
			cout << "Empty Queue ";
			return -1;
		}
		return array[head+1];
	}

	/*
	 * Returns the item at the end of the queue without removing it from the queue.
	 */
	T peekTail(void) const
	{
		if (empty() == 1)
		{
			cout << "Empty Queue ";
			return -1;
		}
		return array[tail];
	}

	/**
	 * Returns the number of elements in this queue.
	 */
	const int size(void) const
	{
		return tail-head;
	}

	const bool isFull()
	{
		return (tail - head) == max_size;
	}


	/**
	 * Returns whether or not this queue is empty.
	 */
	const bool empty() const {
		return size() == 0;
	} // empty

	/*
	 * Prints the elements between head and tail.
	 */
	void print()
	{
		if (empty() == 1)
		{
			cout << "Empty Queue " << endl;
		}
		else
		{
			int index;
			for (index = head+1; index < tail + 1; index++)
			{
				cout << array[index] << endl;
			}
			cout << endl;
		}
	}

	/*
	 * Prints the element at the specified index
	 * @param index - the index to print
	 */
	void printAtIndex(int index)
	{
		cout << array[index] << endl;
	}

};
// ArrayQueue
#endif /* ARRAY_QUEUE_H */

