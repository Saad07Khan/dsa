class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n=answerKey.length();
        int i=0;
        int fcount=0;
        int ans=INT_MIN;
        for(int j=0;j<n;j++)
        {
            if(answerKey[j]=='F')
            {
                fcount++;
            }

            while(fcount>k)
            {
                if(answerKey[i]=='F')fcount--;
                i++;
            }

            ans=max(ans,j-i+1);

        }

        int tcount=0;
        int l=0;
        int ans1=INT_MIN;
         for(int j=0;j<n;j++)
        {
            if(answerKey[j]=='T')
            {
                tcount++;
            }

            while(tcount>k)
            {
                if(answerKey[l]=='T')tcount--;
                l++;
            }

            ans1=max(ans1,j-l+1);

        }

        int finalans=0;
        finalans= max(finalans,max(ans,ans1));
        return finalans;


        
    }
};