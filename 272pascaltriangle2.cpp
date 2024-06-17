class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>>ans;

        for(int i=0;i<=rowIndex;i++)
        {
            vector<int>v(i+1,1);
            for(int j=1;j<i;j++)
            {
                v[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        
       return ans[rowIndex];



        


    }
};


    //         int low=0, mid=0, n= (int)nums.size();
    //         int high=n-1;
            
    // while(mid<=high)
    // {
    //     if(nums[mid]==0)
    //     {
    //         swap(nums[low],nums[mid]);
    //         low++;
    //         mid++;
    //     }

    //     else if(nums[mid]==1)
    //     {
    //         mid++;
    //     }

    //      else
    //     {
    //         swap(nums[mid],nums[high]);
    //         high--;
    //     }
    // }