class Solution {
public:
    void flatten(TreeNode* root) {
        
        //Base Cases: If root is NULL or root is a leaf node then no change.
        if(!root) return;
        if(!root->left and !root->right) return;
        
        //1st Flatten the right and left child
        flatten(root->left);
        flatten(root->right);
        
        //Store the right of the tree in a var temp
        TreeNode* temp=root->right;
        
        //Then Connect left subtree to right side and  make left child NULL
        root->right=root->left;
        root->left=NULL;
        
        // Only thing left is to connect the right child to its proper place
        while(root->right)
            root=root->right;
        
        root->right=temp;
        return;
    }
};