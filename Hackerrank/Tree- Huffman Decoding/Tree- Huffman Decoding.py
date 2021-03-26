from heapq import heappop, heappush, heapify


class HuffmanTreeNode:
    def __init__(self, data, left=None, right=None):
        self.data = data
        self.left = left
        self.right = right


def DFS(root, node_char):
    answer = {}

    def inOrder(root, s):
        if not root.left and not root.right:
            answer[node_char[root][1]] = s

        if root.left:
            inOrder(root.left, s + '0')

        if root.right:
            inOrder(root.right, s + '1')

    inOrder(root, '')
    return answer


def huffman(freq, char):
    # encoding
    n = len(freq)
    freq_char = [(freq[i], char[i]) for i in range(n)]
    heapify(freq_char)
    node_char = {}
    for i in range(n):
        freq[i] = freq_char[i][0], HuffmanTreeNode(freq_char[i][0])
        node_char[freq[i][1]] = freq_char[i][0], freq_char[i][1]

    while len(freq) > 1:
        f1, node1 = heappop(freq)
        f2, node2 = heappop(freq)

        node = HuffmanTreeNode(f2 + f1, node1, node2)
        f = f1 + f2

        heappush(freq, (f, node))

    # decoding
    f, root = freq.pop()
    answer = DFS(root, node_char)
    return answer


print(huffman([5, 9, 12, 13, 16, 45], ['a', 'b', 'c', 'd', 'e', 'f']))
