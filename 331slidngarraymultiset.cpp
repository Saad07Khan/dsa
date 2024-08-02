class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {

        int n=nums.size();
        int i=0;
        int ans=0;
        multiset<int,greater<int>>ms;
        for(int j=0;j<n;j++)
        {
            ms.insert(nums[j]);
            int largest=*ms.begin();
            int smallest=*ms.rbegin();
            while(i<=j && abs(largest-smallest)>limit)
            {
                ms.erase(ms.find(nums[i]));
                i++;

             largest=*ms.begin();
             smallest=*ms.rbegin();

            }

            ans=max(ans,j-i+1);
        }
        return ans;
        
    }
};