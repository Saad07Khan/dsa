class Solution
{
public:
    int dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return 0;
        }
        int lh = dfs(root->left);
        if (lh == -1)
            return -1;
        int rh = dfs(root->right);
        if (rh == -1)
            return -1;

        if (abs(lh - rh) > 1)
            return -1;

        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode *root)
    {
        if (dfs(root) == -1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};