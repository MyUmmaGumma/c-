#include <iostream>
using namespace std;

bool
sum_within_range(int low, int high, int sum)
{
	return (sum >= low && sum <= high);	
}

int main()
{
	int a[] = {-1,2,3,-2};
	int i = 0, max_sum = 0, sum = 0, count = 0;
	for (i = 0; i < 4; i++) {
		if (a[i] < 0) {
			if (a[i] + sum > 0) {
				sum = sum + a[i];
			} else {
				if (max_sum < sum) {
					max_sum = sum;
				}
				sum = 0;
			}
		} else {
			sum += a[i];
		}
		if (max_sum < sum) {
			max_sum = sum;
		}
	}
	cout<<"Sum = "<<max_sum<<endl;
}
