// PROBLEM STATEMENT:
// Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

// According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
//  that has both p and q as descendants (where we allow a node to be a descendant of itself).”

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        // Applying the base condition
        if(root == null)
            return null;
        // If this condition is true then that root value will be the ancestor of p & q.
        if(root.val == p.val || root.val == q.val)
            return root;
        // Recursive Solution: apply Depth First Search. & traverse left subtree of the node and then right subtree of the node recursively.
        TreeNode l = lowestCommonAncestor(root.left,p,q);
        TreeNode r = lowestCommonAncestor(root.right,p,q);
        // (l != null && r != null ) found p and q in left and right subtree, return itself. 
        if(l != null && r != null)
            return root;
        // (l != null && r == null ) or (l == null || r != null) propogate it above.
        if(l != null || r == null)
            return l;
        if(l == null || r != null)
            return r;
        //  If you dont find neither p nor q in subtress, return null, since current node cannot be the LCA.
        return null;
        
    }
}