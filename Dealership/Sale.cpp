#include "Sale.h" 

int Sale::counter = 0; 

//****************************************************************************************************

Sale::Sale(Customer c, double t, tm d)
{
	counter += 10; 
	id = counter;
	total = t; 
	sellDate = d;
	buyer = &c;
}

//****************************************************************************************************

void Sale::shutDown(std::ofstream& outputFile)
{
	outputFile << id << '\n' << total << '\n'
		<< sellDate.tm_year << '\n'
		<< sellDate.tm_mon << '\n' << sellDate.tm_mday << '\n'
		<< sellDate.tm_hour << '\n' << sellDate.tm_min << '\n';
	buyer->shutDown(outputFile);
	outputFile << cars.size() << '\n'; 
	for (int i = 0; i < cars.size(); i++)
	{
		cars[i]->shutDown(outputFile);
	}
}