#include <iostream>
using namespace std;

#define ROWS 20
#define COLS 23

class Crossings
{
    string s1, s2, s3, s4;
	char toPrint[ROWS][COLS];
	int lowerlimit;

    public:
    Crossings(string _s1, string _s2, string _s3, string _s4) : s1(_s1), 
            s2(_s2), s3(_s3), s4(_s4)
    {
		for (int i = 0; i < ROWS; i++) {
			for (int j = 0; j <COLS; j++) {
				toPrint[i][j] = '?';
			}
		}
		lowerlimit = 1;
	}

    void matchings()
    {
        size_t found1, found2;
        found1 = s1.find_first_of(s2);
        found2 = s2.find_first_of(s1[found1]);
        if (found1 == string::npos) {
            cout<<"Unable to make two crosses";
			return;
        } else {
#ifdef ONLINE_JUDGE
            cout<<"Found common pos = ("<<found1<<", "<<found2<<") char:"
				<<s1[found1]
                <<" between "<<s1<<" and "<<s2<<endl;
#endif
        }
		
        size_t found3, found4;
		found3 = s3.find_first_of(s4);
        found4 = s4.find_first_of(s3[found3]);
        if (found3 == string::npos) {
            cout<<"Unable to make two crosses";
			return;
        } else {
#ifdef ONLINE_JUDGE
            cout<<"Found common pos = ("<<found3<<", "<<found4<<") char:"
				<<s3[found3]
                <<" between "<<s3<<" and "<<s4<<endl;
#endif
        }
		
		int max_distance = s1.size() + s3.size() + 3;
		int char_dist = s1.size() + 3 + found3;
		//Pad with spaces upper left
		for (int i = 0; i < found2; i++) {
			for (int j = 0; j < found1; j++) {
				toPrint[i][j] = ' ';
			}
		}

		//Print first horizontal word
		for (int i = found2, j = 0; j < s1.size(); j++) {
			toPrint[found2][j] = s1[j];
		}

		//Print first vertical word
		for (int i = found1,j = 0; j < s2.size(); j++) {
			toPrint[j][found1]	= s2[j];
		}

		//Pad with spaces bottom left
		for (int i = found2+1; i < s2.size(); i++) {
			for (int j = 0; j < found1; j++) {
				toPrint[i][j] = ' ';
			}
		}

		// Print second horizontal word
		for (int j = 0; j < s3.size(); j++) {
			toPrint[found2][s1.size() + 3 + j] = s3[j];
		}

		//Pad between first and second horizontal word
		for(int j = s1.size(); j < s1.size()+3; j++) {
			toPrint[found2][j] = ' ';
		}
		
		int i = (found2 - found4);
		if (i < 0) { i = 0; }

		//Pad between first and second vertical word - middle upper
		int j;
		int jlim = (s1.size() + 3 + found3); //there is a term of -1  + 1 here
		int ilim = (found2 > found4 ? found2-1 : found4 -1);
		for (; i <= ilim; i++) {
			for (j = found1+1; j < jlim; j++) {
				toPrint[i][j] = ' ';
			}
		}

		/*Pad between first and second vertical word - middle lower
		i = found2+1;
		jlim = (s1.size() + 3 + found3); //there is a term of -1  + 1 here
		ilim = found2 + s4.size() - found4;
		for (; i <= ilim; i++) {
			for (j = found1+1; j < jlim; j++) {
				toPrint[i][j] = ' ';
			}
		}*/

		j = (found2 - found4);
		if (j < 0) { j = 0; }
		// Print second vertical word
		for (int k = 0; k < s4.size(); k++) {
			toPrint[j+k][s1.size() + 3 + found3] = s4[k];
		}
		lowerlimit = j + s4.size() ;
	
		/*Pad the lower left
		i = s2.size();
		ilim = lowerlimit;
		j = 0;
		jlim = found1+1;
		for (; i <= ilim; i++) {
			for (j = 0 ; j < jlim; j++) {
				toPrint[i][j] = ' ';
			}
		}*/
    }

	void print()
	{
		for (int i = 0; i < lowerlimit; i++) {
			for (int j = 0; j <COLS; j++) {
			//	if (toPrint[i][j] != '?') {	
					cout<<toPrint[i][j];
			//	}
			}
			cout<<endl;
		}
		cout<<endl;
	}
};

int main()
{
    string s1, s2,s3,s4;
    while(cin>>s1) {
        if (!s1.compare("#")) {
            break;
        }
        cin>>s2>>s3>>s4;
        Crossings c(s1,s2,s3,s4);
        c.matchings();
        c.print();
    }
}
