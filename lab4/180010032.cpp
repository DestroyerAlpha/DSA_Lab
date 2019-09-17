#include <bits/stdc++.h>

using namespace std;

ofstream f1;
ofstream f2;

vector <int> A;
vector <int> B;

void merge(int p, int q, int r)
{
	int L[q-p+2],R[r-q+1];
	for(int i=0;i<=q-p;i++)
	{
		L[i] = A[p+i];
	}
	for(int i=0;i<=r-q-1;i++)
	{
		R[i] = A[q+i+1];
	}
	L[q-p+1] = INT_MAX;
	R[r-q] = INT_MAX;
	int a=0,b=0;
	for(int i = p;i<=r;i++)
	{
		if(L[a]<R[b])
		{
			A[i] = L[a];
			a += 1;
		}
		else
		{
			A[i] = R[b];
			b += 1;
		}
	}

}

void mergesort(int p, int r)
{
	if (p<r)
	{
		int q = (p+r)/2;

		mergesort(p,q);
		mergesort(q+1,r);
		merge(p,q,r);
	}
}

int partition(int p, int r)
{
	int a = B[r];
	int i = p;
	for (int j = p; j <= r-1; ++j)
	{
		if (B[j] < a)
		{
			
			swap(B[i],B[j]);
			i+=1;
			
		}
	}
	swap(B[i],B[r]);
	return i;
}

void quicksort(int p, int r)
{
	if (p<r)
	{
		int q = partition(p,r);
		quicksort(p,q-1);
		quicksort(q+1,r);
	}
}

int main(int argc, char **argv)
{
	ifstream input;
	f1.open("mergesort.txt");
	f2.open("quicksort.txt");
	input.open(argv[1]);
	char inp[10];
	while(input.getline(inp,10))
	{
		int number = atoi(inp);
		A.push_back(number);
		B.push_back(number);
	}
	mergesort(0,A.size()-1);
	quicksort(0,B.size()-1);
	f1<<A[0];
	f2<<B[0];
	for(int i=1;i<A.size();i++)
	{
		f1<<endl<<A[i];
		f2<<endl<<B[i];
	}
	f1.close();
	f2.close();
	return 0;
}