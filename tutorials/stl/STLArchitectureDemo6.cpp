#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<functional>
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

template<class II1,class II2,class OI,class BF>
void Transform(II1 F1,II1 L1,II2 F2,OI F3,BF bf)
{
	for(;F1!=L1;++F1,++F2,++F3)
		*F3 = bf(*F1,*F2);	
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

void main()
{
	vector<int> v1(5),v2(5);
	list<int> l1;
	int i;

	for(i=0;i<5;++i)
	{
		v1[i] = i+1;
		l1.push_back(i+11);
	}

	Transform(v1.begin(),v1.end(),l1.begin(),v2.begin(),Plus<int>());

	display(v1.begin(),v1.end());
	display(l1.begin(),l1.end());
	display(v2.begin(),v2.end());
}