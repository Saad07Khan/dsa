/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
    
        while(!q.empty())
        {
            int s=q.size();
            Node* prev= NULL;
            for(int i=0;i<s;i++)
            {
                Node* node = q.front();
                q.pop();
                if(prev!=NULL)
                {
                prev->next=node;
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                prev= node;
            }
            prev->next=NULL;
        }

        return root;
    }

    //second approach
    /*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
        {
            return NULL;
        }
        queue<Node*>q;
        q.push(root);
        Node* prev;
    
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                Node* node = q.front();
                q.pop();
                if(i!=s-1)
                {
                    node->next=q.front();
                }
                if(node->left)q.push(node->left);
                if(node->right)q.push(node->right);
                prev=node;
                
            }
            // prev->next=NULL;
        }

        return root;
    }
};
};