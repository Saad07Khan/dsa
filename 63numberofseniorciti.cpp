

//return the number of passengers strictly more than 60 yrs old
//The first ten characters consist of the phone number of passengers.
// The next character denotes the gender of the person.
// The following two characters are used to indicate the age of the person.
// The last two characters determine the seat allotted to that person.
class Solution {
public:
    int countSeniors(vector<string>& nums) {

        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            if(stoi(nums[i].substr(11,2))>60) ans++;
        }

        //stoi function convers string to integer and substr (11,2) extracts 2 strings from index 11 till 2 characters

        return ans;
        
    }
};