#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

class Coords
{
	public:
	Coords(int x1, int y1, int x2) : _x1(x1), _y1(y1), _x2(x2) {}
	int _x1;
	int _y1;
	int _x2;
};

void ordering(vector<Coords *> &vcords)
{
	bool emit_y1 = false;
	vector<Coords *>::iterator v1 = vcords.begin();
	int new_x1, new_x2, new_y1, x1 = -1, x2 = -1, y1 = -1, x3,x4,y2;
	for( ;v1 != vcords.end(); v1++) {
		Coords *c1 = *v1;
		x3 = c1->_x1;
		x4 = c1->_x2;
		y2 = c1->_y1;
		if (x1 == -1) {
			x1 = x3;
			x2 = x4;
			y1 = y2;
			continue;
		}
		
		if (y2 > y1) {
			cout<<x1<<" ";
		}
		if (x3 < x2) {
			if (y1 > y2) {
				if (x4 < x2) {
					if (emit_y1 == false) {
						emit_y1 = true;
						cout<<y1<<" ";
					}
					x1 = x3;
					continue;
				} else if (x4 > x2) {
					if (emit_y1 == false) {
						emit_y1 = true;
						cout<<y1<<" ";
					}
					cout<<x2<<" ";
					cout<<y2<<" ";
					x1 = x3; 
					x2 = x4;
					y1 = y2;
					continue;
				}
			} else (y2 > y1) {
				if (x4 < x2) {
					cout<<y1<<" ";
					cout<<x3<<" ";
						cout<<y2<<" ";
					cout<<x4<<" ";
					cout<<y1<<" ";
					x1 = x3;
					x2 = x2;
					y1 = y1;
				} else (x4 > x2) {
					
				}
			}
		}
	}
}

int main()
{
	int x1,x2,y1;
	vector<Coords *> vcords;
	while (cin>>x1>>y1>>x2) {
		Coords *c= new Coords(x1, y1, x2);	
		vcords.push_back(c);
	}
	ordering(vcords);
}



