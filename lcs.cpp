#include <iostream>
using namespace std;

class LCS {
    private:
        string str1;
        string str2;
        string lcs_str;
        char **reconstruct;
        int **temp;
        int str1_l, str2_l;
    
    public:
        LCS(string s1,string s2) 
        {
            str1 = s1;
            str2 = s2;
            str1_l = str1.size();
            str2_l = str2.size();
            temp = new int*[str1_l];
            reconstruct = new char*[str1_l];
            for (int i = 0; i < str1_l; i++) {
                temp[i] = new int[str2_l];
            }
            for (int i = 0; i < str1_l; i++) {
                for (int j = 0; j < str2_l; j++) {
                    temp[i][j] = -1;
                }
            }
        }

        ~LCS() 
        {
            cout<<"Memoized matrix is:"<<endl<<" ";
            for (int j = 0; j < str2_l; j++) {
                cout<<" "<<str2[j];
            }
            cout<<endl;
            for (int i = 0; i < str1_l; i++) {
                cout<<str1[i]<<" ";
                for (int j = 0; j < str2_l; j++) {
                    cout<<temp[i][j]<<" ";
                }
                cout<<endl;
            }
            for (int i = 0; i < str1_l; i++) {
                delete temp[i];
                temp[i] = NULL;
            }
            delete []temp;
            temp = NULL;
        }
    
    private:
        int lcs(string str1, string str2, int i1, int j1)
        {
            int ret;
            static int count = 0;
           
             //Base Case
            if (i1 == str1_l || j1 == str2_l) {
                return 0;
            }

            //Memoise
            if (temp[i1][j1] != -1) {
                return temp[i1][j1];
            } 

            count++;
            for(int i = i1; i < str1_l; i++) {
                for(int j = j1; j < str2_l; j++) {
                    int v1 = -1, v2 = -1, v3 = -1, max_lcs = -1;
                    // First part of equation
                    if (str1.at(i) == str2.at(j)) {
                        v1 = 1 + lcs(str1, str2, i+1, j+1);
                    } else {
                        // Max of the other two
                        v2 = lcs(str1, str2, i+1, j);
                        v3 = lcs(str1, str2, i, j+1);
                        if (v2 > v3) {
                            max_lcs = v2;
                        } else {
                            max_lcs = v3;
                        }
                    }
                    //Max with the first part of the equation
                    if (v1 > max_lcs) {
                        max_lcs = v1;
                    }
                    // Update memoised array
                    if (temp[i][j] < max_lcs) {
                        temp[i][j] = max_lcs;
                    }
                }
            }
            
            return temp[i1][j1];
        }
    public:
        void compute_lcs()
        {
            cout<<"Max lcs is "<<lcs(str1, str2, 0, 0)<<endl;
            cout<<"String is "<<lcs_str<<endl;
        }        
};

int main()
{
    string str1 = "ABCDGH";
    string str2 = "AEDFHR";
    LCS l(str1, str2);
    l.compute_lcs();
}
