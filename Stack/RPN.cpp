//****************************************************************************************************
//
//         File:                        RPN.cpp
//
//         Student:                     Rei Celaj
//
//         Assignment:                  Program  # 6
//
//         Course Name:                 Data Structures   I
//
//         Course Number:               COSC 3050 - 01
//
//         Due:                         March 6, 2021
//
//
//         This program tests a stack to wtite and read from a file.
//
//
//**************************************************************************************************** 
#include <fstream>  
#include <iostream>
#include <cctype> 

using namespace std; 

#include "Stack.h" 

//**************************************************************************************************** 

void outputToken(char token[], ofstream& resultsFile);
void processNumber(const char * token, Stack<int>& intStack, ofstream& resultsFile);
bool processOperator(char spr, Stack<int> & intStack, ofstream& output);
void displayResult(Stack<int> & intStack, ofstream& resultsFile, bool valid);
void resetFlagStack(Stack<int>& intStack, bool& valid);  

//****************************************************************************************************  

int main()
{
	ofstream output ("results.txt"); 
	ifstream input("expressions.txt"); 
	bool isValid = true; 
	char token[5]; 
	Stack<int> intStack = Stack<int>(); 

	while (input >> token)
	{
		outputToken(token, output);  

		if (token[0] == ';')
		{
			displayResult(intStack, output, isValid); 
			resetFlagStack(intStack, isValid);
		} 
		else if ((isValid) && (isdigit(token[0])))
		{
			processNumber(token, intStack, output);
		} 
		else
		{
			isValid = processOperator(token[0], intStack, output);
		}
	}

	output.close(); 
	input.close();
	return 0;
}

//****************************************************************************************************   

void outputToken(char token[], ofstream& resultsFile)
{
	resultsFile << endl << "( Token:  " << token << " ) \t\t";

	if (token[0] != ';')
		cout << token << " ";
}

//****************************************************************************************************
 
void processNumber(const char * token, Stack<int>& intStack, ofstream& resultsFile)
{
	int ival;

	ival = atoi(token);
	intStack.push(ival);

	resultsFile << "Push " << ival;
}

//****************************************************************************************************

bool processOperator(char spr, Stack<int> & intStack, ofstream& output)
{
	bool success = false; 

	int op1,
		op2,
		result;

	if ((intStack.pop(op2)) && (intStack.pop(op1)))
	{
		switch (spr)
		{
			case('+'):
				result = op1 + op2;
				break;

			case('-'):
				result = op1 - op2;
				break;

			case('*'):
				result = op1 * op2;
				break;

			case('/'):
				result = op1 / op2;
				break;

			case('%'):
				result = op1 % op2;
				break;
		} 

		intStack.push(result);  
		success = true; 

		output << "Pop " << op2 << '\t'
			   << "Pop " << op1 << '\t' << "Push "
			   << result;
	}

	return success; 
} 

//****************************************************************************************************

void displayResult(Stack<int> & intStack, ofstream& resultsFile, bool valid)
{
	int result;
	
	if (!valid)
	{
		resultsFile << "Invalid RPN expression - too few operands" 
			        << '\n' << '\n';  
		cout << '\t' << "invalid" << '\n';
	} 
	else if (intStack.getNumValues() > 1)
	{
		resultsFile << "Invalid RPN expression - too many operands" 
			        << '\n' << '\n'; 
		cout << '\t' << "invalid" << '\n';
	} 
	else
	{
		intStack.pop(result); 
		resultsFile << "Pop " << result << '\n';
		resultsFile << '\t' << '\t' << "Valid: result = "
			        << result << '\n' << '\n'; 
		cout << "= " << result << '\n';
	} 

} 

//****************************************************************************************************

void resetFlagStack(Stack<int>& intStack, bool& valid)
{
	int result;
	while (intStack.pop(result));
	valid = true;
}  

//**************************************************************************************************** 

/* 

2 4 * 5 + = 13
13 5 % 5 + = 8
15 1 + 2 / 1 - = 7
15 + 1 + 2 / 1 -        invalid
3 4 + 15 10 - * = 35
3 4 + 6 15 10 - *       invalid
2 13 + 14 6 - - 5 * 4 + = 39
35 6 4 2 2 / + * - = 5
3 4 + 1 2 - * 4 2 / 3 - + = -8
3 14 1 2 4 2 3 + % * + - + = 8

*/