#include "Salesman.h" 

//****************************************************************************************************

Salesman::Salesman(Name emp, double r, int c,
	std::string p, std::string e) : Employee(emp, r)
{
	commission = c; 
	phoneNum = p; 
	email = e; 
	type = "S";
}

//****************************************************************************************************

void Salesman::calculatePay()
{

}

//****************************************************************************************************

void Salesman::shutDown(std::ofstream& outputFile)
{
	this->Employee::shutDown(outputFile);
	outputFile << commission << '\n' << phoneNum << '\n' 
		       << email << '\n' << orders.size() << '\n';
	for (int i = 0; i < orders.size(); i++)
	{
		orders[i]->shutDown(outputFile);
	}
	outputFile << sales.size() << '\n'; 
	for (int i = 0; i < sales.size(); i++)
	{
		sales[i]->shutDown(outputFile);
	}
}