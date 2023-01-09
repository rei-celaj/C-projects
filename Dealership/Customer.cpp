#include "Customer.h"

int Customer::counter = 0;
//****************************************************************************************************  

Customer::Customer(Name n, std::string p)
{
	name = n; 
	phone = p; 
	id = ++counter * 10;
}

//****************************************************************************************************   

bool Customer::isFull() const
{
	bool flag = false;
	if (loans.size() == 3)
	{
		return true; 
	}  

	return flag;
}

//****************************************************************************************************

bool Customer::insertLoan(Loan& loan)
{
	bool flag = isFull(); 
	Loan* loanptr = &loan;


	if (!flag)
	{
		loans.push_back(loanptr);
	} 

	return flag;
}

//**************************************************************************************************** 

int Customer::searchLoan(const LoanPolicy& loanPol) const
{
	std::vector<Loan *>::const_iterator it;
	int index = -1;

	for (it = loans.begin(); it < loans.end() && index < 0; it++)
	{
		if ((*it)->getPolicy() == loanPol)
		{
			index = it - loans.begin(); 
		}
	}

	return index;
}

//**************************************************************************************************** 

bool Customer::deleteLoan(const LoanPolicy& loanPol)
{
	bool flag = false; 
	int index = searchLoan(loanPol); 

	if (index >= 0)
	{
		delete loans[index];
		loans.erase(loans.begin() + index); 
		flag = true;
	}

	return flag;
}

//**************************************************************************************************** 

std::string Customer::printLoans() const
{
	std::vector<Loan *>::const_iterator it;
	std::string output = ""; 

	for (it = loans.begin(); it < loans.end(); it++)
	{
		output += (*it)->toString() + '\n';
	} 

	return output;
}

//****************************************************************************************************  

std::ostream& operator<<(std::ostream& output, const Customer& customerDisplayed)
{
	output << "Customer Name: " << customerDisplayed.getCustName() << '\n' <<
		"Customer Phone: "<< customerDisplayed.getPhoneNum() << 
		'\n' << customerDisplayed.printLoans();

	return output;
} 

//**************************************************************************************************** 

void Customer::shutDown(std::ofstream& outputFile)
{
	outputFile << id << '\n'; 
	name.shutDown(outputFile); 
	outputFile << phone << '\n' << loans.size() << '\n'; 
	for (int i = 0; i < loans.size(); i++)
	{
		loans[i]->shutDown(outputFile);
	}
}