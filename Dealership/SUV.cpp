#include "SUV.h" 

//**************************************************************************************************** 

SUV::SUV(std::string ma, std::string mo, int miles, int price, std::string v, int p) : Vehicle(ma, mo, miles, price)
{
	varient = v; 
	enginePower = p; 
	setType("S");
}

//**************************************************************************************************** 

void SUV::calculatePrice()
{
	const int SUV_PRICE = 25000; 
	const int PRICE_DEDUCTION = 5000;
	const int MILE_PRICE = 2;
	int price = SUV_PRICE,
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

bool SUV::operator==(Vehicle * rhs) const
{
	try
	{
		SUV * ptr = dynamic_cast<SUV *>(rhs);

		return
			(this->getVarient() == ptr->getVarient()) ? -1 :
			(this->getEnginePower() == ptr->getEnginePower()) ? -1 :
			(this->getVarient() == ptr->getVarient()) ? -1 :
			(this->getMake() == ptr->getMake()) ? -1 :
			(this->getModel() == ptr->getModel()) ? -1 :
			(this->getNumMiles() == ptr->getNumMiles()) ? 1 :
			0;
	} 
	catch (std::bad_cast)
	{
		return false;
	}
}

//**************************************************************************************************** 

bool SUV::operator!=(Vehicle * rhs) const
{
	return !(*this == rhs);
}

//**************************************************************************************************** 

void SUV::display()
{
	this->Vehicle::display(); 
	std::cout << "Engine Power: " << this-> getEnginePower() << '\n' 
		<< "Varient: " << this-> getVarient() << '\n';
}

//**************************************************************************************************** 

void SUV::shutDown(std::ofstream& outputFile)
{
	this->Vehicle::shutDown(outputFile); 
	outputFile << varient << '\n' << enginePower << '\n';
}

//**************************************************************************************************** 