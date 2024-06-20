class Solution {
public:

    bool isPossible(vector<int>&position, int mid, int m)
    {
        int places=1;
        int prev=position[0];
        for(int i=1;i<position.size();i++)
        {
            if(position[i]-prev>=mid)
            {
                places+=1;
                prev=position[i];
                 
            }
           if(places==m)
            {
                return true;
            }
        }

         return false;

    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(),position.end());
        int n=position.size();
        int start=0;
        int end=position[n-1];
        int ans;
        while(start<=end)
        {
            int mid = start +((end-start)/2);

            if(isPossible(position,mid,m))
            {
                ans=mid; start=mid+1;
            }

            else
            {
                end=mid-1;
            }
        }

        return ans;
    }
};