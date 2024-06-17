class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       vector<vector<int>>ans; // since we need to return a list of list
       sort(nums.begin(),nums.end());
       int n=nums.size();
       for(int i=0;i<n;i++)
       {
           if(i!=0 && nums[i]==nums[i-1]) continue; // continue to next iteration

           int j=i+1;
           int k=n-1;

           while(j<k)
           {
              int sum=nums[i]+nums[j]+nums[k];
               if(sum<0)
               {

                j++;

               }
               else if(sum>0)
               {
                   k--;
               }
               else
               {    
                   vector<int>temp={nums[i],nums[j],nums[k]};
                //    temp.push_back(nums[i]);
                //    temp.push_back(nums[j]);
                //    temp.push_back(nums[k]);
                   ans.push_back(temp);
                   j++;
                   k--;
                   while(j<k && nums[j]==nums[j-1])j++;
                   while(j<k && nums[k]==nums[k+1])k--;
               }
           }
       }
       return ans;
    }
};