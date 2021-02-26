"""
Problem: https://www.hackerrank.com/challenges/ctci-bfs-shortest-reach/problem
"""

from collections import deque

# read amount of test cases
testCases = int(input())

# solve each test case
while testCases > 0:

    # read number of nodes and edges
    nodes, edges = map(int, input().split())

    # intialize empty undirected graph (adjacent list)
    graph = []
    for i in range(nodes):
        graph.append([])

    # read each edge and populate graph
    for i in range(edges):
        nodeOne, nodeTwo = map(int, input().split())
        graph[nodeOne - 1].append(nodeTwo - 1)
        graph[nodeTwo - 1].append(nodeOne - 1)

    # read starting node
    startNode = int(input())
    startNode -= 1

    # intialize control variables for BFS
    distance = [-1] * nodes
    visited = [False] * nodes
    toVisit = deque()

    # add node 0 to control variables
    visited[startNode] = True
    distance[startNode] = 0
    toVisit.append(startNode)

    # perform BFS
    while len(toVisit) > 0:

        # get first node from queue
        node = toVisit.popleft()

        # add each unvisited neighbor of node to queue and update control vars
        for neighbor in graph[node]:
            if visited[neighbor] == False:
                visited[neighbor] = True
                distance[neighbor] = distance[node] + 6
                toVisit.append(neighbor)

    # print answer
    first = True
    for i in range(nodes):
        if i != startNode:
            if first == True:
                print(distance[i], end = '')
                first = False
            else:
                print(' ' + str(distance[i]), end = '')
    if testCases != 1:
        print()

    # decrement ammount of test cases
    testCases -= 1
