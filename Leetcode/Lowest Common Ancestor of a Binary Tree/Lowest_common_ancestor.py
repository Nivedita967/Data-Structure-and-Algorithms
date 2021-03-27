# PROBLEM STATEMENT:
# Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.

# According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T
# that has both p and q as descendants (where we allow a node to be a descendant of itself).”

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root, p, q):
        
        if p==q:
            return p
        
        self.val = None
        self.d   = -1
        
        def dfs(n,d):
            res = 0
            if n and d>self.d:
                # Recursive Solution: apply Depth First Search. & traverse left subtree of 
                # the node and then right subtree of the node recursively.
                res  = n in [p,q]
                res += dfs(n.left ,d+1)
                res += dfs(n.right,d+1)
                
                if res == 2 and d > self.d:
                    self.val = n
                    self.d   = d

            # return result
            return res
        
        dfs(root,0)
        return self.val

