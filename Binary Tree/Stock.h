#ifndef STOCK_H
#define STOCK_H

#include <iostream> 
#include <string> 

class Stock
{
private:
	std::string companyName;
	std::string companySymbol;
	double companyPrice;

public:
	Stock(const std::string& name = "", const std::string& = "",
		double price = 0);
	Stock(const Stock& s);
	void display() const;
	void setName(std::string name);
	void setSymbol(std::string symbol);
	void setPrice(double price);
	std::string getName() const;
	std::string getSymbol() const;
	double getPrice() const;
	bool operator==(const Stock& rhs) const;
	bool operator!=(const Stock& rhs) const;
	bool operator<(const Stock& rhs) const;
	bool operator>(const Stock& rhs) const;
	bool operator<=(const Stock& rhs) const;
	bool operator>=(const Stock& rhs) const;
	friend std::ostream & operator <<(std::ostream & out, const Stock & data);
};

//****************************************************************************************************

inline
void Stock::setName(std::string name)
{
	companyName = name;
}

//**************************************************************************************************** 

inline
void Stock::setSymbol(std::string symbol)
{
	companySymbol = symbol;
}

//**************************************************************************************************** 

inline
void Stock::setPrice(double price)
{
	companyPrice = price;
}

//**************************************************************************************************** 

inline
std::string Stock::getName() const
{
	return companyName;
}

//****************************************************************************************************

inline
std::string Stock::getSymbol() const
{
	return companySymbol;
}

//****************************************************************************************************

inline
double Stock::getPrice() const
{
	return companyPrice;
}

//****************************************************************************************************

inline
bool Stock::operator==(const Stock& rhs) const
{
	return (this->companySymbol == rhs.companySymbol);
}

//****************************************************************************************************

inline
bool Stock::operator!=(const Stock& rhs) const
{
	return (this->companySymbol != rhs.companySymbol);
}

//****************************************************************************************************

inline
bool Stock::operator<(const Stock& rhs) const
{
	return (this->companySymbol < rhs.companySymbol);
}

//****************************************************************************************************

inline
bool Stock::operator>(const Stock& rhs) const
{
	return (this->companySymbol > rhs.companySymbol);
}

//****************************************************************************************************

inline
bool Stock::operator<=(const Stock& rhs) const
{
	return (this->companySymbol <= rhs.companySymbol);
}

//****************************************************************************************************

inline
bool Stock::operator>=(const Stock& rhs) const
{
	return (this->companySymbol >= rhs.companySymbol);
}

//****************************************************************************************************
#endif