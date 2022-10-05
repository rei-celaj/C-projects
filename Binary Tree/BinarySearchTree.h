#ifndef BINARY_H
#define BINARY_H  

#include <iostream>
#include "Node.h"

template <typename TYPE>
class BinarySearchTree
{
	private: 
		Node<TYPE>* root; 
		void destroy(Node<TYPE>*& r); 
		void insert(Node<TYPE> *& r, const TYPE& item);
		void inorder(Node<TYPE>* r, std::ostream& os) const;
		void preorder(Node<TYPE>* r, std::ostream& os) const;  
		void postorder(Node<TYPE>* r, std::ostream& os) const; 
		TYPE* search(Node<TYPE> * r, const TYPE& item) const; 
		void searchD(const TYPE& item, bool& found, 
			Node<TYPE>*& locPtr, Node<TYPE>* prev) const; 
		int max(int one, int two) const;  
		int height(Node<TYPE>* r) const;

	public: 
		BinarySearchTree();
		~BinarySearchTree();
		void insert(const TYPE& data); 
		void inorder(std::ostream& os) const; 
		void preorder(std::ostream& os) const;
		void postorder(std::ostream& os) const;
		void deleteNode(const TYPE& item); 
		TYPE* search(const TYPE& item) const; 
		int height() const;  
};

//****************************************************************************************************

template <typename TYPE>
BinarySearchTree<TYPE>::BinarySearchTree()
{
	root = nullptr; 
}

//****************************************************************************************************

template <typename TYPE>
BinarySearchTree<TYPE>::~BinarySearchTree()
{
	destroy(root);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::destroy(Node<TYPE>*& r)
{
	if (r != nullptr)
	{
		destroy(r -> left); 
		destroy(r -> right);  
		delete r;
		r = nullptr;
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::insert(const TYPE& item)
{
	insert(root, item);
} 

//****************************************************************************************************

template <typename TYPE> 
void BinarySearchTree<TYPE>::insert(Node<TYPE>*& r, const TYPE& item)
{
	if (r == nullptr)
	{
		r = new Node<TYPE>(item); 
	} 
	else if (item < r -> data)
	{
		insert(r -> left, item);
	} 
	else if (item > r->data)
	{
		insert(r->right, item);
	}
	else
	{
		std::cout << "Duplicate" << std::endl;
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::inorder(std::ostream& os) const
{
	inorder(root, os);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::inorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inorder(r->left, os);
		os << r->data << std::endl;
		inorder(r->right, os);
	}
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::preorder(std::ostream& os) const
{
	preorder(root, os);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::preorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		os << r->data << std::endl; 
		preorder(r -> left, os); 
		preorder(r -> right, os);
	}
}

//**************************************************************************************************** 

template <typename TYPE>
void BinarySearchTree<TYPE>::postorder(std::ostream& os) const
{
	postorder(root, os);
}

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::postorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		postorder(r->left, os);
		postorder(r->right, os);
		os << r->data << std::endl;
	}
}

//**************************************************************************************************** 

template <typename TYPE>
TYPE * BinarySearchTree<TYPE>::search(const TYPE& item) const
{
	TYPE * found = search(root, item); 
	return found;
} 

//****************************************************************************************************

template <typename TYPE>
TYPE * BinarySearchTree<TYPE>::search(Node<TYPE> * r, const TYPE& item) const
{
	TYPE * found;

	if (r == nullptr)
	{
		found = nullptr; 
	} 
	else if (item < r -> data)
	{
		found = search(r -> left, item);
	} 
	else if (item > r -> data)
	{
		found = search(r -> right, item);
	} 
	else
	{
		found = new TYPE(r -> data);
	} 

	return found;
} 

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::searchD(const TYPE& item, bool& found,
	Node<TYPE>*& locPtr, Node<TYPE>* prev) const
{
	locPtr = root; 
	prev = nullptr; 
	found = false; 

	while ((!found) && (locPtr != nullptr))
	{
		if (item < locPtr -> data)
		{
			prev = locPtr; 
			locPtr = locPtr -> left;
		} 
		else if (item > locPtr->data)
		{
			prev = locPtr;
			locPtr = locPtr->right;
		} 
		else
		{
			found = true;
		}
	}
} 

//****************************************************************************************************

template <typename TYPE>
void BinarySearchTree<TYPE>::deleteNode(const TYPE& item)
{
	Node<TYPE>* current; 
	Node<TYPE>* parent = nullptr;  
	bool found; 

	searchD(item, found, current, parent);

	if (!found)
	{
		std::cout << "item not in tree" << std::endl; 
	} 
	else
	{
		if ((current -> left != nullptr) && (current-> right != nullptr))
		{
			Node<TYPE>* currentSucc = current -> right;
			parent = current;  

			while (currentSucc->left != nullptr)
			{
				parent = currentSucc;
				currentSucc = currentSucc->left;
			} 
			current -> data = currentSucc -> data; 
			current = currentSucc;
		}


		Node<TYPE>* sub = current -> left; 
		if (sub == nullptr)
		{
			sub = current -> right;
		} 
		
		if (parent == nullptr)
		{
			root = sub; 
		} 
		else if (parent -> left == current)
		{
			parent -> left = sub; 
		} 
		else
		{
			parent -> right = sub;
		} 

		delete current;
	} 
}

//****************************************************************************************************

template <typename TYPE>
int BinarySearchTree<TYPE>::max(int one, int two) const
{
	return (one > two) ? one : two;
}

//****************************************************************************************************

template <typename TYPE>
int BinarySearchTree<TYPE>::height(Node<TYPE>* r) const
{
	if (r == nullptr)
	{
		return 0;
	} 
	else
	{
		return 1 + max(height(r -> left), height(r -> right));
	}
}

//**************************************************************************************************** 

template <typename TYPE>
int BinarySearchTree<TYPE>::height() const
{
	int h = height(root); 
	return h;
}
#endif