#include <bits/stdc++.h>

using namespace std;

class Graph
{
	vector <vector<int>> adj_matrix;
	set <int> nodes;
	int row;
	int col;
	struct Node
	{
		int value;
		Node* p;
		Node* next;
		int rank;
	};
	vector <Node*> sets;
	vector <pair <int,int>> sorted_weights;
	vector <vector<int>> weighted_edges;
	vector <vector<int>> kruskal_edge;
	
public:
	Graph(int m, int n, vector<pair<int,int>> p, vector <vector<int>> e)
	{
		row = max(m,n);
		col = row;
		sorted_weights = p;
		weighted_edges = e;
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

	void insert_edge(int u, int v, int w)
	{
		adj_matrix[u][v] = w;
		adj_matrix[v][u] = w;
	}

	void MakeSet(int x)
	{
		Node *n;
		n->value = x;
		n->next = NULL;
		n->p = NULL;
		n->rank = 0;
		sets.push_back(n);
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
		if (x->p != x)
		{
			x->p = FindSet(x->p);
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

	void DisplayGraph()
	{
		for(int i=0;i<=row;i++)
		{
			for(int j=0;j<=col;j++)
			{
				cout<<adj_matrix[i][j]<<" ";
			}
			cout<<endl;
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
			if(FindSet(FindSetNode(weighted_edges[w.second][0])) != FindSet(FindSetNode(weighted_edges[w.second][1])))
			{
				kruskal_edge.push_back(weighted_edges[w.second]);
				Union(FindSet(FindSetNode(weighted_edges[w.second][0])),FindSet(FindSetNode(weighted_edges[w.second][1])));
			}
		}
	}
	
	void DisplayKruskal()
	{
		for(auto w:kruskal_edge)
		{
			cout<<w[0]<<" "<<w[1]<<" "<<w[2]<<endl;
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
		// cout<<1<<endl;
		char *line[15];
		
		line[i] = strtok(inp," ");
		
		while(line[i]!=NULL)
		{
		   line[++i] = strtok(NULL,"\n");
		}
		pair <int, int> p;
		cout<<line[1]<<endl;
		vector <int> edge = {atoi(line[0]),atoi(line[1]),atoi(line[2])};
		// cout<<1<<endl;
		if(col < atoi(line[1]));
		{
			col = atoi(line[1]);
		}
		if(row < atoi(line[0]));
		{
			row = atoi(line[0]);
		}
		cout<<1<<endl;
		p.first = atoi(line[2]);
		p.second = iter;
		weights.push_back(p);
		edges.push_back(edge);
		iter++;

	}
	sort(weights.begin(), weights.end());
	cout<<"col: "<<col<<endl;
	cout<<"row: "<<row<<endl;
	Graph g(row, col, weights,edges);
	// set <int> uni;
	// cout<<weights.size()<<endl;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		// cout<<u<<" "<<v<<endl;
		g.insert_edge(u,v,w);
		// uni.insert(u);
		// uni.insert(v);
		// g.DisplayGraph();
	}
	g.DisplayGraph();
	g.Kruskal();
	g.DisplayKruskal();
	return 0;
}