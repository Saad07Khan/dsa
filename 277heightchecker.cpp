class Solution {
public:
    int heightChecker(vector<int>& heights) {

        int n=heights.size();
        int no=0;
        vector<int>expected(heights.begin(),heights.end());
        sort(expected.begin(),expected.end());

        for(int i=0;i<n;i++)
        {
            if(expected[i]!=heights[i])
            {
                no+=1;
            }
        }

        return no;

        
    }
};