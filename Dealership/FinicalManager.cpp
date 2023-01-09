#include "FinicalManager.h" 

//****************************************************************************************************

FinicalManager::FinicalManager(Name emp, double r, std::string phone, 
	std::string e) : Employee(emp, r)
{
	phoneNum = phone; 
	email = e; 
	type = "FM";
}

//****************************************************************************************************

void FinicalManager::calculatePay()
{

}

//****************************************************************************************************

void FinicalManager::shutDown(std::ofstream& outputFile)
{
	this->Employee::shutDown(outputFile); 
	outputFile << phoneNum << '\n' << email << '\n' << policies.size() << '\n';
	for (int i = 0; i < (int)policies.size(); i++)
	{
		policies[i]->shutDown(outputFile);
	}
	outputFile << loansCreated.size() << '\n'; 
	for (int i = 0; i < (int)loansCreated.size(); i++)
	{
		loansCreated[i]->shutDown(outputFile);
	}
}