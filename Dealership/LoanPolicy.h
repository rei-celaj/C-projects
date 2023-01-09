//****************************************************************************************************
//
//         File:                        LoanPolicy.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Term Project
//
//         Course LoanPolicy:           Object Oriented Analysis and Design
//
//         Course Number:               COSC 4250 - 01
//
//         Due:                         N/A
//
//
//         This program creates LoanPolicy class.
//
//
//****************************************************************************************************

#ifndef LOANPOLICY_H 
#define LOANPOLICY_H

#include <string>
#include <fstream>

class LoanPolicy 
{
	private:
		std::string loanPolicyDescription;
		double rate;
		int timeLoanDuration;

	public:
		LoanPolicy(std::string policy = "NULL", double rate = .5, int time = 2);
		std::string getPolicyDescription() const; 
		double getRate() const;
		int getTime() const; 
		void setRate(const double& rate);
		void setTime(const int& timeLoanDuration);
		void setPolicyDescription(const std::string& description); 
		std::string toString() const;
		bool operator==(const LoanPolicy& rhs) const;
		bool operator!=(const LoanPolicy& rhs) const;
		bool operator<(const LoanPolicy& rhs) const;
		bool operator>(const LoanPolicy& rhs) const;
		bool operator<=(const LoanPolicy& rhs) const;
		bool operator>=(const LoanPolicy& rhs) const;
		void shutDown(std::ofstream& outputFile);
};

std::ostream& operator<<(std::ostream& output, const LoanPolicy& loanPolicyDisplayed);

//****************************************************************************************************

inline
double LoanPolicy::getRate() const
{
	return rate;
}

//**************************************************************************************************** 

inline
int LoanPolicy::getTime() const
{
	return timeLoanDuration;
}

//****************************************************************************************************

inline 
std::string LoanPolicy::getPolicyDescription() const
{
	return loanPolicyDescription;
}

//****************************************************************************************************

inline
void LoanPolicy::setPolicyDescription(const std::string& description)
{
	loanPolicyDescription = description;
}

//****************************************************************************************************

inline 
bool LoanPolicy::operator==(const LoanPolicy& rhs) const
{
	return this->loanPolicyDescription == rhs.loanPolicyDescription;
}

//****************************************************************************************************

inline
bool LoanPolicy::operator!=(const LoanPolicy& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************

inline
bool LoanPolicy::operator<(const LoanPolicy& rhs) const
{
	return !(*this <= rhs);
}

//***************************************************************************************************

inline
bool LoanPolicy::operator>(const LoanPolicy& rhs) const
{
	return !(*this >= rhs);
}

//****************************************************************************************************

inline
bool LoanPolicy::operator<=(const LoanPolicy& rhs) const
{
	return this->loanPolicyDescription <= rhs.loanPolicyDescription;
}

//***************************************************************************************************

inline
bool LoanPolicy::operator>=(const LoanPolicy& rhs) const
{
	return this->loanPolicyDescription >= rhs.loanPolicyDescription;
}

//***************************************************************************************************

#endif