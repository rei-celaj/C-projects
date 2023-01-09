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
//         This program creates SUV class.
//
//
//**************************************************************************************************** 
#ifndef SUV_H
#define SUV_H

#include "Vehicle.h" 

//**************************************************************************************************** 

class SUV : public Vehicle
{
	protected: 
		std::string varient; 
		int enginePower; 

	public:
		SUV(std::string ma = "Ford", std::string mo = "Explorer", int miles = 0, int price = 25000, std::string v = "XL", int power = 250); 
		std::string getVarient() const; 
		int getEnginePower() const; 
		void setVarient(const std::string& v); 
		void setEnginePower(const int& enginePower);
		virtual void calculatePrice(); 
		bool operator==(Vehicle * rhs) const; 
		bool operator!=(Vehicle * rhs) const;
		virtual void display();
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline
std::string SUV::getVarient() const
{
	return varient;
}

//**************************************************************************************************** 

inline
int SUV::getEnginePower() const
{
	return enginePower;
}

//**************************************************************************************************** 

inline 
void SUV::setVarient(const std::string& v)
{
	varient = v;
}

//**************************************************************************************************** 

inline 
void SUV::setEnginePower(const int& p)
{
	enginePower = p;
}

//**************************************************************************************************** 
#endif