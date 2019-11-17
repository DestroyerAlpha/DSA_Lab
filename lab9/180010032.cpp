#include <bits/stdc++.h>

using namespace std;

ofstream file;

class H
{
    vector <list <string>> table;
    int mod;
    public:
        H(int m)
        {
            mod = m;
            for(int i=0;i<m;i++)
            {
                list <string> l;
                table.push_back(l);
            }
        }

        int hash(string s)
        {
            int sum = 0;
            for(auto c:s)
            {
                sum += c - '0';
            }
            return sum%mod;
        }

        bool ana(string s1, string s2)
        {
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1==s2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        void insert(string s)
        {
            int v = hash(s);
            table[v].push_front(s);
        }

        void search(string s)
        {
            vector <string> str;
            int v = hash(s);
            list <string> l = table[v];
            int flag = 0;
            for(auto i:l)
            {
                if(ana(i,s))
                {
                    file<<i<<" ";
                }
            }
            file<<endl;
        }
};

int main(int argc, char **argv)
{
    ifstream f1;
    ifstream f2;
    file.open("anagrams.txt");
    f1.open(argv[1]);
    f2.open(argv[3]);
    int m = atoi(argv[2]);
    H test(m);
    string inp;
    while(f1>>inp)
    {
        // string s = to_string(inp);
        test.insert(inp);
    }
    while(f2>>inp)
    {
        // string s = to_string(inp);
        test.search(inp);
    }
    return 0;

}