class Solution {
public:
    static bool cmp(int x , int y) {
        string xy = to_string(x) + to_string(y);
        string yx = to_string(y) + to_string(x);
        return xy > yx;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin() , nums.end() , cmp);
        string ans = "";
        for(int i = 0 ; i < nums.size() ; i++) {
            ans += to_string(nums[i]);
        }
        if(ans[0] == '0')
           return "0";
        return ans;
    }
};  



// This code defines a class Solution that contains two functions: cmp and largestNumber. It appears to solve the problem of arranging an array of integers in such a way that they form the largest possible number when concatenated.

// cmp Function:

// This is a static method defined within the Solution class. It's used as a custom comparator for the sort function, which will determine how the array elements are sorted.
// The comparator takes two integers, x and y, as its parameters.
// The function first converts both x and y to strings using the to_string function.
// It then forms two concatenated strings: xy, which is x followed by y, and yx, which is y followed by x.
// Finally, it returns true if xy is greater than yx. This means that if xy should appear before yx in the sorted order, then cmp returns true. Otherwise, it returns false.
// largestNumber Function:

// This function takes a reference to a vector of integers called nums as its parameter.
// It first calls the sort function on nums, using the custom comparator cmp defined earlier. This sorts the array in a way that maximizes the concatenation of elements to form the largest number.
// Then, it initializes an empty string ans that will eventually store the concatenated result.
// The function iterates through the sorted nums array and appends the string representation of each number to ans.
// After the loop, it checks if the first character of ans is '0'. If it is, it means that the largest possible number is 0 (since the array elements are sorted), so it returns "0" directly.
// If the first character is not '0', it means there is a valid larger number, so it returns ans.
// In summary, this code sorts an array of integers in a custom way to form the largest possible number when concatenated, and handles cases where the largest number is 0.