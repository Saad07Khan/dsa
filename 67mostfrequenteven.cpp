class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
    
        int freq=0;
        int ele=-1;

        map<int,int>mp;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]%2==0)
            mp[nums[i]]++;
        }

        for(auto a : mp)
        {
            if(a.second>freq) // in {1,2,2,4,4,0} 4 freq is also 2 but this condition makes sure only 2 is printed do dry run to understand
            {
                freq=a.second;
                ele=a.first;
            }
        }
        return ele;



      
        
        
    }
};


