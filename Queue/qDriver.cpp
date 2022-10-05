//****************************************************************************************************
//
//         File:                        Queue.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Program  # 7
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         Mar 19, 2021
//
//
//         This program tests the queue.
//
//
//**************************************************************************************************** 
#include <iostream>

using namespace std; 

#include "Queue.h" 

//****************************************************************************************************

int main()
{
	Queue<int> q1 = Queue<int>();

	int temp;

	if (!q1.dequeue(temp))
	{
		cout << "extraction failed " << endl; 
	}

	if (!q1.viewFront(temp))
	{
		cout << "front is empty" << endl;
	}

	if (!q1.viewRear(temp))
	{
		cout << "rear is empty" << endl;
	}

	cout << "Number of values: " << q1.getNumValues() << endl; 

	if (q1.isFull())
	{
		cout << "list is full" << endl;
	}

	if (q1.isEmpty())
	{
		cout << "list is empty" << endl;
	}

	temp = 10; 
	q1.enqueue(temp); 
	
	temp = 15; 
	q1.enqueue(temp);

	if (q1.viewFront(temp))
	{
		cout << "front is: " << temp << endl;
	}

	if (q1.viewRear(temp))
	{
		cout << "rear is:" << temp << endl;
	}

	cout << "Number of values: " << q1.getNumValues() << endl;

	if (q1.dequeue(temp))
	{
		cout << "extraction of: " << temp  << " from queue."<< endl;
	}

	if (q1.isFull())
	{
		cout << "list is full" << endl;
	}

	if (q1.isEmpty())
	{
		cout << "list is empty" << endl;
	}
	 
	q1.~Queue(); 

	if (q1.isEmpty())
	{
		cout << "list is empty" << endl;
	}

	return 0;
} 

//****************************************************************************************************

/* 

extraction failed
front is empty
rear is empty
Number of values: 0
list is empty
front is: 10
rear is:15
Number of values: 2
extraction of: 10 from queue.
list is empty

*/