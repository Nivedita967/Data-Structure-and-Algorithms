
import operator

# finding union
class UnionFind:

    def __init__(self, N):
        self.P = [i for i in range(N + 1)]

    def find(self, V):
        while V != self.P[V]:
            V = self.P[V]
        return V

    def connected(self, P, Q):
        return self.find(P) == self.find(Q)

    def union(self, P, Q):
        PP = self.find(P)
        QP = self.find(Q)
        self.P[PP] = QP


def kruskal(S, N, E):
    uf = UnionFind(N)                                # Calculating result
    T  = []

    for e in sorted(E, key = operator.itemgetter(0, 1)):
        if not uf.connected(e[2], e[3]):
            uf.union(e[2], e[3])
            T.append((e[2], e[3], e[0]))

    return T                                         # Returning result 


def main():
    N, M = [int(i) for i in input().split()]         # Taking input

    E    = []

    for _ in range(M):
        e = [int(i) for i in input().split()]
        E.append((e[2], e[0] + e[1] + e[2], e[0], e[1]))
        E.append((e[2], e[0] + e[1] + e[2], e[1], e[0]))

    S    = int(input())

    print(sum(t[2] for t in kruskal(S, N, E)))

# main function
if __name__ == "__main__":
    main()
