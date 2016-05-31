#include <iostream>
# include <list>
using namespace std;

class Something {
      public:
        int a;
        float b;
        Something (int _a, float _b) : a(_a) , b(_b) {}
};

ostream& operator <<(ostream &os, Something &s)
{
    os <<s.a << "\t"<<s.b<<endl;
    return os;
}

int main()
{
    list <Something *> some[10];
    Something *s1 = new Something (10,2.5);
    some[1].push_back(s1);
    Something *s2 = new Something (100,12.5);
    some[1].push_back(s2);
    Something *s11 = new Something (20,22.5);
    some[4].push_back(s11);
    Something *s22 = new Something (30,82.5);
    some[4].push_back(s22);
    Something *s13 = new Something (100,122.5);
    some[6].push_back(s13);
    Something *s23 = new Something (1000,112.5);
    some[7].push_back(s23);
    for (int i = 0; i < 10; i++) {
        list<Something *>::iterator it = some[i].begin();
        cout<<"Printing list at index i = "<<i<<endl;
        for (;it != some[i].end(); it++) {
            cout<<*(*it);       
        }
    }
}
