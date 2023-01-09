//****************************************************************************************************
//
//         File:                        OilFilter.h
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
//         This program creates OilFilter class.
//
//
//**************************************************************************************************** 
#ifndef OILFILTER_H
#define OILFILTER_H

#include "Part.h"

//**************************************************************************************************** 

class OilFilter : public Part
{
	protected:
		int size; 
		std::string lifeExpectancy; 
		std::string vehicleType; 

	public: 
		OilFilter(std::string name, double price, int size, std::string le, std::string vt);
		int getSize() const; 
		std::string getLifeExpectancy() const; 
		std::string getVehicleType() const;
		void setSize(const int& s); 
		void setLifeExpectancy(const std::string& l); 
		void setVehicleType(const std::string& v); 
		virtual void inflation();
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline
int OilFilter::getSize() const
{
	return size;
}

//**************************************************************************************************** 

inline
std::string OilFilter::getLifeExpectancy() const
{
	return lifeExpectancy;
}

//**************************************************************************************************** 

inline
std::string OilFilter::getVehicleType() const
{
	return vehicleType;
}

//**************************************************************************************************** 

inline
void OilFilter::setSize(const int& s)
{
	size = s;
}

//**************************************************************************************************** 

inline
void OilFilter::setLifeExpectancy(const std::string& l)
{
	lifeExpectancy = l;
}

//**************************************************************************************************** 

inline
void OilFilter::setVehicleType(const std::string& v)
{
	vehicleType = v;
}

//**************************************************************************************************** 
#endif 