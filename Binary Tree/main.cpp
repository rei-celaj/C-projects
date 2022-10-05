#include "BinarySearchTree.h"  
#include "Stock.h" 
#include <random> 
#include <fstream>

using namespace std; 
 
//****************************************************************************************************

void nameDisplay(const BinarySearchTree<Stock>& stockTree)
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

void priceDisplay(const BinarySearchTree<Stock>& stockTree)
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

void delStock(BinarySearchTree<Stock>& stockTree) 
{
	string sym;
	Stock sample;
	cout << "Enter sym:";
	cin >> sym;

	sample = Stock(" ", sym);

	stockTree.deleteNode(sample);
}

//****************************************************************************************************

void insertStock(BinarySearchTree<Stock>& stockTree)
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

void display(const BinarySearchTree<Stock>& stockTree)
{
	stockTree.inorder(cout);
}

//****************************************************************************************************

void quit(const BinarySearchTree<Stock>& stockTree)
{
	ofstream output;
	output.open("Stock.txt");

	stockTree.inorder(output); 
	output.close();
}

//****************************************************************************************************


int getChoice (BinarySearchTree<Stock>& stockTree)
{
	int c = 0; 
	cout << "1. Give sym to display name" << endl; 
	cout << "2. Give sym to display price" << endl; 
	cout << "3. Remove a stock" << endl;
	cout << "4. Insert a new stock" << endl; 
	cout << "5. Display all stocks" << endl;
	cout << "6. Quit" << endl << endl; 

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
			delStock(stockTree); 
			break;
		case 4: 
			insertStock(stockTree); 
			break;
		case 5: 
			display(stockTree); 
			break;
		case 6: 
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
	BinarySearchTree<int> intTree = BinarySearchTree<int>();
	BinarySearchTree<Stock> stockTree = BinarySearchTree<Stock>();
	ifstream input;

	string name;
	string sym;
	double price;
	Stock placeHold;
	bool flag = true;
	int choice;

	for (int i = 0; i < 10; i++)
	{
		intTree.insert(rand() % 5000 + 1);
	}

	intTree.inorder(cout);
	cout << endl;
	intTree.postorder(cout);
	cout << endl;
	intTree.preorder(cout);
	cout << endl;

	cout << "Height of tree: " << intTree.height() << endl;

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
			stockTree.insert(placeHold);
		}
	}

	input.close();

	while (flag)
	{
		choice = getChoice(stockTree);
		if (choice == 6)
		{
			flag = false;
		}
	}


	return 0;
}
 
//****************************************************************************************************

/* 

42
725
1335
1479
1501
1963
3468
4170
4359
4465

725
1479
1963
1501
1335
4465
4359
4170
3468
42

42
3468
1335
725
1501
1479
1963
4170
4359
4465

Height of tree: 5
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 5
Apple
AAPL
121.73

Advanced Micro Devices
AMD
84.51

Ford Motor
F
11.7

General Electric
GE
12.54

Intel
INTC
60.78

Motorola Inc.
MOT
17.49

Microsoft Corp.
MSFT
28.11

NVIDIA
NVDA
548.58

Sony
SNE
105.81

Tesla
TSLA
564.33

1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 0
Choice does not match options. Please try again
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 1
Enter sym:MSFT
Microsoft Corp. was found!
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 2
Enter sym:AMD
84.51 was found!
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 3
Enter sym:MOT
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 4
Enter name of stock: Coca-Cola
Enter symbol of stock: KO
Enter price of stock: 64
1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 5
Apple
AAPL
121.73

Advanced Micro Devices
AMD
84.51

Ford Motor
F
11.7

General Electric
GE
12.54

Intel
INTC
60.78

Coca-Cola
KO
64

Microsoft Corp.
MSFT
28.11

NVIDIA
NVDA
548.58

Sony
SNE
105.81

Tesla
TSLA
564.33

1. Give sym to display name
2. Give sym to display price
3. Remove a stock
4. Insert a new stock
5. Display all stocks
6. Quit

Enter choice: 6

*/

//****************************************************************************************************