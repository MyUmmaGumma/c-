#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
typedef pair<int, float> edge;

int main()
{
    map<int, vector<edge> > adj_list;
    //No checks for empty for both key of the map and for the value
    adj_list[1].push_back(make_pair(1,2.4));
}
