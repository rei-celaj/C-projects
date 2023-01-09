#include "Employee.h" 

int Employee::counter = 0;
//**************************************************************************************************** 

Employee::Employee(Name n, double r)
{
	counter += 10; 
	id = counter;
	empName = n; 
	payRate = r;
}

//**************************************************************************************************** 

void Employee::shutDown(std::ofstream& outputFile)
{
	outputFile << type << '\n' << id << '\n';  
	empName.shutDown(outputFile);
	outputFile << payRate << '\n';
}