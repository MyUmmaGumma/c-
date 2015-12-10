#include<iostream>
#include<string>
using namespace std;

template<class T=int,int SIZE=5>
class Stack
{
	T arr[SIZE];
	int top;
public:
	Stack();
	~Stack();
	void push(const T& item);
	T pop();
	void display();
};

template<class T,int SIZE>
Stack<T,SIZE>::Stack() : top(-1)
{
	cout<<"Stack created..."<<endl;
}

template<class T,int SIZE>
Stack<T,SIZE>::~Stack() 
{
	cout<<"\nStack destroyed..."<<endl;
}

template<class T,int SIZE>
void Stack<T,SIZE>::push(const T& item)
{
	if(top==SIZE-1)
		cout<<"Stack overflow"<<endl;
	else
		arr[++top] = item;
}

template<class T,int SIZE>
T Stack<T,SIZE>::pop()
{
	T item = T();

	if(top==-1)
		cout<<"Stack underflow"<<endl;
	else
		item = arr[top--];

	return item;
}

template<class T,int SIZE>
void Stack<T,SIZE>::display() 
{
	if(top==-1)
		cout<<"Stack underflow"<<endl;
	else
	{
		for(int i=top;i>=0;--i)
			cout<<arr[i]<<"\t";
		cout<<endl;
	}
}

void main()
{
	cout<<"Size : "<<sizeof(Stack<double,1005>)<<endl;
}
