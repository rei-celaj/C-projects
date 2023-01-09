//****************************************************************************************************
//
//         File:                        Order.h
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
//         This program creates Order abstract class.
//
//
//**************************************************************************************************** 
#ifndef ORDER_H 
#define ORDER_H 

#include <ctime>
#include <fstream>

//**************************************************************************************************** 

class Order
{
	protected:
		static int counter; 
		int id;
		double total; 
		tm arrivalDate;
		tm dateOrdered;

	public:
		Order(double total, tm arrival, tm orderd);
		int getId() const; 
		double getTotal() const; 
		tm getArrival() const; 
		tm getOrdered() const; 
		void setTotal(const double& t); 
		void setArrival(const tm& a); 
		virtual void holder() = 0;
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
int Order::getId() const
{
	return id;
}

//**************************************************************************************************** 

inline 
double Order::getTotal() const
{
	return total;
}

//**************************************************************************************************** 

inline 
tm Order::getArrival() const
{
	return arrivalDate;
}

//**************************************************************************************************** 

inline 
tm Order::getOrdered() const
{
	return dateOrdered;
}

//**************************************************************************************************** 

inline 
void Order::setTotal(const double& t)
{
	total = t;
}

//**************************************************************************************************** 

inline 
void Order::setArrival(const tm& a)
{
	arrivalDate = a;
}

//**************************************************************************************************** 
#endif