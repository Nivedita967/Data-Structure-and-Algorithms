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
        
        res = []                                     
            
        if root.left:
            res += self.inorderTraversal(root.left)         # Updating result
        
        if root:
            res.append(root.val)
        
        if root.right:
            res += self.inorderTraversal(root.right)

        return res                                          # Printing result
        
