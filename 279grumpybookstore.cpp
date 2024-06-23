class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();
        int unSatisfied=0;
        for(int i=0;i<minutes;i++)
        {
            if(grumpy[i]==1)
            {
                unSatisfied+=customers[i];
            }
        }

        int i=0;
        int j=minutes;
        int maxi=unSatisfied;
        while(j<n)
        {
            if(grumpy[j]==1)
            {
                unSatisfied+=customers[j];
            }
            if(grumpy[i]==1)
            {
                unSatisfied-=customers[i];
            }

            maxi=max(maxi,unSatisfied);
            i++;
            j++;
        }

        int totSatisfied=0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                totSatisfied+=customers[i];
            }
        }

        return totSatisfied+maxi;
        
    }
};