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


sort colors brute force
class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Initialize counters for 0s, 1s, and 2s
        int count0 = 0, count1 = 0, count2 = 0;
        
        // Count the number of 0s, 1s, and 2s
        for(int num : nums) {
            if(num == 0) {
                count0++;
            } else if(num == 1) {
                count1++;
            } else {
                count2++;
            }
        }
        
        // Overwrite the array with the sorted colors
        int index = 0;
        for(int i = 0; i < count0; i++) {
            nums[index] = 0;
            index++;
        }
        for(int i = 0; i < count1; i++) {
            nums[index] = 1;
            index++;
        }
        for(int i = 0; i < count2; i++) {
            nums[index] = 2;
            index++;
        }
    }
};












