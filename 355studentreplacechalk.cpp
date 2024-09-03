class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n=chalk.size();
        long long sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=chalk[i];
        }
        k=k%sum;
        int i=0;
        while(k>0)
        {
            if(chalk[i]>k)
            {
                return i;
            }
            k-=chalk[i];
            i++;
            if(i==n)
            {
                i=0;
            }
        }
        return i;
        
        
    }
};