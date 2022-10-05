#include "AVLTree.h"
#include "Stock.h" 
#include <random> 
#include <iostream> 
#include <fstream>

using namespace std; 

//****************************************************************************************************

void nameDisplay(const AVLTree<Stock>& stockTree)
{
	string sym;
	Stock sample;
	Stock * found;
	cout << "Enter sym:";
	cin >> sym;

	sample = Stock(" ", sym);

	found = stockTree.search(sample);

	if (found == nullptr)
	{
		cout << "Sym could not find stock. Please try again.\n";
	}
	else
	{
		cout << found->getName() << " was found!" << endl;
	}

}

//****************************************************************************************************

void priceDisplay(const AVLTree<Stock>& stockTree)
{
	string sym;
	Stock sample;
	Stock * found;
	cout << "Enter sym:";
	cin >> sym;

	sample = Stock(" ", sym);

	found = stockTree.search(sample);

	if (found == nullptr)
	{
		cout << "Sym could not find stock. Please try again.\n";
	}
	else
	{
		cout << found->getPrice() << " was found!" << endl;
	}

}

//****************************************************************************************************

void insertStock(AVLTree<Stock>& stockTree)
{
	string name;
	string sym;
	double price;
	Stock s;

	cout << "Enter name of stock: ";
	cin >> name;
	cout << "Enter symbol of stock: ";
	cin >> sym;
	cout << "Enter price of stock: ";
	cin >> price;
	s = Stock(name, sym, price);
	stockTree.insert(s);
}

//****************************************************************************************************

void display(const AVLTree<Stock>& stockTree)
{
	stockTree.inorder(cout);
}

//****************************************************************************************************

void quit(const AVLTree<Stock>& stockTree)
{
	ofstream output;
	output.open("Stock.txt");

	stockTree.inorder(output);
	output.close();
}

//****************************************************************************************************

int getChoice(AVLTree<Stock>& stockTree)
{
	int c = 0;
	cout << "1. Give sym to display name" << endl;
	cout << "2. Give sym to display price" << endl;
	cout << "3. Insert a new stock" << endl;
	cout << "4. Display all stocks" << endl;
	cout << "5. Quit" << endl << endl;

	cout << "Enter choice: ";
	cin >> c;

	switch (c)
	{
	case 1:
		nameDisplay(stockTree);
		break;
	case 2:
		priceDisplay(stockTree);
		break;
	case 3:
		insertStock(stockTree);
		break;
	case 4:
		display(stockTree);
		break;
	case 5:
		quit(stockTree);
		break;
	default:
		cout << "Choice does not match options. Please try again \n";
	}

	return c;
}

//****************************************************************************************************

int main()
{
	AVLTree<int> intAVL = AVLTree<int>(); 
	AVLTree<Stock> stockAVL = AVLTree<Stock>();
	ifstream input;

	string name;
	string sym;
	double price;
	Stock placeHold;
	bool flag = true;
	int choice;

	for (int i = 0; i < 10; i++)
	{
		intAVL.insert(rand() % 5000 + 1);
	} 

	intAVL.inorder(cout); 
	cout << endl;  
	intAVL.postorder(cout); 
	cout << endl; 
	intAVL.preorder(cout);  
	cout << endl; 

	cout << "Height of tree: " << intAVL.height() << endl;
	input.open("Stock.txt");

	if (input)
	{
		while (getline(input, name))
		{
			placeHold.setName(name);
			getline(input, sym);
			placeHold.setSymbol(sym);
			input >> price;
			placeHold.setPrice(price);
			input.ignore();
			stockAVL.insert(placeHold);
		}
	}
	input.close();

	while (flag)
	{
		choice = getChoice(stockAVL);
		if (choice == 5)
		{
			flag = false;
		}
	}

	return 0;
}

//****************************************************************************************************

/* 

42 BFactor: -1
725 BFactor: 0
1335 BFactor: -1
1479 BFactor: 0
1501 BFactor: 0
1963 BFactor: 0
3468 BFactor: 0
4170 BFactor: 0
4359 BFactor: 0
4465 BFactor: 0

725 BFactor: 0
42 BFactor: -1
1479 BFactor: 0
1963 BFactor: 0
1501 BFactor: 0
4170 BFactor: 0
4465 BFactor: 0
4359 BFactor: 0
3468 BFactor: 0
1335 BFactor: -1

1335 BFactor: -1
42 BFactor: -1
725 BFactor: 0
3468 BFactor: 0
1501 BFactor: 0
1479 BFactor: 0
1963 BFactor: 0
4359 BFactor: 0
4170 BFactor: 0
4465 BFactor: 0

Height of tree: 4
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 4
Apple/AAPL/121.73 BFactor: 0
Advanced Micro Devices/AMD/84.51 BFactor: 0
Ford Motor/F/11.7 BFactor: 0
General Electric/GE/12.54 BFactor: -1
Intel/INTC/60.78 BFactor: 0
Coca-Cola/KO/64 BFactor: 0
Microsoft Corp./MSFT/28.11 BFactor: 0
NVIDIA/NVDA/548.58 BFactor: 0
Sony/SNE/105.81 BFactor: -1
Tesla/TSLA/564.33 BFactor: 0
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 0
Choice does not match options. Please try again
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 1
Enter sym:uds
Sym could not find stock. Please try again.
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 1
Enter sym:APPL
Sym could not find stock. Please try again.
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 1
Enter sym:AAPL
Apple was found!
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 2
Enter sym:AMD
84.51 was found!
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 3
Enter name of stock: Toyota
Enter symbol of stock: TOY
Enter price of stock: 87.3
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 4
Apple/AAPL/121.73 BFactor: 0
Advanced Micro Devices/AMD/84.51 BFactor: 0
Ford Motor/F/11.7 BFactor: 0
General Electric/GE/12.54 BFactor: -1
Intel/INTC/60.78 BFactor: 0
Coca-Cola/KO/64 BFactor: 0
Microsoft Corp./MSFT/28.11 BFactor: 0
NVIDIA/NVDA/548.58 BFactor: 0
Sony/SNE/105.81 BFactor: 0
Toyota/TOY/87.3 BFactor: 0
Tesla/TSLA/564.33 BFactor: 0
1. Give sym to display name
2. Give sym to display price
3. Insert a new stock
4. Display all stocks
5. Quit

Enter choice: 5


*/