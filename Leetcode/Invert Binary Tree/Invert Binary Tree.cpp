/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Given the root of a binary tree, invert the tree, and return its root.
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        
        TreeNode *temp = root->left;   // initializing a temporary struct. Could also use a pointer 
        root->left = root->right;    //swap children
        root->right = temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;        //return root of inverted binary tree
       } 
};
