class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int i=0;
        int count=0;
        int n=s.length();
        int zcount=0;
        int ocount=0;
        for(int j=0;j<n;j++)
        {
            if(s[j]=='0')
            {
                zcount++;
            }
            if(s[j]=='1')
            {
                ocount++;
            }

            while(zcount>k && ocount>k)
            {
                if(s[i]=='0')
                {
                    zcount--;
                }
                if(s[i]=='1')
                {
                    ocount--;
                }

                i++;
            }

            count+=(j-i+1);
        }

        return count;
    }
};