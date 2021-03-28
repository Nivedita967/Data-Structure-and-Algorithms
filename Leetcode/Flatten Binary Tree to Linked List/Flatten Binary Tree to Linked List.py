class Solution(object):
    def flatten(self, root):
        stack = []
        while root or stack:
            # something on left and right. push right node onto stack, swap and move left
            if root.left and root.right:
                stack.append(root.right)
                root.right = root.left
                root.left = None
                root = root.right
            # if just left, then swap and traverse
            elif root.left:
                root.right = root.left
                root.left = None
                root = root.right
            # if just right, then just traverse rightwards
            elif root.right:
                root = root.right
            else:
                if stack:
                    root.right = stack.pop()
                root = root.right
        return