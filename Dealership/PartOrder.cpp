#include "PartOrder.h" 

//**************************************************************************************************** 

PartOrder::PartOrder(double t, tm a, tm o, std::string dt) : 
	Order(t, a, o)
{
	deliveryType = dt;
}

//****************************************************************************************************

void PartOrder::shutDown(std::ofstream& outputFile)
{
	this->Order::shutDown(outputFile); 
	outputFile << deliveryType << '\n' << parts.size() << '\n'; 
	for (int i = 0; i < parts.size(); i++)
	{
		parts[i]->shutDown(outputFile);
	}
}