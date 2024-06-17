//Input: gain = [-5,1,5,0,-7]
// Output: 1
// Explanation: The altitudes are [0,-5,-4,1,1,-6]. The highest is 1.


class Solution {
public:
// imp: always use push_back to put in values in the vector
    int largestAltitude(vector<int>& gain) {
        int highest=INT_MIN;
        vector<int> pre;
      

        pre.push_back(0);

        for(int i=1;i<=gain.size();i++) //<= is used since we are accesing last element as well so -1 will give us the last element
        {
            pre.push_back(pre[i-1]+gain[i-1]);
        }

       highest = *max_element(pre.begin(),pre.end());

        return highest;


    }
};

