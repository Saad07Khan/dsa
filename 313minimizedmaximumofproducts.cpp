class Solution {
public:

    bool isPossible(vector<int>&quantities,int mid, int n)
    {
        int cnt=0;
        for(int i=0;i<quantities.size();i++)
        {
            cnt+=ceil((double)quantities[i]/(double)mid);
        }

        return cnt<=n; //0 products can also be given to stores
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high= *std::max_element(quantities.begin(),quantities.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(isPossible(quantities,mid,n))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};