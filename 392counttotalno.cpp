class Solution {
public:
    long long coloredCells(int n) {
        
        long long count=1;
        for(int i=0;i<n;i++)
        {
            count+=4*i;
        }

        return count;
    }
};