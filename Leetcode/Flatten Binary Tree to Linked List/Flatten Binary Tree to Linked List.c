// Given the root of a binary tree, flatten the tree into a "linked list":

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

void flatten(struct TreeNode* root)
{
    // if root != null
        if(root)
        {
            // initialize a variable of type TreeNode to root->right
            struct TreeNode* flat_tree = root->right;
            // perform recursive Depth First Search for left & right subtree
            flatten(root->left);
            flatten(root->right);
            
            // Flatten by assigning root->right = root->left
            root->right = root->left;
            root->left = NULL;
            // traverse the right subtree of root
            while(root->right)
            {
                root = root->right;
            }
            // flat_tree = initial root->right
            root->right = flat_tree;
        }
   
}