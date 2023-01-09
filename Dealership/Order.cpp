#include "Order.h"

int Order::counter = 0;
//**************************************************************************************************** 

Order::Order(double t, tm a, tm o)
{
	counter += 10; 
	id = counter;
	arrivalDate = a; 
	dateOrdered = o;
} 

//**************************************************************************************************** 

void Order::shutDown(std::ofstream& outputFile)
{
	outputFile << id << '\n' << total << '\n' << arrivalDate.tm_year << '\n'
		<< arrivalDate.tm_mon << '\n' << arrivalDate.tm_mday << '\n'
		<< arrivalDate.tm_hour << '\n' << arrivalDate.tm_min << '\n'
		<< dateOrdered.tm_year << '\n'
		<< dateOrdered.tm_mon << '\n' << dateOrdered.tm_mday << '\n'
		<< dateOrdered.tm_hour << '\n' << dateOrdered.tm_min << '\n';

}