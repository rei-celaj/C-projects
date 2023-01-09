#include "ServiceTechnition.h"

//****************************************************************************************************

ServiceTechnition::ServiceTechnition(Name emp, double r, std::string ro) : Employee(emp, r)
{
	role = ro;
	type = "ST";
}

//****************************************************************************************************

void ServiceTechnition::calculatePay()
{

}

void ServiceTechnition::shutDown(std::ofstream& outputFile)
{
	this->Employee::shutDown(outputFile);
	outputFile << role << '\n' << currentOrders.size() << '\n'; 
	for (int i = 0; i < currentOrders.size(); i++)
	{
		currentOrders[i]->shutDown(outputFile);
	} 
	outputFile << ordersPlaced.size() << '\n';
	for (int i = 0; i < ordersPlaced.size(); i++)
	{
		ordersPlaced[i]->shutDown(outputFile);
	}
}