#include <bits/stdc++.h>
#include <iostream>
using namespace std;



bool findDuplicate(vector<int>& nums)
{

    int n = nums.size();

    sort(nums.begin(),nums.end());

    for(int i=0;i<n-1;i++)
    {
        if(nums[i]==nums[i+1])
        {
            return true;

        }
    }

    return false;  // return false outside loop because it checks for all the elements in array
}


int main()
{
    vector<int>v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(8);
    v.push_back(6);
    findDuplicate(v);

    return 0;
}



class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        int n=nums.size();





    }
};