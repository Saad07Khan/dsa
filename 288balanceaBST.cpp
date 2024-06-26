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
    void inorder(TreeNode* root,vector<int>&ans)
    {
        if(root==NULL)
        {
            return;
        }

        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        return convert(ans,0,n-1);
    }

    TreeNode* convert(vector<int>&ans,int left, int right)
    {
        if(left>right)return NULL;
        int mid= left+(right-left)/2;
        TreeNode* head= new TreeNode(ans[mid]);
        head->left=convert(ans,left,mid-1);
        head->right=convert(ans,mid+1,right);
        return head;

    }
};
