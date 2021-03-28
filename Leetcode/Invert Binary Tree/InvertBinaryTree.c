void preOrder(struct TreeNode* root){
    if(!root)
        return;
    struct TreeNode* temp=root->left;
    root->left=root->right;
    root->right=temp;
    preOrder(root->left);
    preOrder(root->right);
   
}

struct TreeNode* invertTree(struct TreeNode* root){
    preOrder(root);
    return root;
}
