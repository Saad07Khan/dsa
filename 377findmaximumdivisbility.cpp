class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        int n=nums.size();
        int d=divisors.size();
        vector<int>divisibility;
        for(int i=0;i<d;i++)
        {
            int count=0;
            for(int j=0;j<n;j++)
            {
                if(nums[j]%divisors[i]==0)
                {
                    count++;
                }
            }
            divisibility.push_back(count);
        }

       int maxi= *std::max_element(divisibility.begin(),divisibility.end());
       int cnt=0;
       int mini=INT_MAX;
       for(int i=0;i<divisibility.size();i++)
       {
        if(maxi==divisibility[i])
        {
            mini=min(mini,divisors[i]);

        }
       }

       for(int i=0;i<divisors.size();i++)
       {
        if(divisors[i]==mini)
        {
            return divisors[i];
        }
       }

       return -1;

       

    }
};