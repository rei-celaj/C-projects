//****************************************************************************************************
//
//         File:                        Part.h
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
//         This program creates Part class.
//
//
//**************************************************************************************************** 
#ifndef PART_H 
#define PART_H 

#include <string>
#include <fstream>

//**************************************************************************************************** 

class Part
{
	protected: 
		static int counter; 
		int id;
		std::string name; 
		double price;  
		std::string type;
		virtual void inflation() = 0;

	public: 
		Part(std::string n = "N/A", double p = 0);
		int getId() const; 
		std::string getName() const; 
		double getPrice() const;
		std::string getType() const;
		void setName(const std::string& n); 
		void setPrice(const double& p); 
		void setType(const std::string& s);
		virtual bool operator==(Part * rhs) const;
		virtual bool operator!=(Part * rhs) const;
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int Part::getId() const
{
	return id;
}

//**************************************************************************************************** 

inline 
std::string Part::getName() const
{
	return name;
}

//**************************************************************************************************** 

inline 
double Part::getPrice() const
{
	return price;
}

//**************************************************************************************************** 

inline 
std::string Part::getType() const
{
	return type;
}

//**************************************************************************************************** 

inline 
void Part::setName(const std::string& n)
{
	name = n;
}

//**************************************************************************************************** 

inline 
void Part::setPrice(const double& p)
{
	price = p;
}
//****************************************************************************************************

inline 
void Part::setType(const std::string& t)
{
	type = t;
}

//****************************************************************************************************

inline
bool Part::operator==(Part * rhs) const
{
	return this->getName() == rhs->getName();
}

//****************************************************************************************************

inline 
bool Part::operator!=(Part * rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************
#endif 