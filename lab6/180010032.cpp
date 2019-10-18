#include <bits/stdc++.h>

using namespace std;

ofstream f1;
ofstream f2;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

class Graph
{
	vector <vector<int>> adj_matrix;
	set <int> nodes;
	vector <pair<string,int>> bfs_node;
	vector <vector<int>> dfs_node;
	int row;
	int col;
	int t;
public:
	Graph(int m, int n)
	{
		row = max(m,n);
		col = row;
		for(int i=0;i<=row;i++)
		{
			vector<int> v;
			for(int j=0;j<=col;j++)
			{
				v.push_back(0);
			}
			adj_matrix.push_back(v);
		}
		t = 0;
		// adj_matrix.clear();
	}
	// ~ Graph();

	void insert_edge(int u, int v)
	{
		adj_matrix[u][v] = 1;
		nodes.insert(u);
		nodes.insert(v);
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

	void BFS(int s)
	{
		f1.open("sd.txt");
		int start = 0;
		int end = 0;
		vector <int> queue;
		int no_of_nodes = row;
		// cout<<no_of_nodes<<endl;
		for(int i = 0;i<=no_of_nodes;i++)
		{
			pair <string, int> property;
			property.first = "white";
			property.second = -1;
			bfs_node.push_back(property); 
		}
		bfs_node[s].first = "grey";
		bfs_node[s].second = 0;
		queue.push_back(s);
		end += 1;
		while (end!=start)
		{
			int v = queue[start];
			start +=1;
			for(int i = 0;i<=col;i++)
			{
				int u = i;
				if(adj_matrix[v][i]!=0)
				{
					if(bfs_node[u].first=="white")
					{
						bfs_node[u].second = bfs_node[v].second + 1;

						bfs_node[u].first = "grey";
						queue.push_back(u);
						// cout<<u<<endl;
						end += 1;
					}					
				}
			}
			bfs_node[v].first = "black";
		}
		f1.close();
	}

	void bfsfile(int i)
	{
		f1.open("sd.txt",ios_base::app);
		f1<<i<<" "<<bfs_node[i].second;
		f1<<endl;
		f1.close();
	}

	void dfs()
	{
		for(int i = 0;i<=row;i++)
		{
			vector<int> v= {1,0,0};
			dfs_node.push_back(v);
		}
		for(auto x:nodes)
		{
			if(dfs_node[x][0]==1)
				dfs_visit(x);
		}
	
	}

	void dfs_visit(int v)
	{
		// cout<<v<<endl;
		dfs_node[v][0] = 0;
		t++;
		dfs_node[v][1] = t;
		// cout<<v<<" "<<t<<endl;
		for(int i=0;i<=col;i++)
		{
			if(adj_matrix[v][i]==1)
			{
				if(dfs_node[i][0]==1)
				{
					dfs_visit(i);
				}
			}
		}
		t++;
		dfs_node[v][2] = t;
		// cout<<v<<" "<<t<<endl;
		dfs_node[v][0] = -1;
	}
	
	void t_sort()
	{
		f2.open("ts.txt");
		vector <pair <int,int>> p;
		for(auto x:nodes)
		{
			pair <int,int> pa;
			pa.first = dfs_node[x][2];
			pa.second = x;
			p.push_back(pa);
		}
		sort(p.begin(), p.end());
		for(int c=p.size()-1;c>=0;c--)
		{
			if(p[c].second>0)
			{
				f2<<p[c].second<<endl;
			}
		}

		f2.close();
	}
};

int main(int argc, char **argv)
{
	ifstream input;
	input.open(argv[1]);
	char inp[20];
	vector <pair<int,int>> edges;

	while(input.getline(inp,20))
	{
		int i=0;
		
		char *line[15];
		
		line[i] = strtok(inp," ");
		
		while(line[i]!=NULL)
		{
		   line[++i] = strtok(NULL,"\n");
		}
		pair <int, int> p;
		p.first = atoi(line[0]);
		p.second = atoi(line[1]);
		edges.push_back(p);

	}
	sort(edges.begin(), edges.end());
	int row = edges[edges.size()-1].first;
	sort(edges.begin(),edges.end(), sortbysec);
	int col = edges[edges.size()-1].second;
	// cout<<"col: "<<col<<endl;
	// cout<<"row: "<<row<<endl;
	Graph g(row, col);
	set <int> uni;
	// cout<<edges.size()<<endl;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;
		// cout<<u<<" "<<v<<endl;
		g.insert_edge(u,v);
		uni.insert(u);
		uni.insert(v);
		// g.DisplayGraph();
	}
	// g.DisplayGraph();
	g.BFS(atoi(argv[2]));
	sort(edges.begin(), edges.end());
	for(auto i:uni)
	{
		g.bfsfile(i);
	}

	g.dfs();
	g.t_sort();
	return 0;
}