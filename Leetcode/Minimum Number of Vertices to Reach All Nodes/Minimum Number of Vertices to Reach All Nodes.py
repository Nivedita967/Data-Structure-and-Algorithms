
#Python program to find

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        # return the answer
        return set(range(n)).difference({n2 for n1, n2 in edges})

        