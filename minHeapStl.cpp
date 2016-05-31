#include <iostream>
using namespace std;

#include <iostream>
       #include <algorithm>
       #include <vector>
       using namespace std;

       bool comp(const int& a, const int& b)
       {
          return a<=b?false:true;
       }

       int main () 
       {
         int myints[] = {10,20,30,5,15, 100, -1,40, -5};
         vector<int> v(myints,myints+9);
         vector<int>::iterator it;
         make_heap(v.begin(), v.end(), std::greater<int>());
         cout << "initial min heap   : " << v.front() << endl;
         for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];
         cout<<endl;

         pop_heap (v.begin(),v.end(), std::greater<int>());
         cout << "after pop min heap   : " << v.front() << endl;
         for (unsigned i=0; i<v.size(); i++) cout << " " << v[i];
         cout<<endl;
       }
