//****************************************************************************************************
//
//         File:                        Tires.h
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
//         This program creates Tires class.
//
//
//**************************************************************************************************** 
#ifndef TIRES_H
#define TIRES_H

#include "Part.h" 

//**************************************************************************************************** 

class Tires : public Part
{
	protected: 
		int size; 
		std::string brand; 

	public:
		Tires(std::string n, double p, int s, std::string b);
		int getSize() const; 
		std::string getBrand() const; 
		void setSize(const int& s); 
		void setBrand(const std::string& b); 
		virtual void inflation();
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int Tires::getSize() const
{
	return size;
}

//**************************************************************************************************** 

inline 
std::string Tires::getBrand() const
{
	return brand;
}

//**************************************************************************************************** 

inline 
void Tires::setSize(const int& s)
{
	size = s;
}

//**************************************************************************************************** 

inline 
void Tires::setBrand(const std::string& b)
{
	brand = b;
}

//**************************************************************************************************** 
#endif