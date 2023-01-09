#include "Vehicle.h"

int Vehicle::counter = 0;

//**************************************************************************************************** 

Vehicle::Vehicle(std::string carMake, std::string carModel, int miles, int p)
{
	counter += 10; 
	id = counter;
	make = carMake; 
	model = carModel; 
	numMiles = miles; 
	setPrice(p);
}

//**************************************************************************************************** 

void Vehicle::setPrice(const int& p)
{
	if (p < 0)
	{
		price = -1;
	} 
	else
	{
		price = p;
	}
}
//**************************************************************************************************** 

void Vehicle::updateNumMiles(const int& m)
{
	if (m > numMiles)
	{
		numMiles = m;
	}
}

//**************************************************************************************************** 

void Vehicle::display()
{
	std::cout << "Type: " << this->getType() << '\n' <<
		"ID: " << this->getId() << '\n' << "Make: " << this->getMake()
		<< '\n' << "Model: " << this->getModel() << '\n'
		<< "Number of Miles: " << this->getNumMiles() << '\n' 
		<< "Price: " << this->getPrice() << '\n';
}

//****************************************************************************************************

void Vehicle::shutDown(std::ofstream& outputFile)
{
	outputFile << type << '\n' << id << '\n' << make << '\n'
			   << model << '\n' << numMiles << '\n' << price << '\n';
}

//****************************************************************************************************