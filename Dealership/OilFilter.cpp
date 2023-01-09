#include "OilFilter.h" 

//****************************************************************************************************  

OilFilter::OilFilter(std::string n, double p, int s,
	std::string le, std::string vt) : Part(n, p)
{
	size = s; 
	lifeExpectancy = le; 
	vehicleType = vt; 
	Part::setType("O");
}

//****************************************************************************************************  

void OilFilter::inflation()
{
	price += (int)(price * .1);
}

//****************************************************************************************************  

void OilFilter::shutDown(std::ofstream& outputFile)
{
	this->Part::shutDown(outputFile); 
	outputFile << size << '\n' << lifeExpectancy << '\n' << vehicleType << '\n';
}

//****************************************************************************************************  