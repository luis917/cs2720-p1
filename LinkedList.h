#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <cstdlib>

using std::cout;
using std::endl;

//forward declaration of LinkedList
template<typename T>
class LinkedList;

/**
 * @author - Luis Perea
 * CS2720 - Data Structures
 * 9/27/15
 *
 * Represents a node in a doubly-linked list.
 */
template<typename T>
class Node {
	friend class LinkedList<T>;
	T data;
	Node<T> * prev = nullptr;
	Node<T> * next = nullptr;
}; // Node

/**
 * A doubly-linked list data structure.
 */
template<typename T>
class LinkedList {

	int number_of_elements = 0;

public:

	Node<T> * head = nullptr;


	Node<T> * tail = nullptr;

	/**
	 * Adds an item to the end of this list.
	 *
	 * @param data the item to append
	 */
	void append(T data)
	{
		Node<T> * node = new Node<T>;
		node->data=data;
		if (number_of_elements == 0)
		{
			head = node;
			tail = node;
		}
		else if (number_of_elements == 1)
		{
			node->prev = head;
			head->next = node;
			node->next = nullptr;
			tail = node;
		}
		else
		{
			node->prev = tail;
			node->prev->next = node;
			node->next = nullptr;
			tail = node;
		}
		number_of_elements++;
	}

	/**
	 * Removes all elements from this list.
	 */
	void clear(void)
	{
		if (number_of_elements != 0)
		{
			Node<T> * temp = head;
			while (temp != nullptr)
			{
				head = head->next;
				delete temp;
				temp = head;
			}
			cout << "cleared " << endl;
			head = nullptr;
			tail = nullptr;
			number_of_elements = 0;
		}
	}

	/*
	 * Returns the item at the given index location.
	 *
	 * @param i the index of the item to return
	 */
	T get(int i) const
	{
		if (number_of_elements != 0)
		{
			if (i == 0)
			{
				return head->data;
			}
			else if (i == size()-1)
			{
				return tail->data;
			}
			else
			{
				Node<T> * temp = head;
				for (int j = 0; j < i; j++)
				{
					temp = temp->next;
				}
				return temp->data;
			}
		}
		else return -1;
	}//get

	/**
	 * Adds an item to the list at the specified index location.
	 *
	 * @param i the index where to insert the item
	 * @param data the item to insert
	 */
	void insert(int i, T data)
	{
		if (number_of_elements == 0)
		{
			prepend(data);
		}
		else
		{
			Node<T> * node = new Node<T>;
			node->data = data;
			Node<T> * temp = head;
			for (int j = 0; j < i-1; j++)
			{
				temp = temp->next;
			}
			node->next = temp->next;
			node->next->prev = node;

			temp->next = node;
		}
		number_of_elements++;
	}//insert

	/**
	 * Adds an item to the front of this list.
	 *
	 * @param data the item to prepend
	 */
	void prepend(T data)
	{
		Node<T> * node = new Node<T>;
		node->data=data;
		if (number_of_elements == 0)
		{
			head = node;
			tail = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
		number_of_elements++;
	} //prepend

	/**
	 * Sets the value of element at the given index.
	 *
	 * @param i the index of the element to set
	 * @param data the value to set
	 */
	void set(int i, T data)
	{
		if (number_of_elements != 0)
		{
			Node<T> * temp = head;
			for (int j = 0; j < i; j++)
			{
				temp = temp->next;
			}
			temp->data = data;
		}
		else
		{
			cout << "List is empty" << endl;
		}
	}//set

	/**
	 * Returns the number of elements in this list.
	 */
	const int size() const
	{
		if ( number_of_elements == 0 )
			return 0;

		if (head == NULL)
			return 0;

		return number_of_elements;
	}//size

	/**
	 * Returns whether or not this linked list is empty.
	 */
	const bool empty() const {
		return size() == 0;
	} // empty

	/*
	 * Prints the elements in the list
	 */
	void print()
	{
		if (number_of_elements == 0)
		{
			cout << "empty" << endl;
		}
		else if (number_of_elements != 0)
		{
			Node<T> * current = head;
			while (current != nullptr)
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;
		}
	} //print

	/*
	 * Remove the node at the end of the list.
	 */
	void remove_tail()
	{
		if ( tail != NULL)
		{
			Node<T> * temp = tail;
			if (tail->prev != nullptr)
			{
				tail = temp->prev;
				tail->next = nullptr;
			}
			delete temp;
			number_of_elements--;
		}
	} //remove_tail

	/*
	 * Remove the node at the begining of the list.
	 */
	void remove_head()
	{
		if (head != nullptr)
		{
			Node<T> * temp = head;
			if (head->next != nullptr)
			{
				head = temp->next;
				head->prev = nullptr;
			}
			delete temp;
			number_of_elements--;
		}
	} //remove_head

};
// LinkedList

#endif /** LINKED_LIST_H */

