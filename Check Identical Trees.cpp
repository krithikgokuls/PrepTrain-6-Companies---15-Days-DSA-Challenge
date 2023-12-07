/*
    Time complexity: O(min(M, N)) 
    Space complexity: O(min(H1, H2)
    
    M and N are number of nodes and H1 and H2 are heights of binary tree 1 and binary tree 2 respectively.
*/

bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
         
    // If both are NULL trees, they are identical.       
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    
    // If any one of the trees is NULL, they are not identical. 
    if(root1 == NULL || root2 == NULL){
        return false;
    }
    
    // Check if root's data of both the trees is same. 
    // Recursively check if left subtree and right subtree of both trees is identical. 
    // Return true only if all conditions satisfy. 
    
    return (root1->data == root2->data) && 
            identicalTrees(root1->left, root2->left) && 
            identicalTrees(root1->right, root2->right);
    
}
