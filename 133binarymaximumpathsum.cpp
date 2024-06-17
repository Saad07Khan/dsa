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
class Solution
{
public:
    int maxiPath(TreeNode *node, int &maxi)
    {
        if (node == NULL)
        {
            return 0;
        }

        int lh = max(0, maxiPath(node->left, maxi)); // 0 is passed to not take -ve val in account
        int rh = max(0, maxiPath(node->right, maxi));
        maxi = max(maxi, lh + rh + node->val); // ans will be stored in maxi

        return max(lh, rh) + node->val;
    }
    int maxPathSum(TreeNode *root)
    {
        int maxi = INT_MIN;
        maxiPath(root, maxi);
        return maxi;
    }
};