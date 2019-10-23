#include <bits/stdc++.h>

using namespace std;

ofstream f1;

class Graph
{
	vector <vector<int>> adj_matrix;
	set <int> nodes;
	int row;
	int col;
	struct Node
	{
		int value;
		Node *p;
		Node *next;
		int rank;
	};
	vector <Node *> sets;
	vector <pair <int,int>> sorted_weights;
	vector <vector<int>> weighted_edges;
	vector <vector<int>> kruskal_edge;
	
public:
	Graph(int m, int n, vector<pair<int,int>> p, vector <vector<int>> e, set <int> uni)
	{
		row = max(m,n);
		col = row;
		sorted_weights = p;
		weighted_edges = e;
		nodes = uni;
		for(int i=0;i<=row;i++)
		{
			vector<int> v;
			for(int j=0;j<=col;j++)
			{
				v.push_back(INT_MAX);
			}
			adj_matrix.push_back(v);
		}
		// adj_matrix.clear();
	}
	// ~ Graph();

	void MakeSet(int x)
	{
		// cout<<x<<endl;
		Node *n = new Node;
		
		n->value = x;
		
		n->next = NULL;
		n->p = NULL;
		n->rank = 0;
		
		sets.push_back(n);
		
		// cout<<sets.size()<<endl;
	}

	Node* FindSetNode(int x)
	{
		
		for(auto n:sets)
		{
			
			if(n->value==x)
			{
				
				return n;
				
			}
		}
		
		return NULL;
	}

	Node* FindSet(Node *x)
	{
		
		while (x->p != NULL)
		{
			x = x->p;
		}
		return x;
	}

	void Union(Node *x, Node *y)
	{
		Link(FindSet(x),FindSet(y));
	}

	void Link(Node *s, Node *t)
	{
		if(s->rank>t->rank)
		{
			t->p = s;
		}
		else
		{
			s->p = t;
			if (s->rank==t->rank)
			{
				t->rank += 1;
			}
		}
	}


	void Kruskal()
	{
		for(auto x:nodes)
		{
			MakeSet(x);
		}
		
		for(auto w:sorted_weights)
		{
			
			int u = weighted_edges[w.second][0];
			int v = weighted_edges[w.second][1];
			if(FindSet(FindSetNode(u)) != FindSet(FindSetNode(v)))
			{
				
				kruskal_edge.push_back(weighted_edges[w.second]);
				Union(FindSet(FindSetNode(u)),FindSet(FindSetNode(v)));
			}
			
		}
	}
	
	void DisplayKruskal()
	{
		f1.open("mst.txt");
		for(auto w:kruskal_edge)
		{
			f1<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
		}
	}

};

int main(int argc, char **argv)
{
	ifstream input;
	input.open(argv[1]);
	char inp[20];
	vector <pair<int,int>> weights;
	vector <vector <int>> edges;
	int iter = 0;
	int row = 0,col = 0;
	while(input.getline(inp,20))
	{
		int i=0;
		
		char *line[15];
		
		line[i] = strtok(inp," ");
		
		while(line[i]!=NULL)
		{
		   line[++i] = strtok(NULL," \n");
		}
		pair <int, int> p;
		// cout<<line[2]<<endl;
		vector <int> edge = {atoi(line[0]),atoi(line[1]),atoi(line[2])};
		
		if(col < atoi(line[1]));
		{
			col = atoi(line[1]);
			// cout<<col<<endl;
		}
		if(row < atoi(line[0]));
		{
			row = atoi(line[0]);
		}
		
		p.first = atoi(line[2]);
		p.second = iter;
		weights.push_back(p);
		edges.push_back(edge);
		iter++;

	}
	sort(weights.begin(), weights.end());
	// cout<<"col: "<<col<<endl;
	// cout<<"row: "<<row<<endl;
	
	
	set <int> uni;
	// cout<<weights.size()<<endl;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		// cout<<u<<" "<<v<<" "<<w<<endl;
		// g.insert_edge(u,v,w);
		uni.insert(u);
		uni.insert(v);
		// g.DisplayGraph();
	}
	// for(auto c:uni)
	// {
	// 	cout<<c<<endl;
	// }
	Graph g(row, col, weights,edges,uni);
	
	// g.DisplayGraph();
	g.Kruskal();
	
	g.DisplayKruskal();
	return 0;
}