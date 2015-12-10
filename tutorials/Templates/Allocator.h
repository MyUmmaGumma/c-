template<class T>
class Allocator
{
	typedef T value;
	typedef T& reference;
	typedef T* pointer;
	typedef const T& const_reference;
	typedef const T* const_pointer;
public:
	Allocator()
	{
		cout<<"Allocator"<<endl;
	}
	void allocate(pointer &p,size_t size)
	{
		p = new T[size];
	}
	void construct(reference val,value init)
	{
		val = init;
	}
	void deallocate(pointer p,size_t size)
	{
		// ignore size

		delete[] p;
	}
};

// partial specialization for <char*>

void Allocator<char*>::allocate(char** &p,size_t size)
{
	p = new char*[size];
	for(int i=0;i<size;++i)
		p[i] = new char[20];
}

void Allocator<char*>::construct(char* &val,char* init)
{
	strcpy(val,init);
}

void Allocator<char*>::deallocate(char** p,size_t size)
{
	// use size

	for(int i=0;i<size;++i)
		delete p[i];

	delete[] p;
}

