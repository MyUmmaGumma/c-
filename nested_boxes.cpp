#include <vector>
#include <tuple>
#include <utility>
using namespace std;
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
			int n1 = -1, orig_longest = longest;
			deque<pair<int, int> >deq;
			do {
				vector<int>::iterator result1 = 
					std::find(std::begin(pred), std::end(pred), n1);
				if (result1 == std::end(pred)) {
					if (longest != 0) {
						pred[n1] = INT_MIN;
						deq.pop_back();
						if (deq.empty()) {
							longest = orig_longest;
							n1 = -1;
							continue;
						}
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
			bool first = true;
			while(!deq.empty()) {
				pair<int, int> p = deq.front();
				if (!first) {
					cout<<" ";
				} else {
					first = false;
				}
				cout<<p.first + 1;
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
				print_topo();
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
				print_vint("Predecessor ", sssp_pred);
				print_vint("Shortest path estimate: ", path_estimate);
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


typedef int dim;
typedef vector<dim> box;
typedef vector<box> Boxes;

class NestedBoxes {
    private:
        Graph g;
        Boxes b;
        int _num_boxes;
        int _num_dims;
    public:
        NestedBoxes(Boxes &b1, int num_boxes, int dims) : g(num_boxes) 
        {
            b = b1;
            _num_boxes = num_boxes;
            _num_dims = dims;
            Boxes::iterator it = b.begin();
            while (it != b.end()) {
                box bx = (*it);
                sort(bx.begin(), bx.end()); 
                it++;
            }
        }
        
        void print() 
        {
            Boxes::iterator it = b.begin();
            cout<<"Printing dimensions of "<<_num_boxes<<" boxes"<<endl;
            while (it != b.end()) {
                box bx = (*it);
                box::iterator bit = bx.begin();
                cout<<"Dimensions of box: ";
                for (; bit != bx.end() ; bit++) {
                    cout<<(*bit)<<" ";
                }    
                cout<<endl;
                it++;
            }
        }
    private:

        bool willNest(box b1, box b2)
        {
            for(box::iterator it = b1.begin(), it1 = b2.begin();
                 it != b1.end() && it1 != b2.end(); it++, it1++) {
                if ((*it) > (*it1)) {
                    return false;
                }
            }
            return true;
        }

        void makeGraph()
        {
            int i = 0, j = 0;
            for(Boxes::iterator it = b.begin(); it != b.end(); it++, i++) {
				j = 0;
                for (Boxes::iterator bit = b.begin(); bit != b.end(); bit++, j++) {
					if (i == j)
						continue;
                    if (willNest((*it), (*bit))) {
                        g.addEdge(i, j, -1);
                    }    
                }
            }
        }

    public:
        void getNested()
        {
			makeGraph();
			//g.print();
			g.dag_shortest_paths();
        }
};


int main()
{
	int num_boxes = 0, dimensions = 0;
    int i, j;
	while (cin>>num_boxes>>dimensions) {
        Boxes set_of_box;
        //cout<<" "<<num_boxes<<" of boxes with "<<dimensions<<" of sides"<<endl;
		for (i=0; i < num_boxes; i++) {
            box b;
           // cout<<"Enter box "<<i<<" dimensions:"<<endl;
			while(b.size() < dimensions && cin>>j) {
                b.push_back(j);
		    }
            //Ideally this should be done in the NestedBoxes class - shortcutting :-/
            sort(b.begin(), b.end());
            set_of_box.push_back(b);
		}
        NestedBoxes *nb = new NestedBoxes(set_of_box, num_boxes, dimensions);
        //nb->print();
        nb->getNested();
	}
}
