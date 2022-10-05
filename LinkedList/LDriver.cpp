//****************************************************************************************************
//
//         File:                        LDriver.cpp
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Program  # 5
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         Feb 26, 2021
//
//
//         This program tests LList.
//
//
//**************************************************************************************************** 
#include <iostream> 

using namespace std;

#include "LList.h" 

//**************************************************************************************************** 

int main()
{
	LList<short> tempList = LList<short>(); 

	short tempShort = 5; 

	int numVal;  

	tempList.~LList();

	numVal = tempList.getNumValues(); 
	cout << "Number of values in the list is: " << numVal << endl;

	if (tempList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}

	if (!tempList.isFull())
	{
		cout << "The list is not full." << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl; 
	} 

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.viewFront(tempShort))
	{
		cout << "Front: " << tempShort << endl;
	}

	if (tempList.viewRear(tempShort))
	{
		cout << "Back: " << tempShort << endl;
	}

	tempList.display(); 



	if (tempList.insert(tempShort))
	{
		tempList.display(); 
		cout << endl;
	}

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (!tempList.isEmpty())
	{
		cout << "The list is not empty." << endl;
	}

	tempShort = 7; 
	tempList.insert(tempShort); 

	tempShort = 6; 
	tempList.insert(tempShort);

	tempShort = 9;
	tempList.insert(tempShort); 

	tempList.display(); 
	cout << endl;

	tempShort = 10; 

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	} 

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	} 

	tempShort = 8; 

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	} 

	tempShort = 4; 

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	}






	if (tempList.viewFront(tempShort))
	{
		cout << "Front: " << tempShort << endl;
	}

	if (tempList.viewRear(tempShort))
	{
		cout << "Back: " << tempShort << endl;
	} 

	numVal = tempList.getNumValues();
	cout << "Number of values in the list is: " << numVal << endl; 

	if (tempList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}

	if (tempList.isFull())
	{
		cout << "The list is not full" << endl; 
	} 





	tempShort = 6;

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	}

	tempShort = 9;

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	}

	tempShort = 5;

	if (tempList.retrieve(tempShort))
	{
		cout << "Value retrieved: " << tempShort << endl;
	}

	if (tempList.remove(tempShort))
	{
		cout << "Value removed: " << tempShort << endl;
	}



	tempList.display(); 
	cout << endl;

	tempList.~LList();

	if (tempList.isEmpty())
	{
		cout << "The list is empty." << endl;
	}

	return 0;
}

//**************************************************************************************************** 

/*

Number of values in the list is: 0
The list is empty.
The list is not full.
5
Value retrieved: 5
The list is not empty.
5 6 7 9
Front: 5
Back: 9
Number of values in the list is: 4
Value retrieved: 6
Value removed: 6
Value retrieved: 9
Value removed: 9
Value retrieved: 5
Value removed: 5
7
The list is empty.

*/