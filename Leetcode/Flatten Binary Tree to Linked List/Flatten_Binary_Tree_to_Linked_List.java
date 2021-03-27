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
class Flatten_Binary_Tree_to_Linked_List {
    public void flatten(TreeNode root) {
        //if root is null return
         if(root == null) {
             return;
         }
         //create a stack
         Stack<TreeNode> stack = new Stack<>();
         stack.push(root);
         //check whether stack is empty or not
         while(!stack.isEmpty()) {
             TreeNode cur = stack.pop();
             
             //Push right child first, so we can use left child first
             if(cur.right != null) {
                stack.push(cur.right); 
             }
             //Push left child first, so we can use right child first
             if(cur.left != null) {
                stack.push(cur.left); 
             }
             
             if(!stack.isEmpty()) {
                cur.right = stack.peek();
                cur.left = null;
             }
         }
     }
 }

 