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
    vector<int> inorderTraversal(TreeNode* root) {
        stack <TreeNode*> a;
        vector <int> b;
        while (root || !a.empty()){ 
            if (root){
                a.push(root);   //if node is not null push it to the stack and move forward to the left child node.
                root = root->left;
            }
            else{
                root = a.top(); //root is null, hence we have reached the end of left tree, we need to check the right nodes. 
                a.pop();
                b.push_back(root->val);
                root = root->right;
            }
        }
        return b;
    }
};