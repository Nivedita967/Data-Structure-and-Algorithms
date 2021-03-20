# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root):

        if not root:
            return root
        
        res = []                                            # Declaring the list to contain tree elements            
            
        if root.left:
            res += self.inorderTraversal(root.left)         # Updating list to find if the tree is left
        
        if root:                                            # Appending value of root in the list
            res.append(root.val)
        
        if root.right:
            res += self.inorderTraversal(root.right)        # Updating list to find if the tree is right

        return res                                          # Returning result
        
