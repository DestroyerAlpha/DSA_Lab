#include<bits/stdc++.h>

using namespace std;

void cuttree(int t,int n,vector <vector<int>> &desc,int x,int y);

vector<vector<int>> a;

int main()
{
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
	vector <vector<int>> desc;
	float max = 0;
	int x_coor;
	int y_coor;
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
		int profit = p*d*h;
		float gross_profit = profit/(x+y+d);
		if(gross_profit>max and (x + y + d) <= t)
		{
			x_coor = x;
			y_coor = y;
			max = gross_profit;
		}

	}
	cuttree(t,n,desc,x_coor,y_coor);

	return 0;
}

void cuttree(int t,int n,vector <vector<int>> &desc,int x,int y)
{
		// for(int i=0;i<n;i++)
		// {
		// 	for(int j =0;j<n;j++)
		// 	{
		// 		cout<<a[j][i]<<" ";
		// 	}
		// 	cout<<endl;
		// }
		vector <int> v1;
		vector <int> v2;
		vector <int> v3;
		vector <int> v4;	
		int tempweight = 0,weight2 = 0;
		int index=0,index1=0;
		int max = 0;
		int flag = 0, in = 0;
		int t1 = 0; //count1 = 1, count2 = 1, count3 = 1, count4 = 1;
		v1.clear();
		v1.push_back(0);
		v2.clear();
		v2.push_back(0);
		v3.clear();
		v3.push_back(0);	
		v4.clear();
		v4.push_back(0);
		
		int i = x;
		int j = y;	
		if(a[i][j])
		{
			index = a[i][j]-1;
			int t_used = desc[index][0]+desc[index][1]+desc[index][3];
			if(t_used<=t)
			{
				in = 1;
				// count1 = 1, count2 = 1, count3 = 1, count4 = 1;
				int break1 = 0,break2 = 0,break3 = 0,break4 = 0;
				int value = desc[index][2]*desc[index][3]*desc[index][5];
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
							t1 = t-t_used;
							flag = 1;
							max = value;
							index1 = a[i][j]-1;
							v1.push_back(k-i);
						}
					}
				}
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
							t1 = t-t_used;
							flag = 2;
							max = value;
							index1 = a[i][j]-1;
							v2.push_back(i-k);
							// weight1 = weight2;
						}
					}
				}
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
							t1 = t-t_used;
							flag = 3;
							max = value;
							index1 = a[i][j]-1;
							v3.push_back(k-j);
						}
					}
						
				}
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
							t1 = t-t_used;
							flag = 4;
							max = value;
							index1 = a[i][j]-1;
							v4.push_back(j-k);
						}
					}	
				}
				weight1 = tempweight;
				height1 = tempheight;
				index = a[i][j]-1;
				x_index = i;
				y_index = j;
				value = desc[index][2]*desc[index][3]*desc[index][5];
			}
		}
			
		
			
		if (in)
		{
			int xl = desc[index1][0] - x;
			int yl = desc[index1][1] - y;
			x = desc[index1][0];
			y = desc[index1][1];
			if(xl>0)
			{
				for(int i=0;i<xl;i++)
				{
					cout<<"move right\n";
				}
			}
			else if(xl<0)
			{
				for(int i=0;i<(-xl);i++)
				{
					cout<<"move left\n";
				}
			}
			if(yl>0)
			{
				for(int i=0;i<yl;i++)
				{
					cout<<"move up\n";
				}
			}
			else if(yl<0)
			{
				for(int i=0;i<(-yl);i++)
				{
					cout<<"move down\n";
				}
			}
			if(flag==3)
			{
				for(int m = 0; m < v3.size(); m++)
				{
					a[desc[index1][0]][desc[index1][1]+v3[m]] = 0;
				}
				cout<<"cut up\n";
			}
			else if(flag==4)
			{
				for(int m = 0; m < v4.size(); m++)
				{
					a[desc[index1][0]][desc[index1][1]- v4[m]] = 0;
				}
				cout<<"cut down\n";
			}
			else if(flag==1)
			{
				for(int m = 0; m < v1.size(); m++)
				{
					a[desc[index1][0] + v1[m]][desc[index1][1]] = 0;
				}
				cout<<"cut right\n";
			}
			else if(flag == 2)
			{
				for(int m = 0; m < v2.size(); m++)
				{
					a[desc[index1][0] - v2[m]][desc[index1][1]] = 0;
				}
				cout<<"cut left\n";
			}
			// for(int i=0;i<n;i++)
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
			int x_coor;
			int y_coor;
			for(int k=0;k<n;k++)
			{
				for(int l=0;l<n;l++)
				{
					if(a[k][l])
					{
						int index = a[k][l] - 1;
						int profit = desc[index][2] + desc[index][3] +desc[index][5];
						float gross_profit = profit/(abs(desc[index][0]-x)+abs(desc[index][1]-y)+desc[index][3]);
						if(gross_profit>max and (abs(desc[index][0]-x)+abs(desc[index][1]-y)+desc[index][3]) <= t1)
						{
							x_coor = desc[index][0];
							y_coor = desc[index][1];
							max = gross_profit;
						}
					}
				}
			}
			cuttree(t1,n,desc,x_coor,y_coor);
		}
}