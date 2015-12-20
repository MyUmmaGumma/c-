#include <iostream>
using namespace std;
#include <limits.h>

//102 - Ecological Bin Packing
// 0 - Brown, 1- Green, 2 - Clear
int permutes[6][3] = { {0,1,2},
                        {0,2,1},
                        {1,0,2},
                        {1,2,0},
                        {2,0,1},
                        {2,1,0}};

//The colour of bin_num is color. Move bottles from other bins of this color to bin_num
int moveBottles(int color, int bin_num, int (*a)[3]) {
	int moves = 0;
	moves += a[(bin_num+1) % 3][color] + a[(bin_num+2)%3][color];
	return moves;
}

string getString(int i)
{
	switch (i) {
	case 0: return "BGC";
	case 1: return "BCG";
	case 2: return "GBC";
	case 3: return "GCB";
	case 4: return "CBG";
	case 5: return "CGB";
	}
	return "None";
}

int main()
{
    int a[3][3];
	int i = 0, j = 0;
	string a1;
    while (cin >>a[0][0]>>a[0][1]>>a[0][2]>>a[1][0]>>a[1][1]>>a[1][2]>>a[2][0]>>a[2][1]>>a[2][2]) {
		int min = INT_MAX;
		string a1; 
		for (i = 0; i < 6; ++i) {
			int iter_total = 0;
			for (j = 0; j < 3; ++j) {
				iter_total += moveBottles(permutes[i][j], j, a);
			}
			if (iter_total < min) {
				min = iter_total;
				a1 = getString(i);;
			} else if (iter_total == min) {
				string a2 = getString(i);
				if (a1.compare(a2) > 0) {
					a1 = a2;
				}
			}
		}
		cout <<a1<<" "<<min<<endl;
	}
}
