#include "WorkOrder.h" 
//****************************************************************************************************

WorkOrder::WorkOrder(tm date, double price, std::string description)
{
	dateTime = date; 
	orderPrice = price; 
	orderDescription = description;
} 

//****************************************************************************************************

bool WorkOrder::operator==(const WorkOrder& rhs) const
{
	if ((this->dateTime.tm_hour == rhs.dateTime.tm_hour) &&
		(this->dateTime.tm_mon == rhs.dateTime.tm_mon) &&
		(this->dateTime.tm_min == rhs.dateTime.tm_min) &&
		(this->dateTime.tm_year == rhs.dateTime.tm_year))
	{
		return true;
	}
	else
	{
		return false;
	}
}

//****************************************************************************************************

void WorkOrder::shutDown(std::ofstream& outputFile)
{
	outputFile << dateTime.tm_year << '\n'
		<< dateTime.tm_mon << '\n' << dateTime.tm_mday << '\n'
		<< dateTime.tm_hour << '\n' << dateTime.tm_min << '\n'
		<< orderPrice << '\n' << orderDescription << '\n';
}
