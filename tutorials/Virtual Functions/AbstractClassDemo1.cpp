#include<iostream>
#include<string>
using namespace std;

class Figure
{
protected:
	int dim1,dim2;
public:
	Figure() : dim1(0), dim2(0) {}
	Figure(int d1,int d2) : dim1(d1), dim2(d2) {}
	virtual operator string()
	{
		return "Figure";
	}
	virtual int area()
	{
		cout<<"Figure not defined"<<endl;
		return 0;
	}
};

class Rectangle : public Figure
{
public:
	Rectangle() {}
	Rectangle(int dim1,int dim2) 
		: Figure(dim1,dim2) {}
	int area()
	{
		return dim1 * dim2;
	}
	operator string()
	{
		return "Rectangle";
	}
};

class Triangle : public Figure
{
public:
	Triangle() {}
	Triangle(int dim1,int dim2) 
		: Figure(dim1,dim2) {}
	int area()
	{
		return 0.5 * dim1 * dim2;
	}
	operator string()
	{
		return "Triangle";
	}
};

class Square : public Figure
{
public:
	Square() {}
	Square(int dim) 
		: Figure(dim,dim) {}
	int area()
	{
		return dim1 * dim2;
	}
	operator string()
	{
		return "Square";
	}
};

class Client
{
public:
	static void execute(Figure *f)
	{
		cout<<"The figure is "<<string(*f)<<endl;
		cout<<"The area is : "<<f->area()<<endl<<endl;
	}
};

void main()
{
	Client *client = new Client;

	client->execute(new Rectangle(10,20));
	client->execute(new Square(10));
	client->execute(new Triangle(10,5));

	client->execute(new Figure(10,5));
}