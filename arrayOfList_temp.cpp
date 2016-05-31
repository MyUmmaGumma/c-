#include <iostream>
# include <list>
using namespace std;

t
emplate <class T>
class Something {
      public:
        int a;
        float b;
        T c;
        Something (int _a, float _b) : a(_a) , b(_b) {}
};

template <class T>
ostream& operator <<(ostream &os, Something<T> &s)
{
    os <<s.a << "\t"<<s.b<<endl;
    return os;
}

int main()
{
    list <Something<int> *> some[10];
    Something<int> *s1 = new Something<int> (10,2.5);
    some[1].push_back(s1);
    for (int i = 0; i < 10; i++) {
        list<Something<int> *>::iterator it = some[i].begin();
        cout<<"Printing list at index i = "<<i<<endl;
        for (;it != some[i].end(); it++) {
            cout<<*(*it);       
        }
    }
}
