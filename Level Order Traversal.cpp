
/*
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the number of nodes in Binary Tree
*/

vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    vector<int> output;

    //  If given tree is empty
    if (root == NULL)
    {
        return output;
    }

    //  To traverse level by level
    queue<BinaryTreeNode<int> *> level;

    //  Append root to the queue
    level.push(root);

    //  Iterater until queue does not become empty
    while (!level.empty())
    {
        //  Get the size of current level
        int levelSize = level.size();

        //  Visit all node which are at current level and append their children if they exist
        while (levelSize != 0)
        {
            //  Get the front node from queue
            BinaryTreeNode<int> *curr = level.front();
            level.pop();

            //  Store in output
            output.push_back(curr->val);

            //  Append left child into queue if it exist
            if (curr->left != NULL)
            {
                level.push(curr->left);
            }

            //  Append right child into queue if it exist
            if (curr->right != NULL)
            {
                level.push(curr->right);
            }
            levelSize = levelSize - 1;
        }
    }

    //  Return the output
    return output;
}
