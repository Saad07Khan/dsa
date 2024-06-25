class Solution {
public:

    void fnc(int i,int j,int prev,vector<vector<int>>&ocean,vector<vector<int>>&heights)
    {
        if(i<0 || j<0 || i>=heights.size() || j>=heights[0].size())
        {
            return;
        }

        if(ocean[i][j]==1)
        {
            return;
        }

        if(heights[i][j]<prev)
        {
            return;
        }

        ocean[i][j]=1;
        fnc(i+1,j,heights[i][j],ocean,heights);//down
        fnc(i,j+1,heights[i][j],ocean,heights);//right
        fnc(i-1,j,heights[i][j],ocean,heights);//up
        fnc(i,j-1,heights[i][j],ocean,heights);//left

    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        //consider reverse way
        vector<vector<int>>ans;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));

        for(int i=0;i<m;i++) //until column end as we go up and down until end of column
        {
            // fnc(0,i,INT_MIN,pacific,heights);
            // fnc(n-1,i,INT_MIN,atlantic,heights); 
            fnc(0,i,INT_MIN,pacific,heights);
            fnc(n-1,i,INT_MIN,atlantic,heights);
        }

        for(int j=0;j<n;j++) // go until end of rows as left and right
        {
            // fnc(0,j,INT_MIN,pacific,heights);
            // fnc(m-1,j,INT_MIN,atlantic,heights);
            fnc(j,0,INT_MIN,pacific,heights);
            fnc(j,m-1,INT_MIN,atlantic,heights);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==1 && atlantic[i][j]==1)
                {
                vector<int>v(2);
                v[0]=i;
                v[1]=j;
                ans.push_back(v);

                }
            }
        }

        return ans;
    }
};