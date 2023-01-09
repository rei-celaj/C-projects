//****************************************************************************************************
//
//         File:                        Dealership.h
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
//         This program creates Dealership class.
//
//
//****************************************************************************************************
#ifndef DEALERSHIP_H 
#define DEALERSHIP_H 

#include "Lot.h" 
#include "Staff.h" 
#include "Storage.h" 

//****************************************************************************************************

class Dealership
{
	private:
		std::string name; 
		std::string address; 
		std::string phoneNum;
		Lot cars;
		Storage parts; 
		Staff employees;

	public:
		Dealership(std::string name, std::string add, std::string phone); 
		~Dealership(); 
		void shutDown(std::ofstream& fileWrite);
		std::string getName() const;
		std::string getAddress() const; 
		std::string getPhoneNum() const; 
		void setName(const std::string& n); 
		void setAddress(const std::string& a); 
		void setPhoneNum(const std::string& p);
		void addCar(Vehicle * v);
		int searchCar(Vehicle * v); 
		bool deleteCar(Vehicle * v);
		void addPart(Part * p); 
		void addEmployee(Employee * e);
};

//****************************************************************************************************

inline 
std::string Dealership::getName() const
{
	return name; 
}

//****************************************************************************************************

inline 
std::string Dealership::getAddress() const
{
	return address;
}

//****************************************************************************************************

inline 
std::string Dealership::getPhoneNum() const
{
	return phoneNum;
}

//****************************************************************************************************

inline 
void Dealership::setName(const std::string& n)
{
	name = n;
}

//****************************************************************************************************

inline 
void Dealership::setAddress(const std::string& a)
{
	address = a;
}

//****************************************************************************************************

inline
void Dealership::setPhoneNum(const std::string& p)
{
	phoneNum = p;
}

//****************************************************************************************************

inline 
void Dealership::addCar(Vehicle * c)
{
	cars.addItem(c);
}

//****************************************************************************************************

inline 
int Dealership::searchCar(Vehicle * v)
{
	return cars.searchItem(v); 
}

//****************************************************************************************************

inline 
bool Dealership::deleteCar(Vehicle * v)
{
	return cars.deleteItem(v);
}

inline 
void Dealership::addPart(Part * p)
{
	parts.addItem(p);
}

//****************************************************************************************************

inline 
void Dealership::addEmployee(Employee * e)
{
	employees.addItem(e);
}

//****************************************************************************************************
#endif