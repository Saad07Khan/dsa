class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.size();
        int count=0;
        int i=0;
        int maxi=0;

        for(int j=0;j<n;j++)
        {
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')
            {
                count++;
            }

            while(i<=j && j-i+1>k)
            {
                if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u')
                {
                count--;
                }

                i++;
            }
            maxi=max(maxi,count);
        }
        return maxi;
    }
};