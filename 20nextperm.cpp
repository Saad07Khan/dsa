class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), index = -1;
        for(int i=n-2; i>=0; i--){
            if(nums[i] < nums[i+1]){
                index = i;
                break;
            }
        }
        for(int i=n-1; i>=index && index != -1; i--){ // smallest among the largest element being replaced 
                                                          // by the index
            if(nums[i] > nums[index]){
                swap(nums[i], nums[index]);
                break;
            }
        }
        reverse(nums.begin() + index + 1, nums.end()); // reverse array after for loop and if index=-1 reverse it directly
    }
};





/*In the given code snippet, the index variable is being used to keep track of the index of the element that needs to be swapped to achieve the next lexicographically greater permutation of the input vector nums. The index is initially set to -1, and if it remains -1, it indicates that there is no next permutation possible, and the input vector is already in its highest possible lexicographical order.

Here's how the code works:

It starts by iterating through the nums vector from right to left (i goes from n-2 down to 0). It's looking for the first element that is smaller than the element to its right. This is because swapping such an element with a larger element from the right will give the next greater permutation. The index of this element is stored in the index variable.

If no such element is found (i.e., the loop completes without finding a suitable element), then index remains -1, indicating that the vector is already in its highest lexicographical order. In this case, there is no next permutation possible, and the vector is reversed to its smallest lexicographical order. This is why the index is initially set to -1.

If a suitable element is found (i.e., index is not -1), the code proceeds to another loop that iterates from the right end of the vector. It finds the smallest element that is larger than the element at the index position and swaps them.

Finally, the code reverses the subvector starting from index + 1 to the end. This step ensures that the remaining elements after swapping are in ascending order, as swapping only ensures the next permutation. Reversing makes the permutation the smallest possible after swapping the selected elements.

So, setting index to -1 initially allows the code to determine whether a next permutation is possible or not. If index remains -1, it means no next permutation is possible, and the vector is already at its maximum lexicographical order.*/