//****************************************************************************************************
//
//         File:                        Student.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Program  # 10
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         April 20, 2021
//
//
//         This program creates the student struct.
//
//
//****************************************************************************************************
#include <iostream>

#ifndef STUDENT_H
#define STUDENT_H 

//****************************************************************************************************

class Student 
{
	private:
		int id; 
		char name[50]; 
		double gpa; 

	public: 
		bool operator <(const Student & rhs) const;
		bool operator <(int value) const; 
		bool operator <=(const Student & rhs) const; 
		bool operator <=(int value) const; 
		bool operator >(const Student & rhs) const; 
		bool operator >(int value) const; 
		bool operator >=(const Student & rhs) const; 
		bool operator >=(int value) const; 
		bool operator ==(const Student & rhs) const; 
		bool operator ==(int value) const; 
		bool operator !=(const Student & rhs) const; 
		bool operator !=(int value) const; 
		friend std::ostream & operator <<(std::ostream & out, const Student & data);
}; 

//****************************************************************************************************

bool Student::operator <(const Student & rhs) const
{
	return (this -> id < rhs.id);
} 

//**************************************************************************************************** 

bool Student::operator <(int value) const
{
	return (this -> id < value);
}

//****************************************************************************************************

bool Student::operator <=(const Student & rhs) const
{
	return (this -> id <= rhs.id);
}

//**************************************************************************************************** 

bool Student::operator <=(int value) const
{
	return (this -> id <= value);
}

//****************************************************************************************************

bool Student::operator >(const Student & rhs) const
{
	return (this -> id > rhs.id);
}

//****************************************************************************************************

bool Student::operator >(int value) const
{
	return (this -> id > value);
}

//****************************************************************************************************

bool Student::operator >=(const Student & rhs) const
{
	return (this -> id >= rhs.id);
}

//**************************************************************************************************** 

bool Student::operator >=(int value) const
{
	return (this -> id >= value);
}

//****************************************************************************************************

bool Student::operator ==(const Student & rhs) const
{
	return (this -> id == rhs.id);
}

//****************************************************************************************************

bool Student::operator ==(int value) const
{
	return (this -> id == value);
}

//**************************************************************************************************** 

bool Student::operator !=(const Student & rhs) const
{
	return (this -> id != rhs.id);
}

//****************************************************************************************************

bool Student::operator !=(int value) const
{
	return (this -> id != value);
}

//**************************************************************************************************** 

std::ostream & operator <<(std::ostream & out, const Student & data)
{
	return out;
}

//****************************************************************************************************
#endif 