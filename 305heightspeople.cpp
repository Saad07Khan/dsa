class Solution {
public:


    static bool cmp(pair<string,int>a, pair<string,int>b)
    {
        return a.second>b.second;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n=heights.size();
        vector<pair<string,int>>p;
        for(int i=0;i<n;i++)
        {
            pair<string,int>v=make_pair(names[i],heights[i]);
            p.push_back(v);
        }
        
        sort(p.begin(),p.end(),cmp);
        vector<string>ans;
        for(auto it: p)
        {
            ans.push_back(it.first);
        }

        return ans;

        
    }
};