//Lca of nodes n1 and n2 is shared ancestor of nodes n1 and n2 which is located farthest from the roots

//In a tree we should always think for a particular node and recursion will take care of all nodes

//Here, the current node is root
// If root is Null then no LCA return NULL

// If root is either p or q then LCA is root
// Else if tell the left subtree to find LCA and right subtree to find LCA and store in left and right variables
//If left and right both are not null then root is LCA
//If left is NULL and right is NOT NULL then left subtree contains LCA so simply return left
//Vice Versa for right

//Else if left and right both are NULL return NULL

//Refer to code line by line to understand completely.

class Solution {
public:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return NULL;
        
        if(root->val==p->val or root->val==q->val)
            return root;
        
        TreeNode* left=lca(root->left,p,q);
        TreeNode* right=lca(root->right,p,q);
        
        if(left and right)
            return root;
        
        if(left)
            return left;
        
        if(right)
            return right;
        
        return NULL;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};