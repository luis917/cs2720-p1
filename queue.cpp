#include <iostream>
#include <cstdlib>
#include "LinkedList.h"
#include "LinkedStack.h"
#include "LinkedQueue.h"
#include "ArrayStack.h"
#include "ArrayQueue.h"
#include <sys/time.h>
using std::cout;
using std::endl;


/*
 * testing Array Queue and Linked Queue
 */
int main(int argc, const char * argv[]) {

	cout << "testing LinkedQueue" << endl << endl;

	//time variables
	double time_in_ms = 0.0, seconds_diff = 0.0, usec_diff = 0.0;
	struct timeval tv_start, tv_end;

	int sample_size = 1000;


	LinkedQueue<int> * queue_original = new LinkedQueue<int> {};
	LinkedQueue<int> queue = * queue_original;

	for (int index = 0; index < 4; index++)
	{
		//linkedstack enqueue
		gettimeofday(&tv_start, NULL);
		for(int i = 0; i < sample_size; i++)
		{
			queue.enqueue(rand());
		}

		gettimeofday(&tv_end, NULL);
		seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
		usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
		time_in_ms = seconds_diff + usec_diff;
		cout << "time in ms to enqueue " << sample_size << " : " << time_in_ms << endl;
		cout << "size: " << queue.size() << endl;

		//linkedstack dequeue
		gettimeofday(&tv_start, NULL);
		for(int i = 0; i < sample_size; i++)
		{
			queue.dequeue();
		}

		gettimeofday(&tv_end, NULL);
		seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
		usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
		time_in_ms = seconds_diff + usec_diff;
		cout << "time in ms to dequeue " << sample_size << " : " <<time_in_ms << endl;
		cout << "size: " << queue.size() << endl;

		sample_size = sample_size * 10;
		cout << endl;
	}

	cout << "--------------------------------------------------" << endl;

	cout << "testing Array Queue" << endl << endl;
	sample_size = 1000;

	ArrayQueue <int> * array_original = new ArrayQueue<int> {};
	ArrayQueue <int> array = * array_original;

	for (int index = 0; index < 4; index++)
	{
		//array enqueue
		gettimeofday(&tv_start, NULL);
		for(int i = 0; i < sample_size; i++)
		{
			array.enqueue(rand());
		}

		gettimeofday(&tv_end, NULL);
		seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
		usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
		time_in_ms = seconds_diff + usec_diff;
		cout << "time in ms to enqueue " << sample_size << " : " << time_in_ms << endl;
		cout << "size: " << array.size() << endl;

		//arrayqueue dequeue
		gettimeofday(&tv_start, NULL);
		for(int i = 0; i < sample_size; i++)
		{
			array.dequeue();
		}

		gettimeofday(&tv_end, NULL);
		seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
		usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
		time_in_ms = seconds_diff + usec_diff;
		cout << "time in ms to dequeue " << sample_size << " : " <<time_in_ms << endl;
		cout << "size: " << array.size() << endl;

		sample_size = sample_size * 10;
		cout << endl;
	}

	//delete[] array_original;

	// -------------------------------------------------------------
	/*
	ArrayQueue <int> * array = new ArrayQueue<int> {};

	for(int i = 0; i < 1000000; i++)
	{
		array->enqueue(i);
	}

	array->print();

	for(int i = 0; i < 1000000; i++)
	{
		array->dequeue();
	}

	array->print();
	*/

	//------------------------------------------------------------

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
	for (int index = 0; index < 10; index++)
	{
		arrayQueue->enqueue(index);
	}
	arrayQueue->print();
	cout << "size: " << arrayQueue->size() << endl;
	cout << "peek tail: " << arrayQueue->peekTail() << endl;
	//arrayQueue->printAtIndex(102);
	//cout << "size: " << arrayQueue->size() << endl;
	//cout << "dequeue: " << arrayQueue->dequeue() << endl;
	//cout << "size: " << arrayQueue->size() << endl;

	*/


	// Queue<int> * q1 = new ArrayQueue<int> {};
	// Queue<int> * q2 = new LinkedQueue<int> {};
	// test!
	// delete q1;
	// delete q2;

	//return EXIT_SUCCESS;

}
// main




