#ifndef AVLTREE_H 
#define AVLTREE_H

#include "Node.h"
#include <iostream>

//****************************************************************************************************

template<typename TYPE> 
class AVLTree
{
	private:
		Node<TYPE>* root;
		void destroy(Node<TYPE>*& r);
		void rotateLeft(Node<TYPE>*& r1);
		void rotateRight(Node<TYPE>*& r1);
		int getBalance(Node<TYPE>* r) const;
		void updateBfactors(Node<TYPE>*& r);
		int max(int a, int b) const;
		int height(Node<TYPE>* r) const; 
		void insert(Node<TYPE>*& r, const TYPE& item);
		void inorder(Node<TYPE>* r, std::ostream& os) const;
		void preorder(Node<TYPE>* r, std::ostream& os) const;
		void postorder(Node<TYPE>* r, std::ostream& os) const;
		TYPE* search(Node<TYPE>* r, const TYPE& item) const;

	public:
		AVLTree(); 
		~AVLTree(); 
		void insert(const TYPE& item);
		int height() const;
		void inorder(std::ostream& os) const; 
		void preorder(std::ostream& os) const; 
		void postorder(std::ostream& os) const; 
		TYPE* search(const TYPE& item) const; 
}; 

//****************************************************************************************************

template<typename TYPE> 
inline
AVLTree<TYPE>::AVLTree()
{
	root = nullptr; 
}

//****************************************************************************************************

template<typename TYPE>
inline
AVLTree<TYPE>::~AVLTree()
{
	destroy(root);
} 

//****************************************************************************************************

template<typename TYPE>
void AVLTree<TYPE>::rotateLeft(Node<TYPE>*& r1)
{
	Node<TYPE>* r2 = r1 -> right;
	r1 -> right = r2 -> left; 
	r2 -> left = r1; 
	r1 = r2;
}

//****************************************************************************************************

template<typename TYPE>
void AVLTree<TYPE>::rotateRight(Node<TYPE>*& r1)
{
	Node<TYPE>* r2 = r1 -> left;
	r1 -> left = r2 -> right;
	r2 -> right = r1;
	r1 = r2;
}

//****************************************************************************************************

template <typename TYPE>
inline
int AVLTree<TYPE>::max(int one, int two) const
{
	return (one > two) ? one : two;
}

//****************************************************************************************************

template<typename TYPE>
inline
int AVLTree<TYPE>::height() const
{
	int h = height(root); 
	return h;
}

//****************************************************************************************************

template<typename TYPE>
int AVLTree<TYPE>::height(Node<TYPE>* r) const
{
	int h = 0;
	if (r != nullptr)
	{
		h = 1 + max(height(r->left), height(r->right)); 
	} 
	return h;
} 

//****************************************************************************************************

template<typename TYPE>
int AVLTree<TYPE>::getBalance(Node<TYPE>* r) const
{
	int balance; 

	if (r == nullptr)
	{
		balance = 0;
	} 
	else
	{
		balance = height(r->left) - height(r->right); 
	} 
	return balance;
}

//**************************************************************************************************** 

template<typename TYPE>
void AVLTree<TYPE>::updateBfactors(Node<TYPE>*& r)
{
	if (r != nullptr)
	{
		r -> bFactor = getBalance(r); 
		updateBfactors(r -> left); 
		updateBfactors(r -> right);
	}
}

//****************************************************************************************************

template<typename TYPE>
void AVLTree<TYPE>::destroy(Node<TYPE>*& r)
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

template<typename TYPE>
inline
void AVLTree<TYPE>::insert(const TYPE& item)
{
	insert(root, item);
}

//****************************************************************************************************

template<typename TYPE>
void AVLTree<TYPE>::insert(Node<TYPE>*& r, const TYPE& item)
{
	if (r == nullptr)
	{
		r = new Node<TYPE>; 
		r -> data = item; 
	} 
	else
	{
		if (item < r -> data)
		{
			insert(r -> left, item);
		} 
		else
		{
			insert(r -> right, item);
		}
	}  
	r -> bFactor = getBalance(r); 
	if (r -> bFactor > 1)
	{
		if ((r->left)->bFactor > 0)
		{
			rotateRight(r);
		} 
		else
		{
			rotateLeft(r->left); 
			rotateRight(r);
		}
		updateBfactors(r);  
	} 
	else if (r->bFactor < -1)
	{
		if ((r->right)->bFactor < 0)
		{
			rotateLeft(r);
		}
		else
		{
			rotateRight(r->right);
			rotateLeft(r);
		}
		updateBfactors(r);
	}
}

//**************************************************************************************************** 

template<typename TYPE>
inline
void AVLTree<TYPE>::inorder(std::ostream& os) const
{
	inorder(root, os);
} 

//**************************************************************************************************** 

template<typename TYPE>
void AVLTree<TYPE>::inorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		inorder(r->left, os);
		os << r->data << " BFactor: " << r->bFactor << std::endl;
		inorder(r->right, os);
	}
} 

//**************************************************************************************************** 

template<typename TYPE>
inline
void AVLTree<TYPE>::preorder(std::ostream& os) const
{
	preorder(root, os);
}

//**************************************************************************************************** 

template<typename TYPE>
void AVLTree<TYPE>::preorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		os << r->data << " BFactor: " << r->bFactor << std::endl;
		preorder(r->left, os);
		preorder(r->right, os);
	}
}

//**************************************************************************************************** 

template<typename TYPE>
inline
void AVLTree<TYPE>::postorder(std::ostream& os) const
{
	postorder(root, os);
}

//**************************************************************************************************** 

template<typename TYPE>
void AVLTree<TYPE>::postorder(Node<TYPE>* r, std::ostream& os) const
{
	if (r != nullptr)
	{
		postorder(r->left, os);
		postorder(r->right, os);
		os << r->data << " BFactor: " << r->bFactor << std::endl;
	}
} 

//****************************************************************************************************

template<typename TYPE> 
TYPE* AVLTree<TYPE>::search(Node<TYPE>* r, const TYPE& item) const
{ 
	TYPE* ans;
	if (r != nullptr)
	{
		if (item > r->data)
		{
			ans = search(r->right, item);
		} 
		else if (item < r->data)
		{
			ans = search(r->left, item);
		} 
		else
		{
			ans = &(r -> data); 
		}
	} 
	else
	{
		ans = nullptr;
	} 
	return ans;
}

//****************************************************************************************************

template <typename TYPE>
TYPE* AVLTree<TYPE>::search(const TYPE& item) const
{
	TYPE* found = search(root, item); 
	return found;
} 

//****************************************************************************************************
#endif