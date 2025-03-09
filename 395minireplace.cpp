class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int i = 0;
        int n = blocks.size();
        int ans = INT_MAX;
        int wcount=0;
        int bcount=0;
        for (int j = 0; j < blocks.size(); j++) {
            if(blocks[j]=='W')
            {
                wcount++;
            }
            while((j-i+1)>k)
            {
                if(blocks[i]=='W')
                {
                    wcount--;
                }
                i++;
            }
            if((j-i+1)==k)
            {
             ans=min(ans,wcount);
            }

        }
        return ans;
    }
};
