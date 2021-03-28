//Problem:https://leetcode.com/problems/invert-binary-tree/

//Approach:Main Idea in inverting here is, to attach the left sub tree
//to the right of root and, attach the right subtree to the left of the root. 
//Repeat this for each and every node, and eventually the tree will be inverted. 

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
