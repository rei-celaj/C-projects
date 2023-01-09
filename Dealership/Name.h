//****************************************************************************************************
//
//         File:                        Name.h
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
//         This program creates Name class.
//
//
//****************************************************************************************************
#ifndef NAME_H 
#define NAME_H 

#include <string>
#include <fstream>

//****************************************************************************************************

class Name //Acts as a composite attribute for other objects
{
	private: 
		std::string firstName; 
		std::string lastName; 

	public: 
		Name(std::string first = "NULL", std::string last = "NULL"); 
		std::string getFirstName() const; 
		std::string getLastName() const; 
		void setFirstName(const std::string& first);
		void setLastName(const std::string& last); 
		bool operator==(const Name& rhs) const;
		bool operator!=(const Name& rhs) const;
		bool operator<(const Name& rhs) const;
		bool operator>(const Name& rhs) const;
		bool operator<=(const Name& rhs) const;
		bool operator>=(const Name& rhs) const;
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const Name& nameDisplayed);

//****************************************************************************************************

inline
std::string Name::getFirstName() const
{
	return firstName;
}

//**************************************************************************************************** 

inline
std::string Name::getLastName() const
{
	return lastName;
}

//**************************************************************************************************** 

inline
void Name::setFirstName(const std::string& first)
{
	firstName = first;
}

//**************************************************************************************************** 

inline
void Name::setLastName(const std::string& last)
{
	lastName = last;
}

//**************************************************************************************************** 

inline
bool Name::operator!=(const Name& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************

inline
bool Name::operator<(const Name& rhs) const
{
	return !(*this <= rhs);
}

//***************************************************************************************************

inline
bool Name::operator>(const Name& rhs) const
{
	return !(*this >= rhs);
}

//****************************************************************************************************
#endif