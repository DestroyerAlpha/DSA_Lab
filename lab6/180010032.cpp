#include <bits/stdc++.h>

using namespace std;

bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

class Graph
{
	vector <vector<int>> matrix;
	int row;
	int col;
public:
	Graph(int m, int n)
	{
		col = n;
		row = m;
		for(int i=0;i<row;i++)
		{
			vector<int> v;
			for(int j=0;j<col;j++)
			{
				v.push_back(0);
			}
			matrix.push_back(v);
		}
		// matrix.clear();
	}
	// ~ Graph();

	void insert(int u, int v)
	{
		matrix[u][v] = 1;
	}
	void DisplayGraph()
	{
		for(int i=0;i<row;i++)
		{
			for(int j=0;j<col;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<endl;
		}
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
	// cout<<col<<endl;
	Graph g(row, col);
	// cout<<edges.size()<<endl;0
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i].first;
		int v = edges[i].second;
		// cout<<u<<" "<<v<<endl;
		g.insert(u,v);
	}
	g.DisplayGraph();
	return 0;
}

