#include "Manager.h"

//****************************************************************************************************

Manager::Manager(Name emp, double r, std::string p, std::string e) : 
	Employee(emp, r)
{
	phoneNum = p; 
	email = e; 
	type = "M";
}

//****************************************************************************************************

void Manager::calculatePay()
{

}

//****************************************************************************************************

void Manager::shutDown(std::ofstream& outputFile)
{
	this->Employee::shutDown(outputFile); 
	outputFile << phoneNum << '\n' << email << '\n';
}