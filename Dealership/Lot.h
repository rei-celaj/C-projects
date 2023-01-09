//****************************************************************************************************
//
//         File:                        Lot.h
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
//         This program creates Lot collection class.
//
//
//****************************************************************************************************
#ifndef LOT_H 
#define LOT_H

#include "SUV.h"
#include "Truck.h"
#include "Sedan.h"
#include <vector>

//****************************************************************************************************
class Lot
{
	private:
		int capacity; 
		int numCars;
		std::vector<Vehicle *> suvs; 
		std::vector<Vehicle *> trucks; 
		std::vector<Vehicle *> sedans;
		bool isFull() const;

	public:
		Lot(int cap = 30, int cars = 0); 
		int getCapacity() const; 
		int getNumCars() const; 
		void setCapacity(const int& cap);
		bool addItem(Vehicle * car);
		void addItem(std::vector<Vehicle *>& coll, Vehicle * c);
		int searchItem(Vehicle * car); 
		int searchItem(std::vector<Vehicle *>& v, Vehicle * car);
		bool deleteItem(Vehicle * car); 
		bool deleteItem(std::vector<Vehicle *>& v, Vehicle * car); 
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const Lot& LotDisplayed);

//****************************************************************************************************

inline
int Lot::getCapacity() const
{
	return capacity;
}

//****************************************************************************************************

inline
int Lot::getNumCars() const
{
	return numCars;
}

//****************************************************************************************************

inline 
void Lot::setCapacity(const int& cap)
{
	capacity = cap;
}

//****************************************************************************************************

inline 
bool Lot::isFull() const
{
	return capacity == numCars;
}
//****************************************************************************************************
#endif