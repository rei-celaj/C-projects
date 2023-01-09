//****************************************************************************************************
//
//         File:                        CarOrder.h
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
//         This program creates CarOrder class.
//
//
//**************************************************************************************************** 
#ifndef CARORDER_H
#define CARORDER_H 

#include "Order.h"
#include "Truck.h" 
#include "Sedan.h" 
#include "SUV.h"
#include <vector>

//**************************************************************************************************** 

class CarOrder : public Order
{
	protected: 
		int deposit;
		std::vector<Vehicle *> cars;
		virtual void holder() {};

	public:
		CarOrder(double total, tm arrival, tm orderd, int deposit);
		int getDeposit() const; 
		void setDeposit(const int& d); 
		void addCar(Vehicle * c);
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int CarOrder::getDeposit() const
{
	return deposit;
}

//**************************************************************************************************** 

inline 
void CarOrder::setDeposit(const int& d)
{
	deposit = d;
} 

//**************************************************************************************************** 

inline
void CarOrder::addCar(Vehicle * c)
{
	cars.push_back(c);
}

//**************************************************************************************************** 
#endif