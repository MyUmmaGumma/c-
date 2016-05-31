#include <iostream>
#include <map>
#include <vector>
#include <queue>
using namespace std;

class Relations
{
	private:
		map<string, string> pc;
		map<string, vector<string> > cp;
	public:
		void add_relation(string p, string c)
		{
			pc[p] = c;
			if (cp.find(c) != cp.end()) {
				vector<string>parents = cp[c];
				parents.push_back(p);
				cp[c] = parents;
			} else {
				vector<string> ps;
				ps.push_back(p);
				cp[c] = ps;
			}
		}
		void print()
		{
			for(auto it = pc.cbegin(); it != pc.cend(); it++) {
				cout<<"P:"<<(*it).first<<" C:"<<(*it).second<<endl;
			}
			for(auto it = cp.cbegin(); it != cp.cend(); it++) {
				vector<string> ps = (*it).second;
				cout<<"Printing parents for "<<(*it).first<<"\t";
				for_each(ps.begin(), ps.end(),
					 [](string const& i) { cout<<i<<", "; });
				cout<<endl;
			}
		}

		string get_parent_level(int level)
		{
			if(level == 0) {
				return "parent";
			} else if (level == 1) {
				return "grand parent";
			} else {
				level = level - 1;
				string str="";
				for(int i = level; i > 0; i--) {
					str += "great ";
				}
				str += "grand parent";
				return str;
			}
		}
	
		string get_child_level(int level)
		{
			if(level == 0) {
				return "child";
			} else if (level == 1) {
				return "grand child";
			} else {
				level = level - 1;
				string str="";
				for(int i = level; i > 0; i--) {
					str += "great ";
				}
				str += "grand child";
				return str;
			}
		}

		string find_parent_relation(string str1, string str2)
		{
			queue<string> q;
			map<string, string> pred;
			vector<string> visited;
			
			q.push(str1);
			q.push("");
			while(!q.empty()) {
				string toExplore = q.front();
				q.pop();
				vector<string> ns = cp[toExplore];
				if (find(ns.begin(), ns.end(), str2)
						!= ns.end()) {
					pred[str2] = toExplore;
					break;
				}
				for(auto it = ns.begin(); it != ns.end(); it++) {
					if (find(visited.begin(), visited.end(), *it) == 
							visited.end()) {
							visited.push_back(*it);
							q.push(*it);
							pred[*it] = toExplore;
						}
				}
			}
				auto it = find_if(pred.begin(), pred.end(),
					[str2](pair<string, string> p){
					if (!p.second.compare(str2)) {
						return true;
					} else {
						return false;
					}
				});
				
				string rel;
				if (it != pred.end()) {
					string temp = str1;
					int level = 0;
					while(pred[temp] != str2) { 
						temp = pred[temp];
						level++;
					}
					return get_parent_level(level);
				} else {
					rel = "no relation";
				}
				return rel;
	}

	vector<string> get_parent_string(string s)
	{
		string temp = s;
		vector<string> ret;
		while(pc.find(temp) != pc.end()) {
			temp = pc[temp];
			ret.push_back(temp);
		}
		return ret;
	}	

	// Try to find if s1 is a child of s2
	string find_child_relation(string s1, string s2)
	{
		string temp = s1;
		int level = 0;
		while(pc.find(temp) != pc.end()) {
			if(!pc[temp].compare(s2)) {
				return get_child_level(level);		
			} else {
				level++;
			}
			temp = pc[temp];
		}

		temp = s2;
		level = 0;
		while(pc.find(temp) != pc.end()) {
			if(!pc[temp].compare(s1)) {
				return get_parent_level(level);		
			} else {
				level++;
			}
			temp = pc[temp];
		}
		return "";
	}
	
	string find_cousin_relation(string s1, string s2)
	{
		vector<string> ps1, ps2;
		ps1 = get_parent_string(s1);
		ps2 = get_parent_string(s2);
		if (ps1.empty() || ps2.empty()) {	
			return "";
		}
		int j = 0, n= 0, m = 0;
		for (auto it1 = ps1.begin(); it1 != ps1.end(); it1++,n++) {
			m = 0;
			for (auto it2 = ps2.begin(); it2 != ps2.end(); it2++,m++) {
				if (!(*it1).compare(*it2)) {
					j = -1;
					break; 
				}
			}
				if (j == -1) {
					break; 
				}
		}

		if (m == 0 && n == 0) {
			return "";
		}
		if (m-n == 0) {
			return "sibling";
		} else {
			//make the string n cousin removed m
			int k = min(m,n);
			j = abs(n-m);
			string str = to_string(k) + " cousin removed " +
							to_string(j);
			return str;
		}
	}
	
	string get_relation(string s1, string s2)
	{
		string a = find_child_relation(s1, s2);
		if (!a.empty()) {
			return a;
		}
		string b = find_cousin_relation(s1, s2);
		if (!b.empty()) {
			return b;
		}
		/*	return find_parent_relation(s1, s2); */
		
		return "no relation";
	}
};

int main()
{
	Relations r;
	string parent, child;

	while(cin>>parent>>child) {
		if(!parent.compare("no.child")) {
			break;
		}
		r.add_relation(parent, child);
	}
	while(cin>>parent>>child) {
		cout<<r.get_relation(parent, child)<<endl;
	}
}
