#include <bits/stdc++.h>

using namespace std;
ofstream f1;

bool sortinrev(const pair<int,int> &a,  const pair<int,int> &b) 
{ 
       return (a.first > b.first); 
} 

class Graph
{
	vector <vector<int>> adj_matrix;
	set <int> nodes;
	int row;
	int col;
    int source;
	vector <vector<int>> weighted_edges;
    vector <pair <int,int>> d_factor;
    vector <pair <int,int>> s_factor;
	
public:
	Graph(int m, int n, vector <vector<int>> e, set <int> uni, int s)
	{
		row = max(m,n);
		col = row;
		weighted_edges = e;
		nodes = uni;
        source = s;
		for(int i=0;i<=row;i++)
		{
			vector<int> v;
			for(int j=0;j<=col;j++)
			{
				v.push_back(-1);
			}
			adj_matrix.push_back(v);
		}
		// adj_matrix.clear();
        createGraph();
	}
	// ~ Graph();
    void createGraph()
    {
        for(auto i:weighted_edges)
        {
            adj_matrix[i[0]][i[1]] = i[2];
        }
    }

    void initialise()
    {
        for(auto x:nodes)
        {
            int distance = 1000000000;
            if(x==source)
            {
                distance = 0;
                // cout<<source<<endl;
            }
            pair <int,int> p;
            p.first = distance;
            p.second = x;
            d_factor.push_back(p);
        }
    }

    void relax(int u, int v)
    {
        int index1 = 0;
        int index2 = 0;
        int iter = 0;
        for(auto p:d_factor)
        {
            if(p.second == u)
            {
                index1 = iter;
            }
            if(p.second == v)
            {
                index2 = iter;
            }
            iter++;
        }
        if(d_factor[index2].first > abs(d_factor[index1].first + adj_matrix[u][v]))
        {
            d_factor[index2].first = abs(d_factor[index1].first + adj_matrix[u][v]);
        }
    }

    void Dijkstras()
    {
        // cout<<source<<endl;
        initialise();
        sort(d_factor.begin(),d_factor.end());
        while(!d_factor.empty())
        {
            int u = d_factor[0].second;
            // cout<<u<<endl;
            for(int i=0;i<=row;i++)
            {
                if(adj_matrix[u][i]>=0)
                {
                    relax(u,i);
                }
            }
            // s_factor.push_back(d_factor[0]);
            sort(d_factor.begin(),d_factor.end(), sortinrev);
            s_factor.push_back(d_factor[d_factor.size()-1]);
            d_factor.pop_back();
            sort(d_factor.begin(),d_factor.end());
        }
    }
    void DisplayDikstras()
    {
        f1.open("dijkstra.txt");
        for(auto p:s_factor)
        {
            if(p.first >= 1000000000 or p.first < 0)
            {
                p.first = -1;
            }
            f1<<p.second<<" "<<p.first<<endl;
        }
    }

};

int main(int argc, char **argv)
{
	ifstream input;
    vector <int> first_node;
    vector <int> second_node;
	input.open(argv[1]);
	char inp[20];
	vector <vector <int>> edges;
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
		vector <int> edge = {atoi(line[0]),atoi(line[1]),atoi(line[2])};
		edges.push_back(edge);
        first_node.push_back(atoi(line[0]));
        second_node.push_back(atoi(line[1]));

	}
	sort(first_node.begin(),first_node.end(),greater <int> ());
    sort(second_node.begin(),second_node.end(),greater <int> ());
    row = first_node[0];
    col = second_node[0];
	// cout<<row<<" "<<col<<endl;
	set <int> uni;
	for(int i=0;i<edges.size();i++)
	{
		int u = edges[i][0];
		int v = edges[i][1];
		int w = edges[i][2];
		uni.insert(u);
		uni.insert(v);
	}
    // cout<<argv[2]<<endl;
	Graph g(row, col,edges,uni,atoi(argv[2]));
    g.Dijkstras();
    g.DisplayDikstras();

	return 0;
}