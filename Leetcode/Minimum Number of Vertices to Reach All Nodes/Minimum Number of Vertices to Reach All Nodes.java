/*
Given a directed acyclic graph, with n vertices numbered from 0 to n-1, and an array edges where edges[i] = [fromi, toi] represents
 a directed edge from node fromi to node toi.
Find the smallest set of vertices from which all nodes in the graph are reachable. It's guaranteed that a unique solution exists.
Notice that you can return the vertices in any order.

*/
public List<Integer> findSmallestSetOfVertices(int n, List<List<Integer>> edges) {
    List<Integer> res = new ArrayList<>();
    /*
All nodes with no in-degree must in the final result, because they can not be reached from
All other nodes can be reached from any other nodes.
    */

    // seen array would keep track of visited nodes.
    int[] seen = new int[n];
    for (List<Integer> e: edges)
        seen[e.get(1)] = 1;
    for (int i = 0; i < n; ++i)
    // if seen == 0 then in-degree of node is 0. so add it to the result
        if (seen[i] == 0)
            res.add(i);
    // return the res list
    return res;
}