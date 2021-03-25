class Solution:
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        Stack=[]                                     # Creaating an empty stack
        pushed=deque(pushed)                         # Creating double ended queue
        popped=deque(popped)                         
        while(len(pushed)):
            
            if len(Stack)==0:
                Stack.append(pushed.popleft())
            else:
                push = pushed.popleft()              # Pushing and popping according to input
                pop  = popped.popleft()
                if Stack[-1]==pop:
                    Stack.pop()
                    pushed.appendleft(push)
                else:
                    Stack.append(push)
                    popped.appendleft(pop)
        
        while(len(Stack)):                            # Checking whether those input can be used in a stack (if we finally get an empty stack, input is valid)
            pop=popped.popleft()
            top=Stack.pop()
            if pop!=top:
                return False
        return True                                   # Returning result
      
