 vector<int> preorderTraversal(TreeNode* root) {
        vector<int>ans;
        stack<TreeNode*>st;
        if(root==NULL)
        {
            return ans;
        }

        st.push(root);

        while(!st.empty())
        {
            root = st.top();
            st.pop();
            ans.push_back(root->val);
            if(root->right!=NULL)
            {
                st.push(root->right);
            }
            if(root->left!=NULL)
            {
                st.push(root->left);
            }
        }
        return ans;
    }
};