class Solution {
public:
void findcombi(int ind, int target,vector<int>& candidates,vector<int>&temp,vector<vector<int>>&ans)
{
    if(target==0)
    {
        ans.push_back(temp);
        return;
    }
    for(int i=ind;i<candidates.size();i++)
    {
        if(i>ind && candidates[i]==candidates[i-1])continue;
        if(candidates[i] > target) break;
        temp.push_back(candidates[i]);
        findcombi(i+1,target-candidates[i],candidates,temp,ans);
        temp.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        findcombi(0,target,candidates,temp,ans);
        return ans;

        
    }
};
