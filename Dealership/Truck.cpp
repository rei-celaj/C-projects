#include "Truck.h" 

//****************************************************************************************************  

Truck::Truck(std::string ma, std::string mo, int miles, int price,
	std::string ft, std::string et, std::string v) : Vehicle(ma, mo, miles, price)
{
	flatbedType = ft; 
	engineType = et; 
	varient = v; 
	type = "T";
}

//****************************************************************************************************  

void Truck::calculatePrice()
{
	const int TRUCK_PRICE = 30000;
	const int PRICE_DEDUCTION = 6000;
	const int MILE_PRICE = 2;
	int price = TRUCK_PRICE,
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

bool Truck::operator==(Vehicle * rhs) const
{
	try
	{
		Truck * ptr = dynamic_cast<Truck *>(rhs);
		return
			(this->getEngine() == ptr -> getEngine()) ? -1 :
			(this->getFlatBed() == ptr -> getFlatBed()) ? -1 :
			(this->getVarient() == ptr -> getVarient()) ? -1 :
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

bool Truck::operator!=(Vehicle * rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************

void Truck::display()
{
	this -> Vehicle::display();
	std::cout << "Engine Type: " << this->getEngine() << '\n' 
		<< "FlatBed Type: " << this->getFlatBed() << '\n' 
		<< "Varient: " << this->getVarient() << '\n';
}

//****************************************************************************************************

void Truck::shutDown(std::ofstream& outputFile)
{
	this->Vehicle::shutDown(outputFile); 
	outputFile << flatbedType << '\n' << engineType << '\n'
		       << varient << '\n';
}

//****************************************************************************************************