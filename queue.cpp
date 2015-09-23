#include <iostream>
#include <cstdlib>
//#include "ArrayQueue.h"
//#include "LinkedQueue.h"
#include "LinkedList.h"
#include "LinkedStack.h"
using std::cout;
using std::endl;
using std::string;
int main(int argc, const char * argv[]) {
cout << "Testing Queue Implementations..." << endl;
//LinkedList<int> * list = new LinkedList<int> {};
/*
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
list->print();
cout << "Size: " << list->size() << endl;
list->append(1);
list->print();
cout << "get(0): " << list->get(0) << endl;
*/

cout << endl << "testing linkedstack" << endl;

LinkedStack <int> * list = new LinkedStack <int> {};
list->push(5);
list->push(2);
list->push(3);
list->print();
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
delete list;

// Queue<int> * q1 = new ArrayQueue<int> {};
// Queue<int> * q2 = new LinkedQueue<int> {};
// test!
// delete q1;
// delete q2;
return EXIT_SUCCESS;
} // main
