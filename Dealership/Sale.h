//****************************************************************************************************
//
//         File:                        Sale.h
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
//         This program creates Sale class.
//
//
//****************************************************************************************************
#ifndef SALE_H 
#define SALE_H

#include "Customer.h"
#include "Truck.h" 
#include "Sedan.h"
#include "SUV.h"
#include <ctime>

//****************************************************************************************************

class Sale
{
	private:
		static int counter; 
		int id;
		double total; 
		tm sellDate; 
		Customer* buyer; 
		std::vector<Vehicle *> cars;

	public:
		Sale(Customer cust, double total = 0, tm date = tm());
		int getId() const; 
		double getTotal() const; 
		tm getDate() const; 
		void setTotal(const double& t); 
		void setDate(const tm& d); 
		void addCar(Vehicle * v);
		void shutDown(std::ofstream& outputFile);
};

//****************************************************************************************************

inline
int Sale::getId() const
{
	return id;
}

//****************************************************************************************************

inline
double Sale::getTotal() const
{
	return total;
}

//****************************************************************************************************

inline
tm Sale::getDate() const
{
	return sellDate;
}

//****************************************************************************************************

inline
void Sale::setTotal(const double& t)
{
	total = t;
}

//****************************************************************************************************

inline
void Sale::setDate(const tm& d)
{
	sellDate = d;
}

//****************************************************************************************************

inline
void Sale::addCar(Vehicle * c)
{
	cars.push_back(c);
}

//****************************************************************************************************
#endif 