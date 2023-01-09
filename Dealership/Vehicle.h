//****************************************************************************************************
//
//         File:                        Loan.h
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
//         This program creates Vehicle class.
//
//
//**************************************************************************************************** 
#ifndef VEHICLE_H 
#define VEHICLE_H 

#include <string>
#include <iostream>
#include <fstream>

//**************************************************************************************************** 

class Vehicle
{
	protected:
		static int counter; 
		int id;
		std::string make; 
		std::string model;
		int numMiles;
		std::string type;
		int price;  
		virtual void calculatePrice() = 0; 
	
	public:
		Vehicle(std::string carMake, std::string carModel, int miles, int price);
		int getId() const; 
		std::string getMake() const; 
		std::string getModel() const; 
		int getNumMiles() const; 
		int getPrice() const; 
		std::string getType() const;
		void setMake(const std::string& m); 
		void setModel(const std::string& m); 
		void updateNumMiles(const int& m); 
		void setPrice(const int& p); 
		void setType(const std::string& t); 
		virtual bool operator==(Vehicle * rhs) const = 0; 
		virtual bool operator!=(Vehicle * rhs) const = 0; 
		virtual void display(); 
		virtual void shutDown(std::ofstream& outputFile);
}; 

//**************************************************************************************************** 

inline 
int Vehicle::getId() const
{
	return id;
}

//**************************************************************************************************** 

inline
std::string Vehicle::getMake() const
{
	return make;
}

//**************************************************************************************************** 

inline 
std::string Vehicle::getModel() const
{
	return model;
}

//**************************************************************************************************** 

inline
int Vehicle::getNumMiles() const
{
	return numMiles;
}

//****************************************************************************************************  

inline 
int Vehicle::getPrice() const
{
	return price;
}

//**************************************************************************************************** 

inline
std::string Vehicle::getType() const
{
	return type;
}

//**************************************************************************************************** 

inline 
void Vehicle::setMake(const std::string& m)
{
	make = m;
}

//**************************************************************************************************** 

inline
void Vehicle::setModel(const std::string& m)
{
	model = m;
}

//**************************************************************************************************** 

inline
void Vehicle::setType(const std::string& t)
{
	type = t;
}

//**************************************************************************************************** 
#endif 