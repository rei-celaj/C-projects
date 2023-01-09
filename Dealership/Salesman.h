//****************************************************************************************************
//
//         File:                        Salesman.h
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
//         This program creates Salesman class.
//
//
//****************************************************************************************************
#ifndef SALESMAN_H 
#define SALESMAN_H 

#include "Employee.h"
#include "CarOrder.h"
#include "Sale.h"

//****************************************************************************************************

class Salesman : public Employee
{
	protected:
		int commission; 
		std::string phoneNum; 
		std::string email; 
		std::vector<CarOrder *> orders; 
		std::vector<Sale *> sales;

	public:
		Salesman(Name emp, double rate, int commission, 
			std::string phone, std::string email);
		int getCommission() const;
		std::string getPhone() const;
		std::string getEmail() const;
		void setCommission(const int& c);
		void setPhone(const std::string& p);
		void setEmail(const std::string& e); 
		void addCarOrder(CarOrder * ca); 
		void addSale(Sale * s);
		virtual void calculatePay();
		virtual void shutDown(std::ofstream& outputFile);
};

//****************************************************************************************************

inline 
int Salesman::getCommission() const
{
	return commission;
}

//****************************************************************************************************

inline
std::string Salesman::getPhone() const
{
	return phoneNum;
}

//****************************************************************************************************

inline
std::string Salesman::getEmail() const
{
	return email;
}

//****************************************************************************************************

inline 
void Salesman::setCommission(const int& c)
{
	commission = c;
}

//****************************************************************************************************

inline
void Salesman::setPhone(const std::string& p)
{
	phoneNum = p;
}

//****************************************************************************************************

inline
void Salesman::setEmail(const std::string& e)
{
	email = e;
}

//****************************************************************************************************

inline 
void Salesman::addCarOrder(CarOrder * co)
{
	orders.push_back(co);
}

//****************************************************************************************************

inline 
void Salesman::addSale(Sale * s)
{
	sales.push_back(s);
}

//****************************************************************************************************
#endif 