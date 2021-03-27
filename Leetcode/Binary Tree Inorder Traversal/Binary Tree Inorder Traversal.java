// Given the root of a binary tree, return the inorder traversal of its nodes' values.
import java.util.*;
class Solution {
    // Initialize an arraylist
    List<Integer> al = new ArrayList();
    public List<Integer> inorderTraversal(TreeNode root) {
        iot(root);
       return al; 
    }
    // iot is a helper method to store the inorder traversed node value in ArrayList al.
    public void iot(TreeNode root){
        // Base condition: root != null
        if(root != null){
            // Traverse the left subtree of root
            if(root.left != null){
                iot(root.left);
            }
            // root add root value to the list
            al.add(root.val);
            // Traverse the right subtree of root
            if(root.right != null){
                iot(root.right);
            }
        }
        
    }
}