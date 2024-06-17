class Solution {
public:

void solve(vector<int>&nums,int sum,int &ans,int index)
{
    if(index==nums.size())
    {
        ans+=sum;
        return;
    }

    solve(nums,sum^nums[index],ans,index+1);
    solve(nums,sum,ans,index+1);

}
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        solve(nums,0,ans,0);
        return ans;

    }
};

