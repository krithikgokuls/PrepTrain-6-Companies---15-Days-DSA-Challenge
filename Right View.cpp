/*
    Time Complexity : O(N)
    Space Complexity : O(N)
    
    Where N is the number of BinaryTreeNodes in the tree.
*/

vector<int> printRightView(BinaryTreeNode<int> *root){
    // It is used to store the answer.
    vector<int> ans;

    if (root == NULL)
    {
        return {};
    }

    // Queue used to do level order traversal.
    queue<BinaryTreeNode<int> *> q;
    q.push(root);

    // Traverse till queue becomes empty.
    while (!q.empty())
    {
        // Number of BinaryTreeNodes at the current level.
        int n = q.size();

        // Traverse all BinaryTreeNodes of the current level.
        for (int i = 1; i <= n; i++)
        {
            BinaryTreeNode<int> *temp = q.front();
            q.pop();

            // Add the right most element of the current level.
            if (i == n)
            {
                ans.push_back(temp->data);
            }

            // Add left BinaryTreeNode to the queue.
            if (temp->left != NULL)
            {
                q.push(temp->left);
            }

            // Add right BinaryTreeNode to the queue.
            if (temp->right != NULL)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}
