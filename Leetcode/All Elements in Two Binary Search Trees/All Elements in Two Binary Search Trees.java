
// Problem Statement:
//  All Elements in Two Binary Search Trees
//     Given two binary search trees root1 and root2.
//     Return a list containing all the integers from both trees sorted in ascending order.

 
class Solution {
    // Create an empty arrayList a: this will contain the inorder traversed values
    List<Integer> a = new ArrayList();  
    public List<Integer> getAllElements(TreeNode root1, TreeNode root2) {
        // Find the inorder traversal for each tree: This will sort the values for each node
        inorder(root1);
        inorder(root2);
        List<Integer> ans = new ArrayList(a);
        // sort the list
        Collections.sort(ans);
        return ans;
    }
    public void inorder(TreeNode root){
        // Base condition
        if(root == null)
            return;
        // for inorder traversal: left -> root ->  right
        inorder(root.left);
        a.add(root.val);
        inorder(root.right);
    }
}