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
	const int SIZE = 5;
	Stack<int,5> *s1 = new Stack<>;
	int i;	

	cout<<"\nPushing elements into the Stack"<<endl;
	for(i=0;i<SIZE+1;++i)
		s1->push(i+1);

	cout<<"\nDisplaying the elements of the Stack"<<endl;
	s1->display();

	cout<<"\nPopping the elements from the Stack"<<endl;
	for(i=0;i<SIZE+1;++i)
		cout<<s1->pop()<<endl;

	cout<<"\nDisplaying the elements of the Stack"<<endl;
	s1->display();

	delete s1;
}
