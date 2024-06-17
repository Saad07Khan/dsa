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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> result;
        if (root == NULL)
        {
            return result;
        }

        queue<TreeNode *> q;
        bool leftToright = true;
        // flag 1 - L->R
        // flag 0 - R->L
        q.push(root);

        while (!q.empty())
        {
            int size = q.size();
            vector<int> zig(size);

            for (int i = 0; i < size; i++)
            {
                TreeNode *node = q.front();
                q.pop();
                int index;
                if (leftToright)
                {
                    index = i;
                }
                else
                {
                    index = size - i - 1;
                } // to make it reverse if flag=0
                zig[index] = node->val;
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
            }
            leftToright = !leftToright;
            result.push_back(zig);
        }
        return result;
    }
};