#include <iostream>
#include <vector>
using namespace std;
#include <stdint.h>
#include <limits.h>

uint64_t
mps(vector<int> &v)
{
    int64_t max = INT_MIN, running = 1;
    int64_t min = 0;
    for (int i=0; i<v.size(); i++) {
        if (v[i] < 0) {
            if (min < 0) {
                running = min * v[i];
                if (running > max) {
                    max = running;
                    min = min * v[i];
                } else {
                    min = v[i];
                    running = 1;
                }
            } else {
                min = running * v[i];
                running = 1;
            } 
            if (max < v[i]) {
                max = v[i];
            }
        } else {
            if (running *v[i] > max) {
                max = running * v[i];
                running = max;
            } else {
                running = (running > 0) ? running*v[i] : v[i];
                if (max <= 0) {
                    max = v[i];
                }
            }
            min = min * v[i];
        }
    }
    return max;
}

int main()
{
    int myints[] = {1,2,-3,5,15, 10, -1,4, -5};
    vector<int> v(myints,myints+9);
    cout<<mps(v)<<endl;
    int myints1[] = {-1,-2,-3, -4, -5};
    vector<int> v1(myints1,myints1+5);
    cout<<mps(v1)<<endl;
}
