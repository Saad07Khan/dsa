class Solution {
public:
    int minFlipsMonoIncr(string s) {
        stack<char>st;
        int n=s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!st.empty()&&st.top()=='1'&&s[i]=='0')
            {
                st.pop();
                count++;
            }

            else
            {
                st.push(s[i]);
            }
        }

        return count;
        
    }
};