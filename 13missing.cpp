class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0, xor2=0, n=nums.size();
        int n1=n-1;

        for(int i=0;i<n1;i++)
        {
            xor2=xor2^nums[i];
            xor1=xor1^(i+1); // xors all the numbers except last no in range ie (1,2,3,4) if range is 5
        }

        xor1 = xor1^n;
        return xor1^xor2;

        // better optimized as only uses one loop
        // in the end we xor with n as in the loop we dont go until the last number
   
        
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0,n=nums.size();
        for(int i=1;i<=n;i++)
        {
            xor1=xor1^i;
        }

        for(int i=0;i<n;i++)
        {
            xor1=xor1^nums[i];
        }

        return xor1;

        
    }
};



class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int xor1=0,n=nums.size();
        for(int i=1;i<=n;i++)
        {
            xor1=xor1^i;
        }

        for(int i=0;i<=n-1;i++)
        {
            xor1=xor1^nums[i];
        }

        return xor1;

        
    }
};