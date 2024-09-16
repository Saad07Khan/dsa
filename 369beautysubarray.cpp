class Solution {
public:
    int divisorSubstrings(int num, int k) {
        //no of substrings of num when it is read as a string
        //length of k
        //divisor of num
        //
        
        string s= to_string(num);
        int n=s.length();
        int i;
        int count=0;
        for(int j=0;j<=n-k;j++)
        {
           string str= s.substr(j,k);
           int divisor=stoi(str);

            if (divisor == 0) {
                continue;
            }

            if(num% divisor==0)
            {
                count++;
            }
        }
        return count;

        
    }
};