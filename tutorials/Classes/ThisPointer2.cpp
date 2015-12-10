#include<iostream>
#include<string>
using namespace std;

class Person
{
	string name;
	int age;
public:
	void init(string name,int a)
	{
		this->name = name;
		age = a;
	}
	Person greater(Person p)
	{
		if(this->age > p.age)
			return *this;
		else
			return p;

	}
	void display()
	{
		cout<<name<<"\t"<<age<<endl;
	}
};

void main()
{
	Person p1,p2,p3;

	p1.init("Abc",25);
	p2.init("Xyz",21);

	p3 = p1.greater(p2);

	p1.display();
	p2.display();
	p3.display();
}