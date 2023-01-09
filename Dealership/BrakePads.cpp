#include "BrakePads.h" 

//**************************************************************************************************** 

BrakePads::BrakePads(std::string n, double p, 
	std::string bt, std::string b) : Part(n, p)
{
	brakeType = bt; 
	brand = b;
	setType("B");
}

//**************************************************************************************************** 

void BrakePads::inflation()
{
	price += (int)(price * .15);
}

//**************************************************************************************************** 

void BrakePads::shutDown(std::ofstream& outputFile)
{
	this->Part::shutDown(outputFile); 

	outputFile << brakeType << '\n' << brand << '\n';
}

//**************************************************************************************************** 