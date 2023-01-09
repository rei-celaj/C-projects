#include "Staff.h"

//****************************************************************************************************

Staff::Staff()
{
	numEmployees = 0;
}

//****************************************************************************************************

void Staff::setManager(Manager& emp)
{
	delete manager; 
	manager = &emp;
}


//****************************************************************************************************

void Staff::setFinicalManager(FinicalManager& emp) 
{ 
	delete finicalManager; 
	finicalManager = &emp;
}

//****************************************************************************************************

void Staff::addItem(Employee * emp)
{
	if (emp -> getType() == "S")
	{
		addItem(salesmen, emp);
	}
	else
	{
		addItem(serviceTechnitions, emp);
	}
}

//****************************************************************************************************

void Staff::addItem(std::vector<Employee *>& coll, Employee * item)
{
	Employee * ptr = item;
	coll.push_back(ptr);
}

//****************************************************************************************************

int Staff::searchItem(Employee *  emp)
{
	int index;
	if (emp -> getType() == "S")
	{
		index = searchItem(salesmen, emp);
	}
	else
	{
		index = searchItem(serviceTechnitions, emp);
	}
	return index;
}

//****************************************************************************************************

int Staff::searchItem(std::vector<Employee *>& coll, Employee * item)
{
	int index = -1;
	std::vector<Employee *>::iterator it;

	for (it = coll.begin(); it < coll.end(); it++)
	{
		if (**it == *item)
		{
			index = it - coll.begin();
		}
	}
	return index;
}

//****************************************************************************************************

bool Staff::deleteItem(Employee * emp)
{
	bool flag;

	if (emp -> getType() == "S")
	{
		flag = deleteItem(salesmen, emp);
	}
	else
	{
		flag = deleteItem(serviceTechnitions, emp);
	}
	return flag;
}

//****************************************************************************************************

bool Staff::deleteItem(std::vector<Employee *>& coll, Employee * item)
{
	bool flag = false;
	int index = searchItem(coll, item);

	if (index > -1)
	{
		delete coll[index];
		coll.erase(coll.begin() + index);
		flag = true;
	}
	return flag;
}

void Staff::shutDown(std::ofstream& outputFile)
{
	outputFile << numEmployees << '\n'; 
	manager->shutDown(outputFile);
	finicalManager->shutDown(outputFile); 
	outputFile << salesmen.size() << '\n'; 
	for (int i = 0; i < salesmen.size(); i++)
	{
		salesmen[i]->shutDown(outputFile);
	}
	outputFile << serviceTechnitions.size() << '\n'; 
	for (int i = 0; i < serviceTechnitions.size(); i++)
	{
		serviceTechnitions[i]->shutDown(outputFile);
	}
}


/*

std::ostream& operator<<(std::ostream& output, const Lot& LotDisplayed)
{
	std::vector<Salesman *>::const_iterator it1;
	std::vector<ServiceTechnition *>::const_iterator it2;

	output << "Manager: " << *manager << '\n'; 
	output << "Fincial Manager: " << *finicalManger << '\n';

	output << "Salesmen: " << '\n';

	for (it1 = salesmen.begin(); it1 < salesmen.end(); it1++)
	{
		output << **it1;
	}

	output << "Service Technitions: " << '\n';

	for (it2 = serviceTechnitions.begin(); it2 < serviceTechnitions.end(); it2++)
	{
		output << **it2;
	}

	return output;
}

*/

//****************************************************************************************************