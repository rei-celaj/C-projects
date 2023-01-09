#include "Sedan.h"

//**************************************************************************************************** 

Sedan::Sedan(std::string ma, std::string mo, int miles, int price,
	int c, int p) : Vehicle(ma, mo, miles, price)
{
	groundClearence = c; 
	enginePower = p; 
	setType("SE");
}

//**************************************************************************************************** 

void Sedan::calculatePrice()
{
	const int SEDAN_PRICE = 27500;
	const int PRICE_DEDUCTION = 5000;
	const int MILE_PRICE = 2;
	int price = SEDAN_PRICE,
		miles = this->getNumMiles();


	if (miles >= 3000)
	{
		price -= PRICE_DEDUCTION;
		miles -= 3000;
		if (miles > 0)
		{
			price += miles * MILE_PRICE;
		}
		this->setPrice(price);
	}
}

//**************************************************************************************************** 

bool Sedan::operator==(Vehicle * rhs) const
{
	try
	{
		Sedan * ptr = dynamic_cast<Sedan *>(rhs);

		return
			(this->getGround() == ptr -> getGround()) ? -1 :
			(this->getPower() == ptr -> getPower()) ? -1 :
			(this->getMake() == ptr -> getMake()) ? -1 :
			(this->getModel() == ptr -> getModel()) ? -1 :
			(this->getNumMiles() == ptr -> getNumMiles()) ? 1 :
			0;
	}
	catch (std::bad_cast)
	{
		return false;
	}
}

//**************************************************************************************************** 

bool Sedan::operator!=(Vehicle * rhs) const
{
	return !(*this == rhs);
}

//**************************************************************************************************** 

void Sedan::display()
{
	this->Vehicle::display(); 
	std::cout << "Ground Clearence: " << this->getGround() << '\n' 
		<< "Engine Power: " << this->getPower() << '\n';
}

//**************************************************************************************************** 

void Sedan::shutDown(std::ofstream& outputFile)
{
	this->Vehicle::shutDown(outputFile); 
	outputFile << groundClearence << '\n' << enginePower << '\n';
}

//**************************************************************************************************** 