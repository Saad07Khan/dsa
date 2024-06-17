// npos in C++ is a constant representing the absence of a valid position or the result when a substring is not found in a string. It is typically returned by string search functions.

// Input: s = "abcde", goal = "cdeab"
// Output: true 
// Input: s = "abcde", goal = "abced" Output: false


class Solution {
public:
    bool rotateString(string s, string goal) {

        int n1= s.size();
        int n2= goal.size();

        if(n1!=n2)
        {
            return false;
        }

        string ans = s+s;

        if(ans.find(goal)!=string::npos)//means if goal is present in string return true
        {
            return true;
        }
        else
        {
            return false;
        }

    
    }
};