//****************************************************************************************************
//
//         File:                        Employee.h
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
//         This program creates Employee class.
//
//
//**************************************************************************************************** 
#ifndef EMPLOYEE_H 
#define EMPLOYEE_H 

#include "Name.h"

//**************************************************************************************************** 

class Employee
{
	protected:
		static int counter; 
		int id;
		Name empName; 
		double payRate;
		std::string type;
		virtual void calculatePay() = 0;

	public:
		Employee(Name emp, double rate);
		int getId() const; 
		Name getName() const; 
		double getRate() const; 
		std::string getType() const;
		void setName(const Name& n); 
		void setRate(const double& r);
		virtual bool operator==(const Employee& rhs) const;
		virtual bool operator!=(const Employee& rhs) const;
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int Employee::getId() const
{
	return id;
}

//**************************************************************************************************** 

inline 
Name Employee::getName() const
{
	return empName;
}

//**************************************************************************************************** 

inline 
double Employee::getRate() const
{
	return payRate;
}

//**************************************************************************************************** 

inline 
std::string Employee::getType() const
{
	return type;
}

//**************************************************************************************************** 

inline 
void Employee::setName(const Name& n)
{
	empName = n;
}

//**************************************************************************************************** 

inline 
void Employee::setRate(const double& r)
{
	payRate = r;
}

//****************************************************************************************************

inline 
bool Employee::operator==(const Employee& rhs) const
{
	return this->empName == rhs.empName;
}

//****************************************************************************************************

inline 
bool Employee::operator!=(const Employee& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************
#endif
