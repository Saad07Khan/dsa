/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL || root == p || root == q) // base case
        {
            return root;
        }
        
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left==NULL)
        {
            return right;
        }
        
        else if(right==NULL)
        {
            return left;
        }

        else // if both left and right are not null ie: required values
        {
            return root;
        }
    }
};
// Solution approach:- Use DFS traversal(Recursive DFS) first go to left and then go to right. 
// 0) If the root node is only one the node which you are looking for then return root
// 1) If both left and right returns null then returns null
// 2) If left returns a node and right returns null then return left and vice versa (Return something which gives u node) 
// 3) If both returns you the nodes then u have found the answer so return root


if(i==candidates.size())
{
    if(target==0)
    {
        ans.push_back(temp);
    }
}

if