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

    int calcNode(TreeNode* root)
    {
        if(root==NULL)return 0;

        int lh= calcNode(root->left);
        int rh= calcNode(root->right);

        return 1+(lh+rh);
    }
    int calc(TreeNode* root,int &counter)
    {

        if(root==NULL)
        {
            return 0;
        }
        int sum=0;
        sum+=calc(root->left,counter);
        sum+=calc(root->right,counter);
        int cnt=calcNode(root);
        sum+=root->val;
        if(sum/cnt==root->val)
        {
            counter++; 
        }
        return sum;

    }
    int averageOfSubtree(TreeNode* root) {
        if(root==NULL)return 0;
        int counter =0;
        calc(root,counter);
        return counter;
        
    }
};