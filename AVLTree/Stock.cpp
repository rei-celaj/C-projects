#include "Stock.h"

//****************************************************************************************************

Stock::Stock(const std::string& name, const std::string& symbol,
	double price)
{
	companyName = name;
	companyPrice = price;
	companySymbol = symbol;
}

//****************************************************************************************************

Stock::Stock(const Stock& s)
{
	companyName = s.companyName;
	companyPrice = s.companyPrice;
	companySymbol = s.companySymbol;
}

//****************************************************************************************************

void Stock::display() const
{
	std::cout << "Company Name: " << companyName << std::endl;
	std::cout << "Company Symbol: " << companySymbol << std::endl;
	std::cout << "Company Price: " << companyPrice << std::endl;
}

//**************************************************************************************************** 

std::ostream & operator <<(std::ostream & out, const Stock & data)
{
	out << data.companyName << '/' << data.companySymbol << '/'
		<< data.companyPrice;
	return out;
}

//****************************************************************************************************