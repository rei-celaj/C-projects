//****************************************************************************************************
//
//         File:                        Storage.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Term Project
//
//         Course LoanPolicy:           Object Oriented Analysis and Design
//
//         Course Number:               COSC 4250 - 01
//
//         Due:                         N/A
//
//
//         This program creates Storage collection class.
//
//
//****************************************************************************************************
#ifndef STORAGE_H 
#define STORAGE_H

#include "BrakePads.h" 
#include "Tires.h"
#include "OilFilter.h"
#include <vector>

//****************************************************************************************************
class Storage
{
	private:
		int numProducts;
		std::vector<Part *> oilFilters;
		std::vector<Part *> tires;
		std::vector<Part *> brakePads;

	public:
		Storage();
		int getNumProducts(); 
		void addItem(Part * partAdd); 
		void addItem(std::vector<Part *>& coll, Part * partAdd);
		int searchItem(Part * partSearch);
		int searchItem(std::vector<Part *>& coll, Part * partSearch);
		bool deleteItem(Part * partDelete);
		bool deleteItem(std::vector<Part *>& coll, Part * partDelete);
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const Storage& storageDisplayed);

//****************************************************************************************************

inline 
int Storage::getNumProducts()
{
	return numProducts;
}

//****************************************************************************************************
#endif 