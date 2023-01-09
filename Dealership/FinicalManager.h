//****************************************************************************************************
//
//         File:                        FinicalManger.h
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
//         This program creates FinicalManger class.
//
//
//****************************************************************************************************
#ifndef FINICALMANAGER_H
#define FINICALMANAGER_H 

#include "Employee.h"
#include "Loan.h"
#include <vector>

class FinicalManager : public Employee
{
	protected:
		std::string phoneNum;
		std::string email;
		std::vector<LoanPolicy *> policies; 
		std::vector<Loan *> loansCreated;

	public:
		FinicalManager(Name emp, double rate, std::string phone, std::string email);
		std::string getPhone() const;
		std::string getEmail() const;
		void setPhone(const std::string& p);
		void setEmail(const std::string& e);
		void addPolicy(LoanPolicy * p); 
		void addLoan(Loan * l);
		virtual void calculatePay(); 
		virtual void shutDown(std::ofstream& outputFile);
};

//****************************************************************************************************

inline
std::string FinicalManager::getPhone() const
{
	return phoneNum;
}

//****************************************************************************************************

inline
std::string FinicalManager::getEmail() const
{
	return email;
}

//***************************************************************************************************

inline
void FinicalManager::setPhone(const std::string& p)
{
	phoneNum = p;
}

//****************************************************************************************************

inline
void FinicalManager::setEmail(const std::string& e)
{
	email = e;
}

//****************************************************************************************************

inline 
void FinicalManager::addLoan(Loan * l)
{
	loansCreated.push_back(l);
}

//****************************************************************************************************

inline 
void FinicalManager::addPolicy(LoanPolicy * p)
{
	policies.push_back(p);
}

//****************************************************************************************************
#endif