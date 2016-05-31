#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool find1(vector<pair<int, int> > v)
{
    return (find(v.begin(), v.end(), make_pair(3, 50)) != v.end());
}

typedef vector<vector<pair<int, int> > > arrayofcycles;
int main()
{
    arrayofcycles c;
    for (int i = 0; i < 10; i++) {
        vector<pair<int, int> > v;
        for (int j = 0; j < 5; j++) {
            v.push_back(make_pair(i, j));
        }
        c.push_back(v);
    }

    pair<int, int> p = make_pair(7,4);
    if (find_if(c.begin(), c.end(), [p](const std::vector<pair<int, int> > &v)
        {
            return (find(v.begin(), v.end(), p) != v.end());
        }
        ) != c.end()) {
        cout<<"Element found"<<endl;
    } else {
        cout<<"Element not found"<<endl;
    }
    
}
