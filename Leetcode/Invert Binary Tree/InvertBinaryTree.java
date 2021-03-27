/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution 
{
    public TreeNode invertTree(TreeNode root) 
    {
        //empty tree
        if(root==null)                                          
            return root;
        
        //to traverse down left side of tree
        TreeNode left = invertTree(root.left);       
        
        //to traverse down right side of tree
        TreeNode right = invertTree(root.right);    
        
        //swap children
        root.right = left;                                      
        root.left = right;
        
        //return root of inverted binary tree
        return root;
    }
}