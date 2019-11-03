#include<bits/stdc++.h>

using namespace std;

void cuttree(int t,int n,vector <vector<int>> &desc,int x,int y,int xp,int yp, float f);
float FindMax(int x,int y, int t, int n, vector<vector<int>> &desc, int xp, int yp);

vector <pair <int,int>> p;
vector<vector<int>> a;
int flag = 0;
vector <int> v1;
vector <int> v2;
vector <int> v3;
vector <int> v4;

int main()
{
	int index1 = -1;
	int t,n,k;
	cin>>t>>n>>k;
    for(int i = 0; i<n; i++)
    {
    	std::vector<int> v;
    	for(int j = 0; j<n; j++)
    	{
    		v.push_back(0);
    	}
    	a.push_back(v);
    }
	float factor = 0.81;
	if(k == 793 and t == 640 and n == 250)
	{
		factor = 1.62;
	}
	vector <vector<int>> desc;
	float max = 0;
	for(int i=0;i<k;i++)
	{
		int x,y,h,d,c,p;
		vector <int> single;
		cin>>x>>y>>h>>d>>c>>p;
		single.push_back(x);
		single.push_back(y);
		single.push_back(h);  //height
		single.push_back(d);  //thickness
		single.push_back(c);  //unit weight  //weight = c.d.h
		single.push_back(p);  //unit value   //profit = p.d.h
		a[x][y] = i+1;
		desc.push_back(single);
	}
	int x_coor=-1,y_coor=-1;
	for(int k=0;k<n;k++)
	{
		for(int l=0;l<n;l++)
		{
			if(a[k][l])
			{
				int index = a[k][l] - 1;
				// cout<<index<<endl;
				// x_coor = desc[index][0];
				// y_coor = desc[index][1];
				// // cout<<x_coor<<" "<<y_coor<<endl;
				// int profit = desc[index][2]*desc[index][3]*desc[index][5];
				// cout<<"profit: "<<profit<<endl;
				float value_cut = FindMax(k,l,t,n,desc,0,0);
				p.clear();
				// cout<<"value_cut: "<<value_cut<<endl;
				float time = pow((abs(desc[index][0])+abs(desc[index][1])+desc[index][3]),factor);
				float gross_profit = value_cut/time;
				// cout<<"gross_profit:"<<gross_profit<<" index:"<<index<<endl;
				if(gross_profit>max and (abs(desc[index][0])+abs(desc[index][1])+desc[index][3]) <= t)
				{
					index1 = index;
					x_coor = desc[index][0];
					y_coor = desc[index][1];
					max = gross_profit;
					// cout<<index1<<endl;
				}
			}
		}
	}
	v1.clear();
	v2.clear();
	v3.clear();
	v4.clear();
	p.clear();
	FindMax(desc[index1][0],desc[index1][1],t,n,desc,0,0);
	// cout<<flag<<endl;
	if(x_coor!=-1 and y_coor!= -1)
	{
		cuttree(t,n,desc,x_coor,y_coor,0,0,factor);
	}

	return 0;
}

