class Solution {
public:
int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> rightsmall(n), leftsmall(n);
         int maxi = 0;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) leftsmall[i] = 0;
            else leftsmall[i] = st.top() + 1;

            st.push(i);
        }
        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }
            if (st.empty()) rightsmall[i] = n - 1;
            else rightsmall[i] = st.top() - 1;

            st.push(i);
        }
       
        for (int i = 0; i < n; i++) {
            maxi = max(maxi, heights[i] * (rightsmall[i] - leftsmall[i] + 1));
        }
        return maxi;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size(); //row size
        int m= matrix[0].size(); //coloumn size
        int maxArea=0;
        vector<int>heights(m,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]=='1')heights[j]++;
                else
                heights[j]=0;
            }
            int area = largestRectangleArea(heights);
            maxArea= max(area,maxArea);

        }
        return maxArea;
        
    }
};