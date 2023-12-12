/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    Where N is the number of nodes in the Binary Tree.
*/

// Recursive function to find the maximum sum path with current node as peak
int currentPathSum(BinaryTreeNode<int> *currentPeak, int &maxSum)
{
    // Checking if the current node is NULL.
    if (currentPeak == NULL)
    {
        return 0;
    }

    int maxPathSumLeft = max(currentPathSum(currentPeak->left, maxSum), 0);
    int maxPathSumRight = max(currentPathSum(currentPeak->right, maxSum), 0);

    int currentSum = maxPathSumLeft + maxPathSumRight + (currentPeak->data);

    // Updating the overall maximum sum 
    maxSum = max(currentSum, maxSum);

    return max(maxPathSumLeft, maxPathSumRight) + (currentPeak->data);
}

int maxPathSum(BinaryTreeNode<int> *root)
{
    int maxSum = INT_MIN;

    // Calling the recursive function 
    currentPathSum(root, maxSum);

    // Returning the updated value
    return maxSum;

}
