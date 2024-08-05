class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1=p.length();
        int n2=s.length();
        vector<int>p_count(26,0);
        vector<int>s_count(26,0);
        vector<int>ans;
        if (n1 > n2) return ans;
        for(int i=0;i<n1;i++)
        {
            p_count[p[i]-'a']++;
            s_count[s[i]-'a']++;
        }

        for(int i=n1;i<n2;i++)
        {
            if(p_count==s_count)
            {
                ans.push_back(i-n1);
            }

            s_count[s[i]-'a']++;
            s_count[s[i-n1]-'a']--;
        }

          if (p_count == s_count) {
            ans.push_back(n2 - n1);
        }
        return ans;

    }
};