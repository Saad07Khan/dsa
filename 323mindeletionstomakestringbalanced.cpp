class Solution {
public:
    int minimumDeletions(string s) {

        //if ab pair pop stack
        stack<char>st;
        int delcount=0;
        for(int i=0;i<s.length();i++)
        {
            if(!st.empty() && st.top()=='b' && s[i]=='a')
            {
                st.pop();
                delcount++;
            }
            else
            {
                st.push(s[i]);
            }
        }

        return delcount;
        
    }
};