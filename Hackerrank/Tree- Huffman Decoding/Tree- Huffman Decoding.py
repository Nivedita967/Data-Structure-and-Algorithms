#Problem:https://www.hackerrank.com/challenges/tree-huffman-decoding/problem
import queue
def decodeHuff(root, s):
    current = root
    result = []

    for char in s:
        #traverse the tree
        if char is '1':
            current = current.right
        else:
            current = current.left
        #if we are at a character node, reset traversal and append current character to result
        if current.left is None and current.right is None:
            result.append(current.data)
            current = root
    print(''.join(result))
    return ''.join(result)

