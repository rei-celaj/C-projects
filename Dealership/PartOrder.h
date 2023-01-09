//****************************************************************************************************
//
//         File:                        PartOrder.h
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
//         This program creates PartOrder class.
//
//
//**************************************************************************************************** 
#ifndef PARTORDER_H 
#define PARTORDER_H

#include "Order.h"
#include "Tires.h" 
#include "BrakePads.h"
#include "OilFilter.h"
#include <vector>

//**************************************************************************************************** 

class PartOrder : public Order
{
	protected:
		std::string deliveryType;
		std::vector<Part *> parts;
		//Service Technition buyer;
		virtual void holder() {}; 

	public:
		PartOrder(double total, tm arrival, tm orderd, std::string deliveryType);
		std::string getDelivery() const; 
		void setDelivery(const std::string& dt);
		void addPart(Part * p);
		virtual void shutDown(std::ofstream& outputFile);
};

//**************************************************************************************************** 

inline 
std::string PartOrder::getDelivery() const
{
	return deliveryType; 
}

//**************************************************************************************************** 

inline 
void PartOrder::setDelivery(const std::string& dt)
{
	deliveryType = dt;
}

//**************************************************************************************************** 

inline 
void PartOrder::addPart(Part * p)
{
	parts.push_back(p);
}

//**************************************************************************************************** 
#endif 