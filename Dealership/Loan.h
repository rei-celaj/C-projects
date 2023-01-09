//****************************************************************************************************
//
//         File:                        Loan.h
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Term Project
//
//         Course Name:                 Object Oriented Analysis and Design
//
//         Course Number:               COSC 4250 - 01
//
//         Due:                         N/A
//
//
//         This program creates Loan class.
//
//
//****************************************************************************************************

#ifndef LOAN_H 
#define LOAN_H 

#include <string>
#include "LoanPolicy.h"

//**************************************************************************************************** 

class Loan
{
	private:
		static int counter;
		int id; 
		std::string loanDescription; 
		LoanPolicy policy;

	public:
		Loan(std::string description = "NULL", LoanPolicy policy = LoanPolicy());  
		int getId() const; 
		std::string getDescription() const; 
		LoanPolicy getPolicy() const;
		void setDescription(const std::string& description); 
		void setLoanPolicy(const LoanPolicy& policy);
		std::string toString() const;
		bool operator==(const Loan& rhs) const;
		bool operator!=(const Loan& rhs) const;
		bool operator<(const Loan& rhs) const;
		bool operator>(const Loan& rhs) const;
		bool operator<=(const Loan& rhs) const;
		bool operator>=(const Loan& rhs) const;
		void shutDown(std::ofstream& outputFile);
}; 

std::ostream& operator<<(std::ostream& output, const Loan& LoanDisplayed);

//**************************************************************************************************** 

inline 
int Loan::getId() const
{
	return id;
}

//**************************************************************************************************** 

inline 
std::string Loan::getDescription() const
{
	return loanDescription;
}

//**************************************************************************************************** 

inline 
LoanPolicy Loan::getPolicy() const
{
	return policy;
}

//****************************************************************************************************

inline
void Loan::setDescription(const std::string& s)
{
	loanDescription = s;
}

//****************************************************************************************************

inline
void Loan::setLoanPolicy(const LoanPolicy& lp)
{
	policy = lp;
}

//**************************************************************************************************** 

inline
bool Loan::operator==(const Loan& rhs) const
{
	return (this->policy == rhs.policy);
}

//****************************************************************************************************

inline
bool Loan::operator!=(const Loan& rhs) const
{
	return !(*this == rhs);
}

//****************************************************************************************************

inline
bool Loan::operator<(const Loan& rhs) const
{
	return !(*this >= rhs);
}

//***************************************************************************************************

inline
bool Loan::operator>(const Loan& rhs) const
{
	return !(*this <= rhs);
}

//****************************************************************************************************

inline
bool Loan::operator<=(const Loan& rhs) const
{
	return (this->policy <= rhs.policy);
}

//****************************************************************************************************

inline
bool Loan::operator>=(const Loan& rhs) const
{
	return (this->policy >= rhs.policy);
}

//**************************************************************************************************** 
#endif