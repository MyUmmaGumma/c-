#include<iostream>
#include<string>
using namespace std;

#define SIZE 5

template<class T>
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

template<class T>
Stack<T>::Stack() : top(-1)
{
	cout<<"Stack created..."<<endl;
}

template<class T>
Stack<T>::~Stack() 
{
	cout<<"\nStack destroyed..."<<endl;
}

template<class T>
void Stack<T>::push(const T& item)
{
	if(top==SIZE-1)
		cout<<"Stack overflow"<<endl;
	else
		arr[++top] = item;
}

template<class T>
T Stack<T>::pop()
{
	T item = T();

	if(top==-1)
		cout<<"Stack underflow"<<endl;
	else
		item = arr[top--];

	return item;
}

template<class T>
void Stack<T>::display() 
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
	Stack<int> s1;
	int i;

	cout<<"\nPushing elements into the Stack"<<endl;
	for(i=0;i<SIZE+1;++i)
		s1.push(i+1);

	cout<<"\nDisplaying the elements of the Stack"<<endl;
	s1.display();

	cout<<"\nPopping the elements from the Stack"<<endl;
	for(i=0;i<SIZE+1;++i)
		cout<<s1.pop()<<endl;

	cout<<"\nDisplaying the elements of the Stack"<<endl;
	s1.display();
}
