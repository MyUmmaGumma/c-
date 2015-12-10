#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	void init(double r,double i);
	void display();
	void invokingObject()
	{
		cout<<this<<endl;
	}
}*This;

void Complex::init(double r,double i)
{
	real = r;
	imag = i;
}

void Complex::display()
{
	if(imag>=0)
		cout<<real<<" +i "<<imag<<endl;
	else
		cout<<real<<" -i "<<-imag<<endl;
}

void main()
{
	Complex c1,c2;

	c1.init(23.3,45.6);
	c2.init(34.5,-56.7);

	c1.display();
	c2.display();

	c1.invokingObject();
	c2.invokingObject();
}