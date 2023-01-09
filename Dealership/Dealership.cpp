#include "Dealership.h"

//****************************************************************************************************

Dealership::Dealership(std::string n, std::string a, std::string p)
{
	name = n; 
	address = a; 
	phoneNum = p;
}

//****************************************************************************************************

Dealership::~Dealership()
{
	std::ofstream outputFile; 
	outputFile.open("TermProject.txt"); 
	shutDown(outputFile);
	outputFile.close();
}

//****************************************************************************************************

void Dealership::shutDown(std::ofstream& outputFile)
{
	outputFile << name << '\n'
		<< address << '\n'
		<< phoneNum << '\n';
	cars.shutDown(outputFile);
	parts.shutDown(outputFile);
	employees.shutDown(outputFile);
}

//****************************************************************************************************