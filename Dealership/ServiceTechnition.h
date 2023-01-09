//****************************************************************************************************
//
//         File:                        ServiceTechnition.h
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
//         This program creates ServiceTechnition class.
//
//
//****************************************************************************************************
#ifndef SERVICETECHNITION_H
#define SERVICETECHNITION_H 

#include "Employee.h"
#include "WorkOrder.h"
#include "PartOrder.h"

//****************************************************************************************************

class ServiceTechnition : public Employee
{
	protected: 
		std::string role;
		std::vector<WorkOrder *> currentOrders; 
		std::vector<PartOrder *> ordersPlaced;
		virtual void calculatePay();
		virtual void shutDown(std::ofstream& outputFile);

	public:
		ServiceTechnition(Name emp, double rate, std::string role);
		std::string getRole() const; 
		void setRole(const std::string& r); 
		void addWorkOrder(WorkOrder * wo); 
		void addPartOrder(PartOrder * po);
};

//****************************************************************************************************

inline 
std::string ServiceTechnition::getRole() const
{
	return role;
}

//****************************************************************************************************

inline 
void ServiceTechnition::setRole(const std::string& r)
{
	role = r;
}

//****************************************************************************************************

inline 
void ServiceTechnition::addWorkOrder(WorkOrder * wo)
{
	currentOrders.push_back(wo);
}

//****************************************************************************************************

inline 
void ServiceTechnition::addPartOrder(PartOrder * po)
{
	ordersPlaced.push_back(po);
}

//****************************************************************************************************
#endif 