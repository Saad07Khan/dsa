class Solution {
public:
    int minOperations(vector<string>& logs) {
        int count=0;
        for(int i=0;i<logs.size();i++)
        {
            if(logs[i]=="./")
            {
                continue;
            }
            else if(logs[i]=="../")
            {
                if(count==0) // to avoid count going into negative (dry run testcase 3 to understand)
                {
                    count=0;
                }
                else
                {
                    count--;
                }
            }
            else
            {
                count++;
            }
        }
        return count;
    }
};