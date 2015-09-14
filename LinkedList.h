#ifndef LINKED_LIST_H
#define LINKED_LIST_H
// forward declation of LinkedList
template<typename T>
class LinkedList;
/**
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
public:
/**
* Adds an item to the end of this list.
*
* @param data the item to append
*/
void append(T data);
/**
* Removes all elements from this list.
*/
void clear(void);
/**
* Returns the item at the given index location.
*
* @param i the index of the item to return
*/
T get(int i) const;
/**
* Adds an item to the list at the specified index location.
*
* @param i the index where to insert the item
* @param data the item to insert
*/
void insert(int i, T data);
/**
* Adds an item to the end of this list.
*
* @param data the item to prepend
*/
void prepend(T data);
/**
* Sets the value of element at the given index.
*
* @param i the index of the element to set
* @param data the value to set
*/
void set(int i, T data);
/**
* Returns the number of elements in this list.
*/
const int size() const;
/**
* Returns whether or not this linked list is empty. */
const bool empty() const {
return size() == 0;
} // empty
}; // LinkedList
#endif /** LINKED_LIST_H */

