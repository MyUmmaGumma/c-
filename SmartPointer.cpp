#include <iostream>
using namespace std;

template <class T>
class SmartPointer
{
	private:
		T *_data;
		int _refCount;
	public:
		SmartPointer(T data) 
		{
			_data = new T();
			*_data = data;	
			_refCount = 0;
		}
 
		const T&  operator *(void) const
		{
			if (_refCount >=0) {
				return *_data;
			}
		}	

		T& operator *(void)
		{
			return *_data;
		}

		SmartPointer(SmartPointer<T> &s)
		{
			_data = new T();
			*_data = s.GetData();
			_refCount = 0;
		}

		void operator =(SmartPointer<T> &s)
		{
			*_data = s.GetData();
			s.incRefCount();
			_refCount = 1;
		}
		
		T GetData(void)
		{
			return *_data;
		}

		void incRefCount(void)
		{
			_refCount++;
		}

		void decRefCount(void)
		{
			_refCount--;
			if (_refCount == 0)
			{
				delete (_data);
			}
			_data = NULL;
		}

		~SmartPointer()
		{
			if (_refCount == 0)
			{
				delete (_data);
			}
			_data = NULL;
		}
};
