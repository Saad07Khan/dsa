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
    int sum=0;
    void fnc(TreeNode* root)
    {
        if(!root)
        {
            return;
        }

        fnc(root->right);
        root->val+=sum;
        sum=root->val;
        fnc(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        fnc(root);
        return root;
    }
};