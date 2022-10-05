#ifndef NODE_H 
#define NODE_H 

//****************************************************************************************************

template<typename TYPE>
struct Node
{
	TYPE data;
	Node<TYPE> * right;
	Node<TYPE> * left;

	Node();
	Node(TYPE d, Node<TYPE> * r = nullptr, Node<TYPE> * l = nullptr);
};

//****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node()
{
	right = nullptr;
	left = nullptr;
}

//****************************************************************************************************

template<typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE> * r, Node<TYPE> * l)
{
	data = d;
	right = r;
	left = l;
}

//****************************************************************************************************
#endif 