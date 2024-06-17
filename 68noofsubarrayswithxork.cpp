
#include <bits/stdc++.h>
int subarraysWithSumK(vector < int > a, int b) {

    
    int count=0;
    int xr=0;
    map<int,int>mp;
    mp[0]=1;
    int n1=a.size();
    
    for(int i=0;i<n1;i++)
    {

       xr = xr ^ a[i];


        int x = xr ^ b;
        if (mp.find(x) != mp.end()) {
          count += mp[x];
        }

        mp[xr]++;
     }
    return count;
   
}