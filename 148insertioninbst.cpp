class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (root == NULL)
            return new TreeNode(val);
        TreeNode *cur = root; // creating copy of root as have to return it at end

        while (true) // traverses until break statement is encountered
        {
            if (cur->val <= val)
            {
                if (cur->right != NULL)
                    cur = cur->right;
                else
                {
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (cur->left != NULL)
                    cur = cur->left;
                else
                {
                    cur->left = new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};