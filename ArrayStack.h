#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H
#include "Stack.h"
#include <array>
#include <iostream>
#include <cstdlib>
using std::cout;
using std::endl;

/**
 * An array-based stack implementation.
 */
template<typename T>
class ArrayStack : public Stack<T> {
	// instance/state variables

T * array;
int top = -1;
int max_size;

public:
// Default Constructor
ArrayStack(void)
{
	max_size = 100;
	array = new T[max_size];
}

ArrayStack(int new_size)
{
	max_size = new_size;
	array = new T[max_size];
}

// Copy Constructor
ArrayStack(const ArrayStack<T> & other)
{
	cout << other.max_size << endl;
	max_size = other.max_size;
	array = new T[max_size];
	for (int index = 0; index < other.size(); index++)
	//for (int index : other.max_size)
	{
		array[index] = other.array[index];
		top++;
	}
} // ArrayStack

// Destructor
~ArrayStack(void)
{
	delete[] array;
} // ~ArrayStack

/**
 * Pushes an item onto the top of this stack.
 *
 * @param data the item to be pushed onto this stack
 */
void push(T data)
{
	if(top == max_size-1)
	{
		T  * new_array = new T[max_size + 1];
		for (int index = 0; index < max_size; index++)
		{
			new_array[index] = array[index];
		}
		array = new_array;
		max_size++;

		//
		//printf("max size is now: %d\n", max_size);
	}
	top++;
	array[top] = data;
}

/**
 * Removes the item at the top of this stack and returns that item
 */
T pop(void)
{
	if (top == -1)
	{
		cout << "Empty Stack" << endl;
		return -1;
	}
	return array[top--];
}

/**
 * Returns the item at the top of this stack without removing it from the
 * stack.
 */
T peek(void) const
{
	if (top == -1)
	{
		cout << "Empty Stack" << endl;
		return -1;
	}
	return array[top];
}

/**
 * Returns the number of elements in this stack.
 */
const int size(void) const
{
	return top+1;
}

/**
 * Returns whether or not this stack is empty.
 */
const bool empty() const {
	return size() == 0;
} // empty

void print()
{
	if (top == -1)
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

}; // ArrayStack
#endif /* ARRAY_STACK_H */

