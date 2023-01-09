//****************************************************************************************************
//
//         File:                        BrakePads.h
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
//         This program creates BrakePads class.
//
//
//**************************************************************************************************** 
#ifndef BRAKEPADS_H 
#define BRAKEPADS_H 

#include "Part.h"

//**************************************************************************************************** 

class BrakePads : public Part
{
	protected:
		std::string brakeType; 
		std::string brand; 

	public:
		BrakePads(std::string n, double p, std::string bt, std::string b);
		std::string getBrakeType() const; 
		std::string getBrand() const; 
		void setBrakeType(const std::string& bt); 
		void setBrand(const std::string& b);
		virtual void inflation(); 
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline
std::string BrakePads::getBrakeType() const
{
	return brakeType;
}

//**************************************************************************************************** 

inline
std::string BrakePads::getBrand() const
{
	return brand;
}

//**************************************************************************************************** 

inline
void BrakePads::setBrakeType(const std::string& bt)
{
	brakeType = bt;
}

//**************************************************************************************************** 

inline
void BrakePads::setBrand(const std::string& b)
{
	brand = b;
}

//**************************************************************************************************** 
#endif 