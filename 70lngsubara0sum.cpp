#include <vector>
#include <bits/stdc++.h>
int getLongestZeropresumSubarrayLength(vector<int> &arr)
{

    map<int, int> mp;
    int presum = 0;
    int maxi = 0;
    int length;
    for (int i = 0; i < arr.size(); i++)
    {
        presum += arr[i];
        if (presum == 0)
        {
            maxi = i + 1;
        }
        else
        {
            if (mp.find(presum) != mp.end())
            {
                maxi = max(maxi, i - mp[presum]);
            }
            else
            {
                mp[presum] = i;
            }
        }
    }
    return maxi;
}