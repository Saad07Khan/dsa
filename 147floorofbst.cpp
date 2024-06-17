int Floor(BinaryTreeNode<int> *node, int input)
{
    int floor = -1;

    while (node)
    {
        if (node->data == input)
        {
            floor = node->data;
            return floor;
        }

        if (input < node->data)
        {
            node = node->left;
        }
        else
        {
            floor = node->data;
            node = node->right;
        }
    }
    return floor;
}
