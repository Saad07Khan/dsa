class Solution {
public:
    void leftBoundary(Node*root, vector<int>&res)
    {
        Node*curr = root->left;
        while(curr)
        {
            if(!isLeaf(curr))res.push_back(curr->data);
            if(curr->left)curr=curr->left;
            else
            curr=curr->right;
        }
    }
    
    void rightBoundary(Node*root, vector<int>&res)
    {
        vector<int>temp;
        
        Node*curr=root->right;
        while(curr)
        {
            if(!isLeaf(curr))temp.push_back(curr->data);
            if(curr->right)curr=curr->right;
            else
            curr=curr->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--)
        {
            res.push_back(temp[i]);
        }
    }
    
    void leafTraversal(Node* root, vector<int>&res)
    {
        
        if(isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        
        if(root->left)leafTraversal(root->left,res);
        if(root->right)leafTraversal(root->right,res);
    }

    bool isLeaf(Node *root)
    {
        if(!root->left&&!root->right)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    vector <int> boundary(Node *root)
    {
        vector<int>res;
       if(root==NULL)return res;
       if(!isLeaf(root)) res.push_back(root->data);
       leftBoundary(root,res);
       leafTraversal(root,res);
       rightBoundary(root,res);
       return res;
    }
};