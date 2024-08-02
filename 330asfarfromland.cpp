#include <iostream>
#include <vector>
#include <cmath>    // Include cmath for the ceil function
#include <climits>  // Include climits for INT_MIN

using namespace std;

class Solution {
public:
    int maximum(vector<int>& nums) {
        int maxi = INT_MIN;
        for(int i = 0; i < nums.size(); i++) {
            maxi = max(maxi, nums[i]);
        }
        return maxi;
    }

    bool check(vector<int>& piles, int       , int hours) {
        long long countHours = 0;
        for(int i = 0; i < piles.size(); i++) {
            countHours += ceil((double)piles[i] / (double)eatingSpeed);
        }
        return countHours <= hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = maximum(piles);
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(piles, mid, h)) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {2,5,3,6,7,1}; // Example piles of bananas
    int h = 6; // Example hours available

    int result = sol.minEatingSpeed(piles, h);

    cout << "The minimum eating speed is: " << result << endl;

    return 0;
}
