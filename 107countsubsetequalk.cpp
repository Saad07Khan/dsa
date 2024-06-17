int count(int i,int s,int k, vector<int>& nums,vector<vector<int>>&ans,vector<int>& temp)
{
    if(i=nums.size())
    {
        if(s==k)
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    temp.push_back(nums[i]);
    s+=nums[i];
    int r = count(i+1,s,k,nums,ans,temp);
    
    s-=nums[i];
    temp.pop_back();
    int l= count(i+1,s,k,nums,ans,temp); 
    return l+r;
}