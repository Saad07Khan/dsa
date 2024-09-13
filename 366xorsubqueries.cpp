class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        
        //xor from arr[left]to arr[right]
        vector<int>ans;
        for(int i=0;i<queries.size();i++)
        {
            int left= queries[i][0];
            int right = queries[i][1];

            int xorans=arr[left];

            for(int i=left+1;i<=right;i++)
            {
                xorans=xorans^arr[i];
            }

            ans.push_back(xorans);
        }

        return ans;
    }
};