//****************************************************************************************************
//
//         File:                        Manager.h
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
//         This program creates Manager class.
//
//
//****************************************************************************************************
#ifndef MANAGER_H 
#define MANAGER_H 

#include "Employee.h"

//****************************************************************************************************

class Manager : public Employee
{
	protected:
		std::string phoneNum; 
		std::string email;

	public:
		Manager(Name emp, double rate, std::string phone, std::string email);
		std::string getPhone() const; 
		std::string getEmail() const; 
		void setPhone(const std::string& p); 
		void setEmail(const std::string& e); 
		virtual void calculatePay();
		virtual void shutDown(std::ofstream& outputFile);
};

//****************************************************************************************************

inline 
std::string Manager::getPhone() const
{
	return phoneNum;
}

//****************************************************************************************************

inline 
std::string Manager::getEmail() const
{
	return email;
}

//****************************************************************************************************

inline 
void Manager::setPhone(const std::string& p)
{
	phoneNum = p;
}

//****************************************************************************************************

inline 
void Manager::setEmail(const std::string& e)
{
	email = e;
}

//****************************************************************************************************
#endif