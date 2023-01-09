#include "Name.h"

//****************************************************************************************************  

Name::Name(std::string first, std::string last)
{
	firstName = first; 
	lastName = last;
}

//**************************************************************************************************** 

bool Name::operator==(const Name& rhs) const
{
	if (this -> lastName != rhs.lastName)
	{
		return false;
	} 
	else
	{
		return this->firstName == rhs.firstName;
	}
}

//****************************************************************************************************  

bool Name::operator<=(const Name& rhs) const
{
	if (this->lastName > rhs.lastName)
	{
		return false;
	}
	else
	{
		return this->firstName <= rhs.firstName;
	}
}

//****************************************************************************************************

bool Name::operator>=(const Name& rhs) const
{
	if (this->lastName < rhs.lastName)
	{
		return false;
	}
	else
	{
		return this->firstName >= rhs.firstName;
	}
}

//**************************************************************************************************** 

std::ostream& operator<<(std::ostream& output, const Name& nameDisplayed)
{
	output << nameDisplayed.getFirstName() << " " <<
		nameDisplayed.getLastName(); 

	return output;
}

//**************************************************************************************************** 

void Name::shutDown(std::ofstream& outputFile)
{
	outputFile << firstName << '\n' << lastName << '\n';
}