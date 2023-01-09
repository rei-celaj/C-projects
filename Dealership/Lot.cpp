#include "Lot.h" 
//****************************************************************************************************

Lot::Lot(int cap, int num)
{
	capacity = cap;
	numCars = num;
}

//****************************************************************************************************

void Lot::addItem(std::vector<Vehicle *>& coll, Vehicle * item)
{
	coll.push_back(item);
}

//****************************************************************************************************

bool Lot::addItem(Vehicle * car)
{
	bool flag = false;
	if (!isFull())
	{
		if (car->getType() == "S")
		{
			addItem(suvs, car);
		}
		else if (car->getType() == "T")
		{
			addItem(trucks, car);
		}
		else
		{
			addItem(sedans, car);
		}
		numCars++;
		flag = true;
	}
	return flag;
}

//****************************************************************************************************

int Lot::searchItem(Vehicle * car)
{
	int index;
	if (car->getType() == "S")
	{
		index = searchItem(suvs, car);
	}
	else if (car->getType() == "T")
	{
		index = searchItem(trucks, car);
	}
	else
	{
		index = searchItem(sedans, car);
	}
	return index;
}

//****************************************************************************************************

int Lot::searchItem(std::vector<Vehicle *>& coll, Vehicle * item)
{
	int index = -1;
	std::vector<Vehicle *>::iterator it;

	for (it = coll.begin(); it < coll.end(); it++)
	{
		if (**it == item)
		{
			index = it - coll.begin();
		}
	}
	return index;
}

//****************************************************************************************************

bool Lot::deleteItem(Vehicle * car)
{
	bool flag = false;

	if (car->getType() == "S")
	{
		flag = deleteItem(suvs, car);
	}
	else if (car->getType() == "T")
	{
		flag = deleteItem(trucks, car);
	}
	else
	{
		flag = deleteItem(sedans, car);
	}
	return flag;
}

//****************************************************************************************************

bool Lot::deleteItem(std::vector<Vehicle *>& coll, Vehicle * item)
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

//****************************************************************************************************

void Lot::shutDown(std::ofstream& outputFile)
{
	outputFile << capacity << '\n'
			   << numCars << '\n'
			   << suvs.size() << '\n'; 
	for (int i = 0; i < (int)suvs.size(); i++)
	{
		suvs[i]->shutDown(outputFile);
	}
	outputFile << trucks.size() << '\n';

	for (int i = 0; i < (int)trucks.size(); i++)
	{
		trucks[i]->shutDown(outputFile);
	}
	outputFile << sedans.size() << '\n'; 

	for (int i = 0; i < (int)sedans.size(); i++)
	{
		sedans[i]->shutDown(outputFile);
	}
}

//****************************************************************************************************

/*

std::ostream& operator<<(std::ostream& output, const Lot& LotDisplayed)
{
	std::vector<SUV *>::const_iterator it1;
	std::vector<Truck *>::const_iterator it2;
	std::vector<Sedan *>::const_iterator it3;

	output << "SUVS: " << '\n';

	for (it1 = suvs.begin(); it1 < suvs.end(); it1++)
	{
		output << **it1;
	}

	output << "Trucks: " << '\n';

	for (it2 = suvs.begin(); it2 < suvs.end(); it2++)
	{
		output << **it2;
	}

	output << "Sedans: " << '\n';

	for (it3 = suvs.begin(); it3 < suvs.end(); it3++)
	{
		output << **it3;
	}

	return output;
}

*/

//****************************************************************************************************