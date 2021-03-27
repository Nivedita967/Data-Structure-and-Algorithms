# Given the root of a binary tree, invert the tree, and return its root.
class Solution:
    def invertTree(self, root):
        # not empty tree: base condition
        if root:
            # swap right subtree with left & left subtree with right
            root.left, root.right = (self.invertTree(root.right), self.invertTree(root.left))
        # Return The root
        return root