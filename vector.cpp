#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vint;

void foo(vint &v)
{
    v[0] = 100;   
}

int main()
{
    vector<int> i;
    i.push_back(10);
    i.push_back(20);
    i.push_back(30);
    foo(i);
    for(vint::iterator it = i.begin(); it != i.end(); ++it) {
        cout<<*it<<endl;
    }
}
