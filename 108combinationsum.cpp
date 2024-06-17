class Solution {
public:

void combosum(int i,int target,vector<int>& candidates,vector<vector<int>> &ans,vector<int>&temp)
{
    if(i==candidates.size())
    {
        if(target==0)
        {
            ans.push_back(temp);
        }
        return;
    }

    if(candidates[i]<=target)
    {
        temp.push_back(candidates[i]);
        combosum(i,target-candidates[i],candidates,ans,temp);
        temp.pop_back();
    }
    combosum(i+1,target,candidates,ans,temp);

}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>temp;
        combosum(0,target,candidates,ans,temp);
        return ans;

        
    }
};