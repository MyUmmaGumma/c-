#include<iostream>
using namespace std;

class Complex
{
	double real;
	double imag;
public:
	void init(double r,double i)
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
	void sum(const Complex& c1, Complex& c2);
};

void Complex::sum(const Complex& c2, Complex& c3)
{
	c3.real = this->real + c2.real;
	c3.imag = this->imag + c2.imag;
}

void main()
{
	Complex c1,c2,c3;

	c1.init(23.3,45.6);
	c2.init(34.5,-56.7);

	c1.sum(c2,c3);

	c1.display();
	c2.display();
	c3.display();
}