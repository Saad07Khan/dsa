class Solution {
public:
    int maxArea(vector<int>& height) {
        int start=0;
        int end = height.size()-1;
        int currentarea;
        int maxarea=0;

        while(start<end)
        {
            currentarea=min(height[start],height[end])*(end-start);
            if(area>maxarea) maxarea = currentarea;

            if(min(height[start],height[end])==height[start])
                start++;
            else end--;
        }

        return maxarea;
    }
};