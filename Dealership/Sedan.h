//****************************************************************************************************
//
//         File:                        Sedan.h
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
//         This program creates Sedan class.
//
//
//**************************************************************************************************** 

#ifndef SEDAN_H 
#define SEDAN_H 

#include "Vehicle.h"

//**************************************************************************************************** 

class Sedan : public Vehicle
{
	protected: 
		int groundClearence; 
		int enginePower;

	public:
		Sedan(std::string ma = "Honda", std::string mo = "Accord", int miles = 0, int price = 20000, int clearence = 4, int power = 250);
		int getGround() const; 
		int getPower() const; 
		void setGround(const int& g); 
		void setPower(const int& p); 
		virtual void calculatePrice(); 
		bool operator==(Vehicle * rhs) const; 
		bool operator!=(Vehicle * rhs) const;
		virtual void display();
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int Sedan::getGround() const
{
	return groundClearence;
} 

//**************************************************************************************************** 

inline 
int Sedan::getPower() const
{
	return enginePower; 
}

//**************************************************************************************************** 

inline 
void Sedan::setGround(const int& g)
{
	groundClearence = g;
}

//**************************************************************************************************** 

inline 
void Sedan::setPower(const int& p)
{
	enginePower = p;
}

//**************************************************************************************************** 
#endif 