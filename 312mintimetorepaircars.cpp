class Solution {
public:

    bool isPossible(vector<int>&ranks, long long mid, int cars)
    {
        long long carcount=0;
        for(int i=0;i<ranks.size();i++)
        {
            carcount+=(sqrt)(mid/ranks[i]);
        }

        if(carcount>=cars)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long low=1;
        long long high=(long long)cars*(long long)cars*100;
        long long ans=high;

        while(low<=high)
        {
            long long mid=(low+high)/2;
            if(isPossible(ranks,mid,cars))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return ans;


        
    }
};