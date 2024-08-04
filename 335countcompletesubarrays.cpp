class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        set<int>st;
        for(int k=0;k<n;k++)
        {
            st.insert(nums[k]);
        }
              
        for(int j=0;j<n;j++)
        {
            set<int>dup;
            for(int i=j;i<n;i++)
            {
                dup.insert(nums[i]);
                if(st.size()==dup.size())
                {
                    count++;
                }
            }
        }
        return count;
        
    }
};