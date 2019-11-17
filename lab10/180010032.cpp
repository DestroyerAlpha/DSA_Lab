#include <bits/stdc++.h>

using namespace std;

pair <int, pair<int,int>> ExtendedGCD(int a, int b)
{
    // pair <int, pair<int,int>> triplet;
    if(b==0)
    {
        pair<int,int> p;
        p.first = 1;
        p.second = 0;
        pair <int, pair<int,int>> t;
        t.first = a;
        t.second = p;
        return t;
    }
    pair <int, pair<int,int>> t = ExtendedGCD(b,a%b);
    pair <int, pair<int,int>> ret;
    ret.first = t.first;
    ret.second.first = t.second.second;
    ret.second.second = t.second.first - (a/b)*t.second.second;
    return ret;
}

int main(int argc, char **argv)
{
    int b = atoi(argv[2]);
    int a = atoi(argv[1]);
    pair<int,pair<int,int>> p = ExtendedGCD(a,b);
    cout<<p.first<<" "<<p.second.first<<" "<<p.second.second<<endl;
    return 0;
}