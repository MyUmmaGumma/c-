#include<iostream>
using namespace std;

template<class T>
struct Plus
{
	T operator()(T a,T b)
	{
		return a+b;
	}
};

template<class T>
struct Minus
{
	T operator()(T a,T b)
	{
		return a-b;
	}
};

template<class T>
struct Multiplies
{
	T operator()(T a,T b)
	{
		return a*b;
	}
};

template<class T>
struct Divides
{
	T operator()(T a,T b)
	{
		return a/b;
	}
};

template<class T>
struct Greater			// binary predicates
{
	bool operator()(T a,T b)
	{
		return a>b;
	}
};

template<class T,class BF>
void Transform(T *F1,T *L1,T *F2,T *F3,BF bf)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = bf(*F1,*F2);	// bf.operator()(*F1,*F2);
}

template<class T>
void display(T *F,T *L)
{
	for(;F!=L;++F)
		cout<<*F<<"\t";
	cout<<endl;
}

// my own algorithm

int complexOpn(int a,int b)
{
	return 10*a + 5*b;
}

void main()
{
	int a[] = {1,2,3,4,5};
	int b[] = {6,7,8,9,10};
	int c[] = {0,0,0,0,0};

	Transform(a,a+4,b+1,c,Plus<int>());

//	Transform(a,a+4,b+1,c,complexOpn);

	display(a,a+5);
	display(b,b+5);
	display(c,c+5);
}