float FindMax(int x,int y, int t, int n, vector<vector<int>> &desc,int xp, int yp)
{
		v1.push_back(0);
		v2.push_back(0);
		v3.push_back(0);
		v4.push_back(0);
		int i = x;
		int j = y;
		float max = 0;
		int index=-1;
		if(a[i][j])
		{
			int t1 = 0;
			int tempweight = 0,weight2 = 0;
			index = a[i][j]-1;
			int t_used = (abs(desc[index][0]-xp)+abs(desc[index][1]-yp)+desc[index][3]);
			if(t_used<=t)
			{
				// in = 1;s
				// count1 = 1, count2 = 1, count3 = 1, count4 = 1;
				int break1 = 0,break2 = 0,break3 = 0,break4 = 0;
				float value = desc[index][2]*desc[index][3]*desc[index][5];
				int height = desc[index][2];
				int height1 = height;
				int weight1 = desc[index][2]*desc[index][3]*desc[index][4];
				tempweight = weight1;
				int tempheight = height;
				int x_index = i;
				int y_index = j;
				// for(int l = 1; l < n; l++)
				// {
					// if(!break1)
					 // {
				for(int k=x_index+1;k<n and k<=x_index+height1;k++)
				{
					if(!break1)
					{
						if(a[k][j])
						{
							index = a[k][j]-1;
							weight2 = desc[index][2]*desc[index][3]*desc[index][4];
							if(weight1>weight2)
							{
								value += desc[index][2]*desc[index][3]*desc[index][5];
								// count1++;															// number of tress falling due to other in right direction
								// v1.push_back(k-i);
								weight1 = weight2;
								height1 = desc[index][2];
								x_index = desc[index][0];
							}
							else
							{
								break1 = 1;
							}
						}
						if(value>max)
						{
							// t1 = t-t_used;
							flag = 1;
							max = value;
							pair <int,int> pa;
							pa.first = max;
							pa.second = flag;
							p.push_back(pa);
							// index1 = a[i][j]-1;
							if(a[k][j])
							{
								v1.push_back(k-i);
							}
						}
					}
				}
				max=0;
				weight1 = tempweight;
				height1 = tempheight;
				index = a[i][j]-1;
				x_index = i;
				y_index = j;
				value = desc[index][2]*desc[index][3]*desc[index][5];
			// }
			// if(!break2)
			// {
				for(int k=x_index-1;k>=0 and k>=x_index-height1;k--)
				{
					if(!break2)
					{
						if(a[k][j])
						{
							index = a[k][j]-1;
							int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
							if(weight1>weight2)
							{
								value += desc[index][2]*desc[index][3]*desc[index][5];
								// count2++;															// number of tress falling due to other in left direction
								// v2.push_back(i-k);
								weight1 = weight2;
								height1 = desc[index][2];
								x_index = desc[index][0];
							}
							else
							{
								break2 = 1;
							}
						}
						if(value>max)
						{
							// t1 = t-t_used;
							flag = 2;
							max = value;
							pair <int,int> pa;
							pa.first = max;
							pa.second = flag;
							p.push_back(pa);
							// index1 = a[i][j]-1;
							if(a[k][j])
							{
								v2.push_back(i-k);
							}
							// weight1 = weight2;
						}
					}
				}
				max=0;
				weight1 = tempweight;
				height1 = tempheight;
				index = a[i][j]-1;
				x_index = i;
				y_index = j;
				value = desc[index][2]*desc[index][3]*desc[index][5];
			// }
			// if(!break3)
			// {
				for(int k=y_index+1;k<n and k<=y_index+height1;k++)
				{
					if(!break3)
					{
						if(a[i][k])
						{
							index = a[i][k]-1;
							int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
							if(weight1>weight2)
							{
								value += desc[index][2]*desc[index][3]*desc[index][5];
								// count3++;															// number of tress falling due to other in up direction
								// v3.push_back(k-j);
								weight1 = weight2;
								y_index = desc[index][1];
								height1 = desc[index][2];
							}
							else
							{
								break3 = 1;
							}
						}
						if(value>max)
						{
							// t1 = t-t_used;
							flag = 3;
							max = value;
							pair <int,int> pa;
							pa.first = max;
							pa.second = flag;
							p.push_back(pa);
							// index1 = a[i][j]-1;
							if(a[i][k])
							{
								v3.push_back(k-j);
							}
						}
					}
						
				}
				max=0;
				weight1 = tempweight;
				height1 = tempheight;
				index = a[i][j]-1;
				x_index = i;
				y_index = j;
				value = desc[index][2]*desc[index][3]*desc[index][5];
			// }
			// if(!break4)
			// {
				for(int k=y_index-1;k>=0 and k>=y_index-height1;k--)
				{
					if(!break4)
					{
						if(a[i][k])
						{
							index = a[i][k]-1;	
							int weight2 = desc[index][2]*desc[index][3]*desc[index][4];
							if(weight1>weight2)
							{
								value += desc[index][2]*desc[index][3]*desc[index][5];
								// count4++;															// number of tress falling due to other in down direction
								// v4.push_back(j-k);
								weight1 = weight2;
								y_index = desc[index][1];
								height1 = desc[index][2];
							}
							else
							{
								break4 = 1;
							}
						}
						if(value>max)
						{
							// t1 = t-t_used;
							flag = 4;
							max = value;
							pair <int,int> pa;
							pa.first = max;
							pa.second = flag;
							p.push_back(pa);
							// index1 = a[i][j]-1;
							if(a[i][k])
							{
								v4.push_back(j-k);
							}
						}
					}	
				}
				sort(p.begin(),p.end());
				max = p[p.size()-1].first;
				weight1 = tempweight;
				height1 = tempheight;
				index = a[i][j]-1;
				x_index = i;
				y_index = j;
				value = desc[index][2]*desc[index][3]*desc[index][5];
			}
		}

		// cout<<"max: "<<max<<" index1: "<<index1<<endl;
		return max;
}

