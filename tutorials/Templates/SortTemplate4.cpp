#include<iostream>
#include<string>
using namespace std;

template<class T>
void Swap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
void sort(T* arr,int size)
{
	int i,j;

	for(i=0;i<size-1;++i)
		for(j=i+1;j<size;++j)
			if(arr[i]>arr[j])
				Swap(arr[i],arr[j]);
}

// specialization for <char*>

void sort(char *arr[5],int size)
{
	int i,j;

	for(i=0;i<size-1;++i)
		for(j=i+1;j<size;++j)
			if(strcmp(arr[i],arr[j])>0)
				Swap(arr[i],arr[j]);
}

template<class T>
void display(T* arr,int size)
{
	for(int i=0;i<size;++i)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

void main()
{
	char *x[5] = {"Tata","Elxsi","Bangalore","India","C++"};

	cout<<"Before sorting..."<<endl;
	display(x,5);

	sort(x,5);
	
	cout<<"After sorting..."<<endl;
	display(x,5);
}