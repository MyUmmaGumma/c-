#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vint;
typedef vector<vint > vvint;

vvint pp(int a)
{
    if (a==1) {
        vvint v1;
        vint v2;
        v2.push_back(1);
        v1.push_back(v2);
        return v1;
    }
    vvint ans = pp(a-1);
    vint v1, v2, v3;
    for (int i = 1; i < 2*a; ++i) {
       v1.push_back(a);
    }
    vvint::iterator iter1 = ans.begin();
    for (;iter1 != ans.end(); iter1++) {
        (*iter1).push_back(a);
        (*iter1).insert((*iter1).begin(), a);
    }

    for (int i = 1; i < 2*a; ++i) {
       v2.push_back(a);
    }
    ans.insert(ans.begin(), v1);
    ans.push_back(v2);
    return ans;
}

void
print(vvint v)
{
    for(vvint::iterator iter1 = v.begin(); iter1 != v.end(); iter1++) {
        for(vint::iterator iter2 = (*iter1).begin(); iter2 != (*iter1).end(); ++iter2) {
            cout<<*iter2<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    vvint v1 =  pp(9);   
    print(v1);
}
