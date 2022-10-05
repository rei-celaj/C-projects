//****************************************************************************************************
//
//         File:                        Node.h
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
//         This program shows how to make a Node struct.
//
//
//**************************************************************************************************** 

#ifndef NODE_H 
#define NODE_H 

//****************************************************************************************************

template<typename TYPE> 
struct Node
{
	TYPE data; 
	Node<TYPE> *next; 

	Node(); 
	Node(TYPE d, Node<TYPE> * n = nullptr);
};

//****************************************************************************************************

template<typename TYPE> 
Node<TYPE>::Node()
{
	data = 0; 
	next = nullptr; 
}

//****************************************************************************************************

template<typename TYPE> 
Node<TYPE>::Node(TYPE d, Node<TYPE> * n)
{
	data = d; 
	next = n;
}

//****************************************************************************************************
#endif 