//****************************************************************************************************
//
//         File:                        Staff.h
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
//         This program creates Employee collection class for delearship.
//
//
//****************************************************************************************************
#ifndef STAFF_H
#define STAFF_H

#include "Manager.h" 
#include "FinicalManager.h" 
#include "Salesman.h"
#include "ServiceTechnition.h"

//****************************************************************************************************

class Staff
{
	private:
		int numEmployees; 
		Manager* manager; 
		FinicalManager* finicalManager;
		std::vector <Employee *> salesmen;
		std::vector<Employee *> serviceTechnitions;

	public:
		Staff(); 
		int getNumEmployees() const; 
		Manager getManager() const;
		FinicalManager getFinicalManager() const;
		void setManager(Manager& currManager); 
		void setFinicalManager(FinicalManager& currManager);
		void addItem(Employee * emp);
		void addItem(std::vector<Employee *>& emps, Employee * emp);
		int searchItem(Employee * emp); 
		int searchItem(std::vector <Employee *>& emps, Employee * emp);
		bool deleteItem(Employee * emp);
		bool deleteItem(std::vector<Employee *>& emps, Employee * emp);
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const Staff& staffDisplayed);

//****************************************************************************************************

inline 
int Staff::getNumEmployees() const
{
	return numEmployees;
}

//****************************************************************************************************

inline 
Manager Staff::getManager() const 
{ 
	return *manager;
}


//****************************************************************************************************

inline 
FinicalManager Staff::getFinicalManager() const 
{ 
	return *finicalManager;
}

//****************************************************************************************************
#endif