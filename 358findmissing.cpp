class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int cs=accumulate(rolls.begin(),rolls.end(),0);
        int ts=mean*(m+n);
        int ms=ts-cs;
        if(ms<n||ms>6*n)
        {
            return {};
        }
        vector<int>res(n,1);
        ms-=n;
        for(int i=0;i<n && ms>=0;i++)
        {
            int add=min(5,ms);
            res[i]+=add;
            ms-=add;
        }

        return res;
    }
};