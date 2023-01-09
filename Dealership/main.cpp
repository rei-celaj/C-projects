//****************************************************************************************************
//
//         File:                        main.cpp
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Term Project
//
//         Course LoanPolicy:           Object Oriented Analysis and Design
//
//         Course Number:               COSC 4250 - 01
//
//         Due:                         N/A
//
//
//         This program creates a driver for classes.
//
//
//****************************************************************************************************

#include "Dealership.h"
#include <iostream>

using namespace std;

//****************************************************************************************************

vector<Customer> customers;
vector<Loan> loans;
vector<LoanPolicy> policies; 
Dealership dp("Swans", "8731 Market Drive", "912-234-1321");


//****************************************************************************************************

void displayMenu()
{
	cout << "MAIN MENU" << endl << "1: Create a customer" << endl <<
		"2: Create a Loan" << endl << "3: Create LoanPolicy" << endl <<
		"4: Add Loan to customer" << endl << "5: Test cars" << 
		endl << "6: Display list" << endl << "7: Exit" << endl;
}

//****************************************************************************************************

void addCustomer()
{
	string first,
		last,
		phone;

	cout << "Enter first name: ";
	cin >> first;

	cout << "Enter last name: ";
	cin >> last;

	Name name(first, last);

	cout << "Enter Phone: ";
	cin >> phone;

	Customer customerA(name, phone);

	customers.push_back(customerA);
	cout << "Customer has been added." << endl << endl;
}

//****************************************************************************************************

void addLoan()
{
	int num;

	string description;

	cout << "Which policy do you want: ";
	cin >> num;

	cout << "Enter loan description: "; 
	cin.ignore();
	getline(cin, description);

	try
	{
		Loan loanA(description, policies[num - 1]);
		loans.push_back(loanA);
		cout << "Loan has been added." << endl << endl;
	} 
	catch (exception e)
	{
		cout << "Policy is not on the list. Try again" << endl;
	}
}

//****************************************************************************************************

void testCars()
{
	Vehicle * s = new Truck();
	Vehicle * l = new Sedan();
	Vehicle * a = new SUV();

	dp.addCar(s); 
	dp.addCar(l);
	dp.addCar(a);

	cout << "SUV index: " << dp.searchCar(a) << " Truck Index: " << dp.searchCar(s) 
		 << " Sedan Index: " << dp.searchCar(l) << "\n"; 

	s->display();
	l->display(); 
	a->display();

	if (dp.deleteCar(s))
	{
		cout << "Truck deleted!" << endl;
	}

	if (dp.deleteCar(l))
	{
		cout << "Sedan deleted!" << endl;
	}

	if (dp.deleteCar(a))
	{
		cout << "SUV deleted!" << endl;
	}

	s = new Truck();

	if (dp.deleteCar(s))
	{
		cout << "Truck deleted!" << endl;
	}

}

void addPolicy()
{
	string description;
	double rate;
	int time;

	cout << "Enter Loan policy description: ";
	cin.ignore();
	getline(cin, description);

	cout << "Enter rate: ";
	cin >> rate;

	cout << "Enter time length: ";
	cin >> time;

	LoanPolicy policy(description, rate, time);

	policies.push_back(policy);
	cout << "Polices has been added." << endl << endl;
}

//****************************************************************************************************

void addLoanToCustomer()
{
	int num,
		num2;

	cout << "Which loan do you want: ";
	cin >> num;

	cout << "Which customer do you want for the loan: ";
	cin >> num2;

	customers[num - 1].insertLoan(loans[num2 - 1]);

	cout << "Loan has been added to customer." << endl << endl;
}

//****************************************************************************************************

void displayData()
{
	vector<Customer>::iterator it1;
	vector<Loan>::iterator it2;
	vector<LoanPolicy>::iterator it3;

	cout << "Customers" << endl;

	for (it1 = customers.begin(); it1 < customers.end(); it1++)
	{
		cout << *it1 << endl;
	}

	cout << "Loans" << endl;

	for (it2 = loans.begin(); it2 < loans.end(); it2++)
	{
		cout << *it2 << endl;
	}

	cout << "Loan Policies" << endl;

	for (it3 = policies.begin(); it3 < policies.end(); it3++)
	{
		cout << *it3 << endl;
	}
}

//****************************************************************************************************

bool getInput()
{
	int input;
	bool flag = true;

	cout << "Enter a number: ";
	cin >> input;

	switch (input)
	{
	case 1:
		addCustomer();
		break;
	case 2:
		addLoan();
		break;
	case 3:
		addPolicy();
		break;
	case 4:
		addLoanToCustomer();
		break;
	case 5:
		testCars();
		break;
	case 6:
		displayData();
		break; 
	case 7:
		flag = false;
		break;
	default: 
		break;
	}
	return flag;
}

//****************************************************************************************************

int main()
{
	/*
	
	Main tests functions from classes 
	Cannot test collections yet due to 
	classes needing inheritance
	
	*/ 

	
	bool flag = true; 

	while (flag)
	{
		displayMenu(); 
		flag = getInput();
	}
	

	return 0;
} 

/*

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 1
Enter first name: Dan
Enter last name: Smith
Enter Phone: 314-719-9731
Customer has been added.

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 3
Enter Loan policy description: Dang policy
Enter rate: .3
Enter time length: 5
Polices has been added.

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 2
Which policy do you want: 1
Enter loan description: Dang loan
Loan has been added.

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 4
Which loan do you want: 1
Which customer do you want for the loan: 1
Loan has been added to customer.

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 5
Customers
Customer Name: Dan Smith
Customer Phone: 314-719-9731
10
Dang loan
Dang policy
0.300000
5

Loans
10
Dang loan
Dang policy
Loan Rate: 0.3
Loan Duration: 5

Loan Policies
Dang policy
Loan Rate: 0.3
Loan Duration: 5

MAIN MENU
1: Create a customer
2: Create a Loan
3: Create LoanPolicy
4: Add Loan to customer
5: Display data
6: Exit
Enter a number: 6


*/