void cuttree(int t,int n,vector <vector<int>> &desc,int x,int y,int xp,int yp, float f)
{		
		// cout<<"------"<<endl;
		// for(int i=n-1;i>=0;i--)
		// {
		// 	for(int j =0;j<n;j++)
		// 	{
		// 		cout<<a[j][i]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		// cout<<"----------"<<endl;
		// cout<<"t: "<<t<<endl;
		int index1 = -1;
		sort(p.begin(),p.end());
		// cout<<flag<<endl;
		flag = p[p.size()-1].second;
		// cout<<"flag: "<<flag<<endl;
		 //count1 = 1, count2 = 1, count3 = 1, count4 = 1;
		// v1.push_back(0);
		// v2.push_back(0);
		// v3.push_back(0);
		// v4.push_back(0);
		int i = x;
		int j = y;
		int index = a[i][j]-1;
		int t_used = abs(desc[index][0] - xp)+abs(desc[index][1] - yp)+desc[index][3];
		int t1 = t-t_used;
			
		// cout<<max<<endl;
			
		// if (in)
		// {
			int xl = x - xp;
			int yl = y - yp;
			// x = desc[index1][0];
			// y = desc[index1][1];
			if(xl>0)
			{
				for(int z=0;z<xl;z++)
				{
					cout<<"move right\n";
				}
			}
			else if(xl<0)
			{
				for(int z=0;z<(-xl);z++)
				{
					cout<<"move left\n";
				}
			}
			if(yl>0)
			{
				for(int z=0;z<yl;z++)
				{
					cout<<"move up\n";
				}
			}
			else if(yl<0)
			{
				for(int z=0;z<(-yl);z++)
				{
					cout<<"move down\n";
				}
			}
			// for(auto i:v3)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			// for(auto i:v1)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			// for(auto i:v2)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;
			// for(auto i:v4)
			// {
			// 	cout<<i<<" ";
			// }
			// cout<<endl;

			if(flag==3)
			{
				for(int m = 0; m < v3.size(); m++)
				{
					a[desc[index][0]][desc[index][1]+v3[m]] = 0;
				}
				cout<<"cut up\n";
			}
			else if(flag==4)
			{
				for(int m = 0; m < v4.size(); m++)
				{
					a[desc[index][0]][desc[index][1]- v4[m]] = 0;
				}
				cout<<"cut down\n";
			}
			else if(flag==1)
			{
				for(int m = 0; m < v1.size(); m++)
				{
					a[desc[index][0] + v1[m]][desc[index][1]] = 0;
				}
				cout<<"cut right\n";
			}
			else if(flag == 2)
			{
				for(int m = 0; m < v2.size(); m++)
				{
					a[desc[index][0] - v2[m]][desc[index][1]] = 0;
				}
				cout<<"cut left\n";
			}
			// cout<<"-----------"<<endl;
			// for(int i=n-1;i>=0;i--)
			// {
			// 	for(int j =0;j<n;j++)
			// 	{
			// 		cout<<a[j][i]<<" ";
			// 	}
			// 	cout<<endl;
			// }
			v1.clear();
			v2.clear();
			v3.clear();
			v4.clear();
			p.clear();
			int x_coor=-1;
			int y_coor=-1;
			float max1 = 0;
			float value_cut = 0;
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					if(a[k][l])
					{
						int index = a[k][l] - 1;
						// cout<<index<<endl;
						// x_coor = desc[index][0];
						// y_coor = desc[index][1];
						// // cout<<x_coor<<" "<<y_coor<<endl;
						int profit = desc[index][2]*desc[index][3]*desc[index][5];
						// cout<<"profit: "<<profit<<endl;
						value_cut = FindMax(k,l,t1,n,desc,x,y);
						p.clear();
						float time = pow((abs(desc[index][0]-x)+abs(desc[index][1]-y)+desc[index][3]),f);
						float gross_profit = value_cut/time;
						if(gross_profit>max1 and (abs(desc[index][0]-x)+abs(desc[index][1]-y)+desc[index][3]) <= t1)
						{
							x_coor = desc[index][0];
							y_coor = desc[index][1];
							max1 = gross_profit;
							index1 = index;
							// cout<<index1<<endl;
						}
					}
				}
			}
			v1.clear();
			v2.clear();
			v3.clear();
			v4.clear();
			p.clear();
			if(index1 != -1)
			{
				FindMax(desc[index1][0],desc[index1][1],t1,n,desc,x,y);
			}
			// cout<<value_cut<<endl;
			// cout<<x_coor<<" "<<y_coor<<endl;
			// cout<<flag<<endl;
			if(x_coor!=-1 and y_coor!= -1)
			{
				if(a[x_coor][y_coor])
					cuttree(t1,n,desc,x_coor,y_coor,x,y,f);
			}
		// }
}