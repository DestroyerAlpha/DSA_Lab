#include<bits/stdc++.h>

using namespace std;

vector<int> v;

void radixSort(int d, int counter)
{
	// cout<<d<<" "<<counter<<endl;
 	int n = d - counter;
 	if(n<=d)
 	{
	 	vector <int> count;
	 	for(int i=0;i<10;i++)
	 	{
	 		for(int j=0;j<v.size();j++)
	 		{
	 			// cout<<v[j]<<endl;
	 			int red = v[j]/pow(10,(n-1));
	 			// cout<<red<<endl;
	 			// int power = 10;
	 			if((red%10)==i)
	 			{
	 				count.push_back(v[j]);
	 			}
	 		}

	 	}
	 	v = count;
	 	counter--;
	 	radixSort(d,counter);
 	}
 	else
 	{
 		return;
 	}
 	// cout<<"1"<<endl;
}

int main(int argc, char **argv)
{
	int d = atoi(argv[2]);
	ifstream file;
	file.open(argv[1]);
	ofstream output;
	output.open("radix.txt");
	char input[d+1];
	// cout<<"1"<<endl;
	while(file.getline(input,10))
	{
		// cout<<"2"<<endl;
		int number = atoi(input);
		v.push_back(number);
		// cout<<number<<endl;
	}
	// cout<<sizeof(v)<<endl;
	// cout<<"4"<<endl;
	radixSort(d,d-1);
	// cout<<"3"<<endl;
	output<<v[0];
	for(int i=1;i<v.size();i++)
	{
		// cout<<"1"<<endl;
		output<<endl<<v[i];
	}
	file.close();
	output.close();
	return 0;

}