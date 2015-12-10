#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
	friend Complex sum(const Complex& c1, Complex& c2);
public:
	Complex() : real(0), imag(0) {}
	Complex(double r,double i)
	{
		real = r;
		imag = i;
	}
	void display()
	{
		if(imag>=0)
			cout<<real<<" +i "<<imag<<endl;
		else
			cout<<real<<" -i "<<-imag<<endl;
	}	
};

Complex sum(const Complex& c1, Complex& c2)
{
	return Complex(c1.real + c2.real,c1.imag + c2.imag);
}

void main()
{
	Complex c1(23.3,45.6),c2(34.5,-56.7),c3;

	c3 = sum(c1,c2);

	c1.display();
	c2.display();
	c3.display();
}