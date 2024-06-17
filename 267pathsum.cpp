class Solution {
public:

    bool tg(TreeNode* root, int sum, int targetSum)
    {
        if(root==NULL)
        {
            return false;
        }

        if(!root->left && !root->right)
        {
        sum+=root->val;
        if(sum==targetSum) return true;
        }
        return tg(root->left,sum+root->val,targetSum)|| tg(root->right,sum+root->val,targetSum);
    }   
    bool hasPathSum(TreeNode* root, int targetSum) {

        if(tg(root,0,targetSum)) return true;
        else
        return false;
    }
};