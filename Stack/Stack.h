//****************************************************************************************************
//
//         File:                        Stack.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Program  # 6
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         March 6, 2021
//
//
//         This program shows how to make a Stack.
//
//
//**************************************************************************************************** 

#ifndef STACK_H 
#define STACK_H 

#include <new>

//****************************************************************************************************

template<typename TYPE>
class Stack
{

	private:
		int capacity; 
		TYPE * stack; 
		int top;

	public:
		Stack(int cap = 40);
		~Stack();  
		bool push(const TYPE & dataIn); 
		bool pop(TYPE & dataOut); 
		bool peek(TYPE & dataOut); 
		int getNumValues(); 
		bool isFull();
		bool isEmpty(); 
};

//**************************************************************************************************** 

template<typename TYPE>
Stack<TYPE>::Stack(int cap)
{
	capacity = cap; 
	top = -1; 
	stack = new TYPE[capacity];
}

//****************************************************************************************************  

template<typename TYPE>
Stack<TYPE>::~Stack()
{
	TYPE * tempStack = new TYPE[capacity];
	delete[] stack; 
	stack = tempStack; 
	top = -1;
}

//****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::push(const TYPE & dataIn)
{
	bool success = false; 

	if (top + 1 < capacity)
	{
		top++; 
		stack[top] = dataIn; 
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::pop(TYPE & dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top]; 
		top--; 
		success = true;
	}

	return success;
}

//****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::peek(TYPE & dataOut)
{
	bool success = false;

	if (top > -1)
	{
		dataOut = stack[top];
		success = true;
	}

	return success;
}

//**************************************************************************************************** 

template<typename TYPE>
int Stack<TYPE>::getNumValues()
{
	return (top + 1);
}

//****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isFull()
{
	return (top + 1 == capacity);
}

//****************************************************************************************************

template<typename TYPE>
bool Stack<TYPE>::isEmpty()
{
	return (top == -1);
}

//**************************************************************************************************** 
#endif