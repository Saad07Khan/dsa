#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;


int main()
{
    vector<int>v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(8);
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    //or
    cout<<"\n";
    for(auto a:v)cout<<a<<endl;
}