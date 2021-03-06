#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
#include"Array.h"
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

template<class T>
struct Negate
{
	T operator()(T a)
	{
		return -a;
	}
};

template<class T>
struct Logical_not				// Unary predicate
{
	bool operator()(T a)
	{
		return !a;
	}
};

// Unary Transform

template<class II,class OI,class UF>
OI Transform(II F1,II L1,OI F2,UF uf)
{
	for(;F1!=L1;++F1,++F2)
		*F2 = uf(*F1);	
	return F2;
}

// Binary Transform

template<class II1,class II2,class OI,class BF>
OI Transform(II1 F1,II1 L1,II2 F2,OI F3,BF bf)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = bf(*F1,*F2);	
	return F3;
}

template<class T>
void display(T F,T L)
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

template<class T,class OI>
void initialize(OI F,OI L,T start)
{
	for(;F!=L;++F,++start)
		*F = start;
}

void main()
{
	Array<int> a1(5);
	vector<int> v1(5);
	list<int> l1(5);

	vector<int>::iterator p = v1.begin();

	initialize(a1.begin(),a1.end(),1);
	initialize(v1.begin(),v1.end(),10);
	initialize(l1.begin(),l1.end(),20);

	display(a1.begin(),a1.end());
	display(v1.begin(),v1.end());
	display(l1.begin(),l1.end());
}