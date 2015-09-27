#include <iostream>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>
#include "ArrayStack.h"
#include "LinkedStack.h"
using std::cout;
using std::endl;
using std::string;


//Testing Array Stack and Linked Stack
int main(int argc, const char * argv[]) {
//cout << "Testing Stack Implementations..." << endl;
// Stack<int> * s1 = new ArrayStack<int> {};
// Stack<int> * s2 = new LinkedStack<int> {};
// test!
// delete s1;
// delete s2;

cout << "testing LinkedStack" << endl << endl;

//time variables
double time_in_ms = 0.0, seconds_diff = 0.0, usec_diff = 0.0;
struct timeval tv_start, tv_end;

int sample_size = 1000;

LinkedStack<int> * stack_original = new LinkedStack<int> {};
LinkedStack<int> stack = * stack_original;

for (int index = 0; index < 4; index++)
{
	//linkedstack push
	gettimeofday(&tv_start, NULL);
	for(int i = 0; i < sample_size; i++)
	{
		stack.push(rand());
	}

	gettimeofday(&tv_end, NULL);
	seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
	usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
	time_in_ms = seconds_diff + usec_diff;
	cout << "time in ms to push " << sample_size << " : " << time_in_ms << endl;
	cout << "size: " << stack.size() << endl;

	//linkedstack pop
	gettimeofday(&tv_start, NULL);
	for(int i = 0; i < sample_size; i++)
	{
		stack.pop();
	}

	gettimeofday(&tv_end, NULL);
	seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
	usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
	time_in_ms = seconds_diff + usec_diff;
	cout << "time in ms to pop " << sample_size << " : " <<time_in_ms << endl;
	cout << "size: " << stack.size() << endl;

	sample_size = sample_size * 10;
	cout << endl;
}

cout << "--------------------------------------------------" << endl;

cout << "testing Array Stack" << endl << endl;
sample_size = 1000;

ArrayStack <int> * array_original = new ArrayStack<int> {};
ArrayStack <int> array = * array_original;

for (int index = 0; index < 4; index++)
{
	//linkedstack push
	gettimeofday(&tv_start, NULL);
	for(int i = 0; i < sample_size; i++)
	{
		array.push(rand());
	}

	gettimeofday(&tv_end, NULL);
	seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
	usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
	time_in_ms = seconds_diff + usec_diff;
	cout << "time in ms to push " << sample_size << " : " << time_in_ms << endl;
	cout << "size: " << array.size() << endl;

	//linkedqueue pop
	gettimeofday(&tv_start, NULL);
	for(int i = 0; i < sample_size; i++)
	{
		array.pop();
	}

	gettimeofday(&tv_end, NULL);
	seconds_diff = (tv_end.tv_sec - tv_start.tv_sec)*1000.0;
	usec_diff = (tv_end.tv_usec - tv_start.tv_usec)/1000.0;
	time_in_ms = seconds_diff + usec_diff;
	cout << "time in ms to pop " << sample_size << " : " <<time_in_ms << endl;
	cout << "size: " << array.size() << endl;

	sample_size = sample_size * 10;
	cout << endl;
}


return EXIT_SUCCESS;
} // main


