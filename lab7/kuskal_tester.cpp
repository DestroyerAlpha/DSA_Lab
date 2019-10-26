#include<bits/stdc++.h>
using namespace std;


int main(int argc , char** argv){
	ifstream first , second;
	first.open(argv[1]);	//SIRS FILE
	second.open(argv[2]);	//YOUR FILE
	int f1,f2,f3,s1,s2,s3;
	int line = 1;
	bool flag = true;
	while(first >> f1 >> f2  >> f3 && second >> s1 >> s2 >> s3){
		if(f3 == s3 && ((f1 == s1 && f2 == s2) || (f1 == s2 && f2 == s1 ))){
			++line;
			continue;
		}
		else{
			cout << "Not Matched at line : " << line << endl;
			flag = false;
		}
		++line;
	}
	if(flag){
		cout << "MATCHED !! " << endl;
	}
	return 0; 
}