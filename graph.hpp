#include <iostream>
#include <vector>
#include <list>
#include <tuple>
#include <algorithm>
#include <deque>
using namespace std;
#include <limits.h>

#define NIL -1

class Graph 
{
    private:
        int verts;
        int **adj_mat;
		int *predecessor;
		list<int> topo;		

		enum Color {
			WHITE,
			GRAY,
			BLACK
		};

		void DFS_VISIT(int vertex, int time, Color *color, int *stimes, int *etimes)
		{
			color[vertex] = GRAY;
			time++;
			stimes[vertex] = time;
			for(int i = 0; i < verts; ++i) {
				if (adj_mat[vertex][i] != 0) {
					if (color[i] == WHITE) {
						predecessor[i] = vertex;
						DFS_VISIT(i, time, color, stimes, etimes);
					}
				}
			}
			color[vertex] = BLACK;
			etimes[vertex] = ++time;
			topo.push_front(vertex);
		}

    public:
        Graph(int _v) : verts(_v) 
        {
            adj_mat = new int*[verts];
            for (int i = 0; i < verts; i++) {
                adj_mat[i] = new int [verts];
            } 
            for (int i = 0; i < verts; i++) {
            	for (int j = 0; j < verts; j++) {
	                adj_mat[i][j] = 0;
				}
            } 
        }
        
        void addEdge(int x, int y, int w)
        {
            adj_mat[x][y] = w;
        }

        list<int>& get_topological_order()
        {
            return topo;
        }

		void print()
		{
            for (int i = 0; i < verts; i++) {
            	for (int j = 0; j < verts; j++) {
	                cout<<adj_mat[i][j]<<"\t";
				}
				cout <<endl;
            } 
		}

		void DFS()
		{
			Color *color = new Color[verts];
			predecessor = new int[verts];
			int *start_times = new int[verts];
			int *end_times = new int[verts];
			for (int i = 0; i< verts; i++) {
				color[i] = WHITE;
				predecessor[i] = -1;
			}
			int time = 0;
			for (int i = 0; i< verts; i++) {
				if (color[i] == WHITE) {
					//cout<<"Visiting "<<i<<endl;
					DFS_VISIT(i, time, color, start_times, end_times);
				}
			}
			delete []start_times;
			delete []end_times;
			delete []color;
			delete []predecessor;
		}

		void topological_order()
		{
			DFS();
		}

        // Initiailizing the state for the SSSP for DAG for longest path
        // The shortest path init will have the shortest path estimate as INT_MAX
        typedef vector<int> vint;
        void initialize_single_source_rev(int s, vint &predecessor, vint &shortest_path_estimate)
        {
            for (int i = 0; i < verts; i++) {
                if (i != s) {
                    shortest_path_estimate.push_back(INT_MAX);
                    predecessor.push_back(NIL);
                } else {
                    shortest_path_estimate.push_back(0);
                    predecessor.push_back(NIL);
                }
            }
        }

        //get adjacent vertices to the input vertex
        void getAdjVertices(int vertex, vint &adj)
        {
            int *adj_vertices = adj_mat[vertex];
            for (int i = 0; i < verts; i++) {
                if (adj_vertices[i] != 0) {
                    adj.push_back(i);
                }
            }
        }

		void reverse_relax(int u, int vdash, vint &d, vint &pred)
		{
			if (d[vdash] > d[u] + adj_mat[u][vdash]) {
				d[vdash] = d[u] + adj_mat[u][vdash];
				pred[vdash] = u;
			}
		}

		void print_vint(const char *str, vint &v1)
		{
			cout<<"Printing "<<str<<endl;
			vint::iterator it = v1.begin();
			while (it != v1.end()) {
				cout<<*it<<" ";
				it++;
			}
			cout<<endl;
		}

		void get_sequence(vector<int> &pred, int longest)
		{
			int n1 = -1;
			deque<pair<int, int> >deq;
			do {
				vector<int>::iterator result1 = 
					std::find(std::begin(pred), std::end(pred), n1);
				if (result1 == std::end(pred)) {
					if (longest != 0) {
						pred[n1] = INT_MIN;
						deq.pop_back();
						pair<int,int> p = deq.back();
						longest = p.second;
						n1 = p.first;
						continue;
					}
				}
				n1 = result1 - pred.begin();
				longest--;
				deq.push_back(make_pair(n1, longest));
			} while (longest != 0);
			while(!deq.empty()) {
				pair<int, int> p = deq.front();
				cout<<p.first + 1<<" ";
				deq.pop_front();
			}
			cout<<endl;
		} 

        public:
            void dag_shortest_paths()
            {
                DFS();
				vint sssp_pred;
				vint path_estimate;
                list<int> l = get_topological_order();
                list<int>::iterator it = l.begin();
				bool init = false;
                for (; it != l.end(); ++it) {
					vint adj;
      				getAdjVertices(*it, adj);
					if (init == false) {
                		initialize_single_source_rev(*it, sssp_pred, path_estimate);
						init = true;
					}
	
    				vector<int>::iterator adj_it = adj.begin();
					for(; adj_it != adj.end(); ++adj_it) {
    					//cout<<"Reverse relaxing "<<*it<<" and "<<*adj_it<<endl;
						reverse_relax(*it, *adj_it, path_estimate, sssp_pred);
					}
                }
				//print_vint("Predecessor ", sssp_pred);
				//print_vint("Shortest path estimate: ", path_estimate);
				int longest = (*min_element(path_estimate.begin(), path_estimate.end()) * -1) +1;
				cout<<longest<<endl;
				get_sequence(sssp_pred, longest);
            }

		void print_topo()
		{
			list<int>::iterator it = topo.begin();
			cout<<"Topological sort yields: ";
			for(; it != topo.end(); ++it) {
				cout<<(*it)<<"\t";
			}
			cout<<endl;
		}
};

/*
int main()
{
    Graph g(9);
    g.addEdge(0,1,-1);
    g.addEdge(0,6,-1);
    g.addEdge(1,2,-1);
    g.addEdge(1,6,-1);
    g.addEdge(2,5,-1);
    g.addEdge(3,2,-1);
    g.addEdge(3,4,-1);
    g.addEdge(4,5,-1);
    g.addEdge(7,6,-1);
	g.print();
	g.DFS();
	g.print_topo();
    vector<int> adj;
    g.getAdjVertices(3, adj);
    vector<int>::iterator it = adj.begin();
    cout<<"Vertices adjacent to 3 are: ";
	for(; it != adj.end(); ++it) {
		cout<<(*it)<<"\t";
	}
	cout<<endl;
	g.dag_shortest_paths(0);

}
*/
