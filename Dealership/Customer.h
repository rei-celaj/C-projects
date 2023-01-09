//****************************************************************************************************
//
//         File:                        Customer.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Term Project
//
//         Course Name:                 Object Oriented Analysis and Design
//
//         Course Number:               COSC 4250 - 01
//
//         Due:                         N/A
//
//
//         This program creates Customer class.
//
//
//**************************************************************************************************** 

#ifndef Customer_H
#define Customer_H

#include "Name.h" 
#include "Loan.h"  
#include <vector> 
#include <iterator>

//**************************************************************************************************** 

class Customer
{
	private:
		static int counter;
		int id; 
		Name name; 
		std::string phone;  
		std::vector<Loan *> loans;

	public: 
		Customer(Name name = Name(), std::string phone = "111-111-1111");  
		Name getCustName() const; 
		std::string getPhoneNum() const; 
		void setId(const int& id); 
		void setName(const Name& name); 
		void setPhone(const std::string& phone); 
		bool isFull() const;
		bool insertLoan(Loan& loan);  
		int searchLoan(const LoanPolicy& loanPol) const; 
		std::string printLoans() const;
		bool deleteLoan(const LoanPolicy& loanPol);
		bool operator==(const Customer& rhs) const;
		bool operator!=(const Customer& rhs) const;
		bool operator<(const Customer& rhs) const;
		bool operator>(const Customer& rhs) const;
		bool operator<=(const Customer& rhs) const;
		bool operator>=(const Customer& rhs) const;
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const Customer& customerDisplayed);

//**************************************************************************************************** 

inline 
Name Customer::getCustName() const
{
	return name; 
}

//**************************************************************************************************** 

inline 
std::string Customer::getPhoneNum() const
{
	return phone;
}

//**************************************************************************************************** 

inline 
void Customer::setId(const int& i)
{
	id = i;
}

//**************************************************************************************************** 

inline 
void Customer::setName(const Name& s) 
{
	name = s;
}

//**************************************************************************************************** 

inline 
void Customer::setPhone(const std::string& p)
{
	phone = p;
}

//**************************************************************************************************** 

inline
bool Customer::operator==(const Customer& rhs) const
{
	return (this->name == rhs.name);
}

//****************************************************************************************************

inline
bool Customer::operator!=(const Customer& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************

inline
bool Customer::operator<(const Customer& rhs) const
{
	return !(*this >= rhs);
}

//***************************************************************************************************

inline
bool Customer::operator>(const Customer& rhs) const
{
	return !(*this <= rhs);
}

//****************************************************************************************************

inline
bool Customer::operator<=(const Customer& rhs) const
{
	return (this->name <= rhs.name);
}

//****************************************************************************************************

inline
bool Customer::operator>=(const Customer& rhs) const
{
	return (this->name >= rhs.name);
}

//**************************************************************************************************** 
#endif