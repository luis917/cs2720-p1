#include <iostream>
#include <cstdlib>
//#include "ArrayQueue.h"
//#include "LinkedQueue.h"
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"

using std::cout;
using std::endl;
using std::string;
int main(int argc, const char * argv[]) {


cout << "Testing Queue Implementations..." << endl;
LinkedList<int> * list = new LinkedList<int> {};
printf("\n");
list->append(5);
list->append(2);
cout << "get(0): " << list->get(0) << endl;
list->print();
list->prepend(1);
cout << "get(0): " << list->get(0) << endl;
list->print();
cout << "Size: " << list->size() << endl;
list->insert(1, 4);
list->print();
cout << "set: ";
list->set(1, 8);
list->print();
cout << "empty? " << list->empty() << endl;
list->clear();
cout << "after clear: ";
list->print();
cout << "Size: " << list->size() << endl;
list->append(1);
list->print();
cout << "get(0): " << list->get(0) << endl;
list->append(2);
LinkedList<int> list2 = * list;
list2.print();


/*
cout << endl << "testing linkedstack" << endl;

LinkedStack <int> * list = new LinkedStack <int> {};
list->push(5);
list->push(2);
list->push(3);
list->print();
cout << "size: " << list->size() << endl;
cout << "peek: " << list->peek() << endl;
cout << "pop: " << list->pop() << endl;
list->print();
cout << "pop: " << list->pop() << endl;
cout << "size: " << list->size() << endl;
list->print();
cout << "size: " << list->size() << endl;
cout << "pop: " << list->pop() << endl;
list->print();
cout << "size: " << list->size() << endl;
cout << "pop: " << list->pop() << endl;
cout << "size: " << list->size() << endl;
//delete list;
list->push(1);
list->print();
cout << "size: " << list->size() << endl;
list->push(2);
list->print();
LinkedStack<int> list2 = *list;
list2.print();
LinkedStack<int> * list3 = list;
list3->print();
//LinkedStack<int> list4 = new LinkedStack<int> {list};
*/

/*
printf("testing linkedQueue\n");

LinkedQueue <int> * list = new LinkedQueue <int> {};
cout << "pointer: " << &list << endl;

cout << "dequeue: " << list->dequeue() << endl;
list->enqueue(1);
list->enqueue(2);
list->enqueue(3);
list->print();
cout << "size: " << list->size() << endl;
cout << "peek: " << list->peek() << endl;
cout << "dequeue: " << list->dequeue() << endl;
list->print();
cout << "size: " << list->size() << endl;
cout << "peek: " << list->peek() << endl;
cout << "dequeue: " << list->dequeue() << endl;
cout << "size: " << list->size() << endl;
cout << "dequeue: " << list->dequeue() << endl;
cout << "size: " << list->size() << endl;
list->print();
//free(list);
//delete list;
cout << "pointer: " << &list << endl;
*/

/*
printf("testing ArrayStack\n");

ArrayStack<int> * array = new ArrayStack <int> {};
cout << "empty: array->empty() " << endl;
array->print();
array->push(1);
array->push(2);
array->print();
cout << "size: " << array->size() << endl;
cout << "pop: " << array->pop() << endl;
cout << "pop: " << array->pop() << endl;
array->print();
array->push(3);
array->push(4);
cout << "peek: " << array->peek() << endl;
cout << "size: " << array->size() << endl;
array->pop();
array->pop();
cout << "peek: " << array->peek() << endl;
for (int index = 0; index < 102; index++)
{
	array->push(index);
}
array->push(103);
array->print();
*/


/*
printf("Testing ArrayQueue\n");
ArrayQueue<int> * arrayQueue = new ArrayQueue<int> {};
cout << "empty: " << arrayQueue->empty() << endl;
arrayQueue->print();
arrayQueue->enqueue(1);
arrayQueue->enqueue(2);
arrayQueue->enqueue(3);
arrayQueue->print();
cout << "size: " << arrayQueue->size() << endl;
cout << "dequeue: " << arrayQueue->dequeue() << endl;
cout << "dequeue: " << arrayQueue->dequeue() << endl;
arrayQueue->print();
cout << "dequeue: " << arrayQueue->dequeue() << endl;
arrayQueue->print();
cout << "size: " << arrayQueue->size() << endl;
cout << "dequeue: " << arrayQueue->dequeue() << endl;
arrayQueue->enqueue(4);
arrayQueue->enqueue(5);
cout << "peek: " << arrayQueue->peek() << endl;
arrayQueue->dequeue();
arrayQueue->dequeue();
arrayQueue->print();
cout << "size: " << arrayQueue->size() << endl;
for (int index = 0; index < 102; index++)
{
	arrayQueue->enqueue(index);
}
arrayQueue->print();
*/

// Queue<int> * q1 = new ArrayQueue<int> {};
// Queue<int> * q2 = new LinkedQueue<int> {};ß∫
// test!
// delete q1;
// delete q2;
return EXIT_SUCCESS;
} // main
