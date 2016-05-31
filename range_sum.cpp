#include <iostream>
using namespace std;

int low=5, high = 30;

bool
sum_within_range(int sum)
{
	return (sum >= low && sum <= high);	
}

int main()
{
	int a[] = {20,30,-10,40,-80, 1,4,5, -30, 45};
	int i = 0, max_sum = 0, sum = 0, count = 0;
	bool sum_in_range = false;

	for (i = 0; i < 10; i++) {
		if (a[i] > high) {
			continue;
		}
		sum = sum + a[i];
		if (sum_within_range(sum)) {
			sum_in_range = true;
		} else {
			sum_in_range = false;
			sum = a[i];
		} 
		if (sum_in_range) {
			count++;
		} else {
		}

	}
	cout<<"Count = "<<count<<endl;
}
