#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#include <math.h>

typedef pair<int, double> edge;
typedef map<int, vector<edge> > AdjList;
typedef vector<int> vint;
typedef vector<vector<pair<int, int> > > arrayofcycles;
 
class Graph {
    
    typedef void (Graph::*for_each_edge)(int, int , double);
    private:
        map<int, vector<edge> > adj_list;
		double **adj_mat;
        int verts;
        int *predecessor;
        double *shortest_path_estimate;
        arrayofcycles arrc;

    public:
        Graph(int n) 
        {
            verts = n;
            vector<edge> zero_vertex;
            for(int i = 0; i < n; i++) {
                edge e = make_pair(i, 1.0);
                zero_vertex.push_back(e);                
            }
            adj_list[0] = zero_vertex;
            predecessor = new int[n+1];
            shortest_path_estimate = new double [n+1];
			adj_mat = new double*[verts+1];
			for (int i =0; i < verts+1; i++) {
				adj_mat[i] = new double [verts+1];
			}
        }

        void addEdge(int x, int y, double w)
        {
            //adj_list[x].push_back(make_pair(y, w));
			adj_mat[x][y] = w;
        }
    
    private:
        void print_verts()
        {
#ifndef ONLINE_JUDGE
            AdjList::const_iterator iter = adj_list.cbegin();
            cout<<endl;
            while (iter != adj_list.cend()) {
                int vertex = (*iter).first;
                cout<<"Adjancency list for: "<<vertex<<": ";
                vector<edge> v = (*iter).second;
                vector<edge>::iterator iter1 = v.begin();
                while (iter1 != v.end()) {
                    cout<<"("<<(*iter1).first<<", "<<(*iter1).second<<"), ";
                    iter1++;
                }
                cout<<endl;
                iter++;
            }
            cout<<"Predecessor: ";
            for (int i = 0; i <= verts; ++i) {
                cout<<predecessor[i]<<" ";
            }
            cout<<endl;
            cout<<"SPE: ";
            for (int i = 0; i <= verts; ++i) {
                cout<<shortest_path_estimate[i]<<" ";
            }
            cout<<endl;
#endif
        }

        #define NIL -1
        void initialize_sssp()
        {
            int source = 0;
            // We are adding an extra vertex - hence the less than equal to
            for (int i = 0; i <= verts; i++) {
                if (i != source) {
                    shortest_path_estimate[i] = INT_MAX;
                    predecessor[i] = NIL;
                } else {
                    shortest_path_estimate[source] = 0;
                    predecessor[i] = NIL;
                }
            }
        }

        void relax(int u, int v, double w)
        {
            if (shortest_path_estimate[v] > shortest_path_estimate[u] + w) {
                shortest_path_estimate[v] = shortest_path_estimate[u] + w;
                predecessor[v] = u;
            }
        }

        //Try to find whether an edge is already part of a cycle, if not
        // traverse backwards and find cycle out
        void find_cycle(pair<int, int> p)
        {
            if (find_if(arrc.begin(), arrc.end(), 
                [p](const std::vector<pair<int, int> > &v)
                    {
                        return (find(v.begin(), v.end(), p) != v.end());
                    } ) != arrc.end()) 
            {   
                cout<<"The vertex ("<<p.first<<", "<<p.second;
                cout<<") exists in another cycle"<<endl;
            } else {
                vector<pair<int, int> > cycl;
                int start = p.first, u, v;
                do {
                    //insert nodes in the cycle until the (u, v) is 
                    //such that v = start. Once it is equal to start
                    // insert the final edge after the while
                    cout<<"The vertex ("<<p.first<<", "<<p.second;
                    cout<<") was added to a cycle"<<endl;
                    cycl.push_back(p);
                    v = predecessor[p.second];
                    u = p.second;
                    p = make_pair(u, v);
                } while (v != start);
                cycl.push_back(p);
                cout<<"The vertex ("<<p.first<<", "<<p.second;
                cout<<") was added to a cycle"<<endl;
                arrc.push_back(cycl);
                cout<<"Added to the array of cycles";
            }    
        }

        //find negative edge weight cycle
        void fnewc(int u, int v, double w) 
        {
            if (shortest_path_estimate[v] > shortest_path_estimate[u] + w) {
                cout<<"Negative edge("<<u<<", "<<v<<") weight cycle possible"<<endl;
                //find_cycle(make_pair(u,v));
            }
        }

        void print_pred(int v)
        {
            int source = 0;
            cout<<"Printing predecessor for v = "<<v<<endl;
            while (predecessor[v] != source) {
                cout<<predecessor[v]<<" "<<endl;
                v = predecessor[v];
            }
            cout<<endl;
        }


        bool apply_op_for_each_edge(for_each_edge functor)
        {
            AdjList::iterator iter = adj_list.begin();
            while (iter != adj_list.end()) {
                int vertex = (*iter).first;
                vector<edge> v = (*iter).second;
                vector<edge>::iterator iter1 = v.begin();
                while (iter1 != v.end()) {
                    int v = (*iter1).first;
                    double w = (*iter1).second;
                    (this->*functor)(vertex, v, w);
                    iter1++;
                }
                iter++;
            }
            return true;
        }

        void bellman_ford()
        {
            initialize_sssp();
            for (int i = 0; i <= verts; i++) {
                apply_op_for_each_edge(&Graph::relax);
            }
            apply_op_for_each_edge(&Graph::fnewc);
            print_verts();
        }

        void fw()
		{	
			/* for (int i = 0; i < verts; ++i) {
				vector<edge> j = adj_list[i];
				for_each(j.begin(), j.end(), 
                	[adj_mat, i](const edge &e)
                    {
						int k = e.first;
						double weight = e.second;
						cout<<"Processing "<<i<<" and "<<k<<" weight = "<<weight<<endl;
						adj_mat[i][k] = weight;
                    });
			} */
            for(int i = 1; i<verts+1; i++) {
				for (int j = 1; j <verts+1; j++) {
					cout<<adj_mat[i][j]<<" ";
				}
				cout<<endl;
			}
		}

    public:
        void arbitrage()
        {
            //bellman_ford();
            fw();
        }
        
};

int main()
{
    int verts;
    double weight;
    while(cin>>verts) {
        Graph g(verts);
        for (int i = 1; i <= verts; i++) {
            for (int j = 1; j <= verts; j++) {
                if (i == j) {
                    continue;
                }
                cin>>weight;
                if (weight == 0.0) {
                    g.addEdge(i, j, 0);
                } else {
                    g.addEdge(i, j, weight);
                }
            }
        }
        g.arbitrage();
    }
}
