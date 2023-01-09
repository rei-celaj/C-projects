#include "Loan.h" 
int Loan::counter = 0;

//**************************************************************************************************** 

Loan::Loan(std::string description, LoanPolicy policyLoan)
{
	id = ++counter * 10; 
	loanDescription = description; 
	policy = policyLoan;
}

//****************************************************************************************************  

std::ostream& operator<<(std::ostream& output, const Loan& LoanDisplayed)
{
	output << LoanDisplayed.getId() << '\n' <<
		LoanDisplayed.getDescription() << '\n' << LoanDisplayed.getPolicy();

	return output;
}

//****************************************************************************************************   

std::string Loan::toString() const
{
	std::string loanString; 

	loanString = std::to_string(this->getId()) + '\n' + this->getDescription() + '\n' + this->getPolicy().toString(); 
	 
	return loanString;
}

//**************************************************************************************************** 

void Loan::shutDown(std::ofstream& outputFile)
{
	outputFile << id << '\n' << loanDescription << '/n'; 
	policy.shutDown(outputFile);
}

