//****************************************************************************************************
//
//         File:                        SUV.h
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
//         This program creates Truck class.
//
//
//**************************************************************************************************** 
#ifndef TRUCK_H 
#define TRUCK_H

#include "Vehicle.h"

//**************************************************************************************************** 

class Truck : public Vehicle
{
	protected:
		std::string flatbedType; 
		std::string engineType; 
		std::string varient;

	public: 
		Truck(std::string ma = "Toyota", std::string mo = "Tundra", int miles = 0, int price = 30000, 
			std::string ft = "regular", std::string et = "V6", std::string v = "XL");
		std::string getFlatBed() const; 
		std::string getEngine() const; 
		std::string getVarient() const; 
		void setFlatBed(const std::string& f); 
		void setEngine(const std::string& e); 
		void setVarient(const std::string& v);
		virtual void calculatePrice();
		bool operator==(Vehicle * rhs) const; 
		bool operator!=(Vehicle * rhs) const; 
		virtual void display();
		virtual void shutDown(std::ofstream& outputFile);
};


//**************************************************************************************************** 

inline 
std::string Truck::getFlatBed() const
{
	return flatbedType;
}

//**************************************************************************************************** 

inline 
std::string Truck::getEngine() const
{
	return engineType; 
}

//**************************************************************************************************** 

inline
std::string Truck::getVarient() const
{
	return varient;
}

//**************************************************************************************************** 

inline 
void Truck::setFlatBed(const std::string& f)
{
	flatbedType = f;
}

//**************************************************************************************************** 

inline 
void Truck::setEngine(const std::string& e)
{
	engineType = e;
}

//**************************************************************************************************** 

inline 
void Truck::setVarient(const std::string& v)
{
	varient = v;
}

//**************************************************************************************************** 
#endif