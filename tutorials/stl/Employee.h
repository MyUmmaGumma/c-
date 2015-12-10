#include<iostream>
#include<string>
using namespace std;

class Employee
{
	string empId;
	string name;
public:
	Employee() {}
	Employee(string id,string nm)
		: empId(id), name(nm) {}
	string getName() const
	{
		return name;
	}
	string getEmpId() const
	{
		return empId;
	}
};
