#include "LoanPolicy.h" 
//****************************************************************************************************

LoanPolicy::LoanPolicy(std::string policy, double rate, int loanDuration)
{
	loanPolicyDescription = policy; 
	setRate(rate); 
	setTime(loanDuration);
}

//**************************************************************************************************** 

void LoanPolicy::setRate(const double& r)
{
	if (r < 0)
	{
		rate = .5;
	} 
	else
	{
		rate = r;
	}
}

//****************************************************************************************************

void LoanPolicy::setTime(const int& t)
{
	if (t < 0)
	{
		timeLoanDuration = 2;
	}
	else
	{
		timeLoanDuration = t;
	}
}

//****************************************************************************************************

std::ostream& operator<<(std::ostream& output, const LoanPolicy& loanPolicyDisplayed)
{
	output << loanPolicyDisplayed.getPolicyDescription() << '\n' <<
		"Loan Rate: " << loanPolicyDisplayed.getRate() << '\n' << "Loan Duration: " 
		 << loanPolicyDisplayed.getTime() << '\n';

	return output;
}

//****************************************************************************************************  

std::string LoanPolicy::toString() const
{
	std::string loanPolicyString; 

	loanPolicyString = this->getPolicyDescription() + '\n' + 
		std::to_string(this->getRate()) + '\n' + std::to_string(this->getTime());

	return loanPolicyString;
}

//****************************************************************************************************

void LoanPolicy::shutDown(std::ofstream& outputFile)
{
	outputFile << loanPolicyDescription << '\n' << rate << '\n' << timeLoanDuration << '\n';
}