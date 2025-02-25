class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {

        vector<int>ans;
        int n=2147483647;
        for(int i=1;i<=n;i++)
        {

               if(memory1<i&&memory2<i)
            {
                ans.push_back(i);
                ans.push_back(memory1);
                ans.push_back(memory2);
                break;
            }
            if(memory1==memory2||memory1>memory2)
            {
                memory1-=i;
            }
            else if(memory2>memory1)
            {
                memory2-=i;
            
            }

            //  if(memory1<i+1&&memory2<i+1)
            // {
            //     ans.push_back(i+1);
            //     ans.push_back(memory1);
            //     ans.push_back(memory2);
            //     break;
            // }

            // if(memory1==0||memory2==0)
            // {
            //     ans.push_back(i);
            //     ans.push_back(memory1);
            //     ans.push_back(memory2);
            // }
        }

        return ans;
        
    }
};