/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    TreeNode* convert(int low, int high, vector<int>&nums)
    {
        if(low>high)return NULL;
        int mid = low+(high-low)/2;
        TreeNode*head= new TreeNode(nums[mid]);
        head->left=convert(low,mid-1,nums);
        head->right=convert(mid+1,high,nums);
        return head;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n=nums.size();
        return convert(0,n-1,nums);
        
    }
};