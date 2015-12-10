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

template<class T>
void display(T* arr,int size)
{
	for(int i=0;i<size;++i)
		cout<<arr[i]<<"\t";
	cout<<endl;
}

template<class T>
void client()
{
	T x[5];
	for(int i=0;i<5;++i)
		cin>>x[i];

	cout<<"Before sorting..."<<endl;
	display(x,5);

	sort(x,5);
	
	cout<<"After sorting..."<<endl;
	display(x,5);
}

void main()
{
	int type;

	cout<<"Which type ? (1.int, 2.double) : ";
	cin>>type;

	if(type==1)
		client<int>();
	else if(type==2)
		client<double>();
}