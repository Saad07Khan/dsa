class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans;
        for(int i=0;i<=n;i++)
        {
            bitset<32>binary(i);
            string b= binary.to_string();
            int count=0;
            for(int j=0;j<b.length();j++)
            {
                if(b[j]=='1')
                {
                    count++;
                }
            }
            ans.push_back(count);
        }
        return ans;
    }
};