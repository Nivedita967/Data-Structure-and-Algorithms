class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:        # Getting elements of both the trees
        def dfs(root):                                                              # Using recursion to find root
            if not root:
                return
            dfs(root.left)
            l.append(root.val)                                                     # Storing values of the tree in the list
            dfs(root.right)
        l=[]                                                                       # Creating empty list to store values
        dfs(root1)
        dfs(root2)
        return sorted(l)                                                           # Giving result after sorting the list
