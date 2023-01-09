#include "Storage.h" 

//****************************************************************************************************

Storage::Storage()
{
	numProducts = 0;
}

//****************************************************************************************************

void Storage::addItem(Part * partAdd)
{

	if (partAdd->getType() == "O")
	{
		addItem(oilFilters, partAdd);
	}
	else if (partAdd->getType() == "T")
	{
		addItem(tires, partAdd);
	}
	else
	{
		addItem(brakePads, partAdd);
	}
}

//****************************************************************************************************

void Storage::addItem(std::vector<Part *>& coll, Part * item)
{
	Part * ptr = item;
	coll.push_back(ptr);
}

//****************************************************************************************************

int Storage::searchItem(Part * partSearch)
{
	int index;

	if (partSearch -> getType() == "O")
	{
		index = searchItem(oilFilters, partSearch);
	}
	else if (partSearch -> getType() == "T")
	{
		index = searchItem(tires, partSearch);
	}
	else
	{
		index = searchItem(brakePads, partSearch);
	}
	return index;
}

//****************************************************************************************************

int Storage::searchItem(std::vector<Part *>& coll, Part * item) 
{
	int index = -1;
	std::vector<Part *>::iterator it;

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

bool Storage::deleteItem(Part * partDelete)
{
	bool flag;

	if (partDelete -> getType() == "O")
	{
		flag = deleteItem(oilFilters, partDelete);
	}
	else if (partDelete -> getType() == "T")
	{
		flag = deleteItem(tires, partDelete);
	}
	else
	{
		flag = deleteItem(brakePads, partDelete);
	}
	return flag;
}

//****************************************************************************************************

bool Storage::deleteItem(std::vector<Part *>& coll, Part * item)
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

void Storage::shutDown(std::ofstream& outputFile)
{
	outputFile << numProducts << '\n' << oilFilters.size() << '\n'; 
	for (int i = 0; i < (int)oilFilters.size(); i++)
	{
		oilFilters[i]->shutDown(outputFile);
	} 

	outputFile << brakePads.size() << '\n'; 
	for (int i = 0; i < (int)brakePads.size(); i++)
	{
		brakePads[i]->shutDown(outputFile);
	}

	outputFile << tires.size() << '\n'; 
	for (int i = 0; i < (int)tires.size(); i++)
	{
		tires[i]->shutDown(outputFile);
	}
}

//****************************************************************************************************

/*

std::ostream& operator<<(std::ostream& output, const Lot& LotDisplayed)
{
	std::vector<OilFilter *>::const_iterator it1;
	std::vector<Tire *>::const_iterator it2;
	std::vector<BrakePad *>::const_iterator it3;

	output << "Oil Filters: " << '\n';

	for (it1 = oilFilters.begin(); it1 < oilFilters.end(); it1++)
	{
		output << **it1;
	}

	output << "Tires: " << '\n';

	for (it2 = tires.begin(); it2 < tires.end(); it2++)
	{
		output << **it2;
	}

	output << "Brake Pads: " << '\n';

	for (it3 = brakePads.begin(); it3 < breakPads.end(); it3++)
	{
		output << **it3;
	}

	return output;
}

*/

//****************************************************************************************************