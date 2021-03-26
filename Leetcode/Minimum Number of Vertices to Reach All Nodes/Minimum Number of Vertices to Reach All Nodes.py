
#Python program to find Minimum Number of Vertices to Reach All Nodes

class Solution:
    def findSmallestSetOfVertices(self, n: int, edges: List[List[int]]) -> List[int]:
        # return the answer
        return set(range(n)).difference({n2 for n1, n2 in edges})

