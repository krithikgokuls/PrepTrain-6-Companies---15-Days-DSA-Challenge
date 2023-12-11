/*
    Time Complexity: O(n * log(n))
    Space Complexity : O(n)

    Where 'n' is the number of nodes in the given binary tree.
*/

/************************************************************

    Following is the TreeNode class structure:

    template <typename T>
    class TreeNode
    {
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T dat)
        {
            this->data = dat;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/

#include <map>
#include <queue>

vector<int> getTopView(TreeNode<int> *root)
{
    // For storing top view element.
    vector<int> topView;

    // Key will be the horizontal distance from root and value corresponding to that key will be the value of the node.
    map<int, int> visited;

    // If root is NULL then return the top view.
    if (root == NULL)
    {
        return topView;
    }

    // For iterating level by level.
    queue<pair<TreeNode<int> *, int>> level;

    // Append root to the level with 0 horizontal distance.
    level.push({root, 0});

    // Iterate untill level does not become empty.
    while (level.size() != 0)
    {
        // Get total number of node at current level.
        int levelSize = level.size();

        while (levelSize != 0)
        {
            // Get front of the queue.
            pair<TreeNode<int> *, int> curr = level.front();
            level.pop();

            // Get the horizontal distance of curr node.
            int hrDistance = curr.second;

            // Get current node.
            TreeNode<int> *currNode = curr.first;

            // Check whether hDistance is visited or not. If not visited then only it will be seen by the top of the tree.
            if (visited.count(hrDistance) == 0)
            {
                // Make it visited.
                visited.insert({hrDistance, currNode->data});
            }

            // Append left child if it exist with horizontal distance one less than currNode.
            if (currNode->left != NULL)
            {
                level.push({currNode->left, hrDistance - 1});
            }

            // Append right child if it exist with horizontal distance one more than currNode.
            if (currNode->right != NULL)
            {
                level.push({currNode->right, hrDistance + 1});
            }

            levelSize = levelSize - 1;
        }
    }

    // Now visited have the element which can be the view from the top of the tree
    for (auto x : visited)
    {
        topView.push_back(x.second);
    }

    // Return the answer sequence of nodes.
    return topView;
}
