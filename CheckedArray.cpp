#include <iostream>
using namespace std;

template <class T>
class CheckedArray
{
    private:
        T *a; 
        int count;

    public:
        CheckedArray(T *input, int acount)
        {
            a = new T[acount];
            for (int i = 0; i < acount; ++i) {
                a[i] = input[i];
            }
            count = acount;
        }
        
        T operator [](int i)
        {
            if (i >= 0 && i < count) {
                return a[i];
            }
			return 0;
        }

		~CheckedArray()
		{
			delete []a;
			a = NULL;
			count = 0;
		}
	
		int getCount()
		{
			return count;
		}

		CheckedArray(CheckedArray<T> & c)
		{
			a = new T[c.getCount()];
			for (int i = 0; i < c.getCount(); ++i) {
				a[i] = c[i];
			}
			count = c.getCount();
		}

		CheckedArray<T> & operator=(CheckedArray<T> *rhs)
		{
			if (this == rhs) {
				return rhs;
			}
			count = rhs->getCount();
			delete []a;
			a = new T[count];
			for (int i = 0; i < count; ++i) {
				a[i] = rhs[i];
			}
			return this;
		}
};

int main()
{
	int nums[5] = {10,40,30,20,50};
    CheckedArray<int> c(nums, 5);
	double nums1[5] = {1.4,4.6,3.3,2.9,5.8};
    CheckedArray<double> c1(nums1, 5);
	cout<<c[2]<<c1[4]<<endl;
	CheckedArray<int> c2(c);
	cout<<c[0] <<endl;
	double d1[2] = {1.04, 2.05};
	CheckedArray<double> f(d1, 2);
	cout<<f[0];
	f = c1;
	cout<<f[0];
}
