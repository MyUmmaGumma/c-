#include<iostream>
#include<string>
using namespace std;

#define SwapNum(a,b,temp)\
	*temp = *a;		\
	*a = *b;			\
	*b = *temp;		
	

template<class T>
void Swap(T& a,T& b)
{

}

template<class T>
void sort(T* arr,int size)
{

}

template<class T>
void display(T* arr,int size)
{

}


void main()
{
	int a = 10, b= 5, dummy=0;
	
	cout<<a<<"\t"<<b<<endl;

	SwapNum(&a,&b,&dummy);

	cout<<a<<"\t"<<b<<endl;
}