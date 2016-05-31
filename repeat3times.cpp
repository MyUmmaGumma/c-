#include <iostream>
using namespace std;

int repeat3(int *arr, int len)
{
    int sum = 0;
    for(int i = 0; i < len; i++) {
        sum = sum ^ arr[i];
    }
    cout<<sum;
    return sum;
}

int main()
{
    int a[4] = {10,20,20,10};
    repeat3(a, 4);
}
