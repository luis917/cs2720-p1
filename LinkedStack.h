#ifndef LINKED_STACK_H
#define LINKED_STACK_H
#include "Stack.h"
#include "LinkedList.h"

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;


/**
 * @author - Luis Perea
 * CS2720 - Data Structures
 * 9/27/2015
 * A stack implementation based on a doubly linked-list.
 */
template<typename T>
class LinkedStack : public Stack<T> {
	// instance/state variables
public:

	LinkedList<T> * list = new LinkedList<T>;

	// Default Constructor
	LinkedStack(void) = default;

	// Copy Constructor
	LinkedStack(const LinkedStack<T> & other) {
		int other_size = other.list->size();

		if(other_size != 0)
		{
			for (int index = 0; index < other_size; index++)
			{
				T temporary_value = other.list->get(index);
				list->append(temporary_value);
			}
		}
		else
			cout << "Empty stack " << endl;
	} // LinkedStack

	// Destructor
	~LinkedStack(void) {
		list->clear();
		cout << "Linked Stack destructed" << endl;
		delete list;
	} // ~LinkedStack

	/**
	 * Pushes an item onto the top of this stack.
	 *
	 * @param data the item to be pushed onto this stack
	 */
	void push(T data)
	{
		list->append(data);
	}

	/**
	 * Removes the item at the top of this stack and returns that item
	 */
	T pop(void)
	{
		if (list->empty() != 1)
		{
			T item = list->get(list->size()-1);
			list->remove_tail();
			return item;
		}
		else
		{
			cout << "empty stack" << endl;
			return -1;
		}
	}

	/**
	 * Returns the item at the top of this stack without removing it from the
	 * stack.
	 */
	T peek(void) const
	{
		if (empty() != 1)
		{
			T item = list->get(size()-1);
			return item;
		}
		else
		{
			cout << "empty stack" << endl;
			return -1;
		}
	}

	/**
	 * Returns the number of elements in this stack.
	 */
	const int size(void) const
	{
		return list->size();
	}

	/**
	 * Returns whether or not this stack is empty.
	 */
	const bool empty() const {
		return size() == 0;
	} // empty

	/*
	 * Prints the elements in the list.
	 */
	void print(void)
	{
		list->print();
	}

}; // LinkedStack
#endif /* LINKED_STACK_H */

