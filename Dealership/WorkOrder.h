//****************************************************************************************************
//
//         File:                        WorkOrder.h
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
//         This program creates WorkOrder class.
//
//
//****************************************************************************************************
#ifndef WORKORDER_H 
#define WORKORDER_H  

#include <string>
#include <ctime>
#include <fstream>

//****************************************************************************************************

class WorkOrder
{
	private:
		tm dateTime;
		double orderPrice; 
		std::string orderDescription; 

	public:
		WorkOrder(tm dateTime, double price, std::string description); 
		tm getDate() const; 
		double getPrice() const; 
		std::string getDescription() const; 
		void setDate(const tm& dateTime); 
		void setPrice(const double& price); 
		void setDescription(const std::string& desc);
		bool operator==(const WorkOrder& rhs) const;
		bool operator!=(const WorkOrder& rhs) const;
		void shutDown(std::ofstream& outputFile);
};

//****************************************************************************************************

inline 
tm WorkOrder::getDate() const
{
	return dateTime;
}

//****************************************************************************************************

inline 
double WorkOrder::getPrice() const
{
	return orderPrice;
}

//****************************************************************************************************

inline 
std::string WorkOrder::getDescription() const
{
	return orderDescription;
}  

//****************************************************************************************************

inline 
void WorkOrder::setDate(const tm& d)
{
	dateTime = d;
}

//****************************************************************************************************

inline 
void WorkOrder::setDescription(const std::string& des)
{
	orderDescription = des;
}

//****************************************************************************************************

inline 
void WorkOrder::setPrice(const double& p)
{
	orderPrice = p;
}

//****************************************************************************************************


inline 
bool WorkOrder::operator!=(const WorkOrder& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************
#endif