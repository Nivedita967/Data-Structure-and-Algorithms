class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        
        res = []
        stack1 = []            # Declaring stacks
        stack2 = []
        
        # returns next element in the in order traversal of tree from root.
        def inOrder(root, stack):
            current = root
            while True:

                if current is not None:

                    stack.append(current)

                    current = current.left 


                elif(stack):
                    current = stack.pop()
                    return current

                else:
                    return None
            
        cur1 = inOrder(root1, stack1)
        cur2 = inOrder(root2, stack2)
                    
        while(cur1 and cur2):
            
            if cur1.val > cur2.val:
                res.append(cur2.val)
                cur2 = inOrder(cur2.right, stack2)
            else:
                res.append(cur1.val)
                cur1 = inOrder(cur1.right, stack1)
                
        while(cur1):
            res.append(cur1.val)
            cur1 = inOrder(cur1.right, stack1)
        
        while(cur2):
            res.append(cur2.val)
            cur2 = inOrder(cur2.right, stack2)
            
        return res                  # Returning result
