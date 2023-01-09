#include "CarOrder.h" 

//**************************************************************************************************** 

CarOrder::CarOrder(double t, tm a, tm o, int d) : Order(t, a, o)
{
	deposit = d;
}

//**************************************************************************************************** 

void CarOrder::shutDown(std::ofstream& outputFile)
{
	this->Order::shutDown(outputFile); 
	outputFile << deposit << '\n' << cars.size() << '\n'; 
	for (int i = 0; i < cars.size(); i++)
	{
		cars[i]->shutDown(outputFile);
	}
}