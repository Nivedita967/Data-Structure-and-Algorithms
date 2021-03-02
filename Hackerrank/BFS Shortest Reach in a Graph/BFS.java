import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    //Graph class
    public static class Graph {

        //storing graph in adjacency list
        List<List<Integer>> adjLst; 
        int size;

        //creating the graph constructor
        public Graph(int size) {
            adjLst = new ArrayList<>();
            this.size = size;
            while(size-- > 0)//Initialize the adjancency list.
                adjLst.add(new ArrayList<Integer>());
        }

        //addedge funciton to add edges to the graph
        public void addEdge(int first, int second) {
            adjLst.get(first).add(second);
            adjLst.get(second).add(first); 
        // For undirected graph, you need to add edges from both sides.
        }
        
        public int[] shortestReach(int startId) { // 0 indexed
            int[] distances = new int[size];
            Arrays.fill(distances, -1); // O(n) space.

            //initialising a queue to implement FIFO order
            Queue<Integer> que = new LinkedList<>();
            
            que.add(startId); // Initialize queue.
            distances[startId] = 0;

            //basically visited marking hashmap
            HashSet<Integer> seen = new HashSet<>(); //O(n) space. Could be further optimized. I leave it to you to optimize it.
            
            seen.add(startId);
            while(!que.isEmpty()) { // Standard BFS loop.
                Integer curr = que.poll();
                for(int node : adjLst.get(curr)) {
                    if(!seen.contains(node)) {
                        que.offer(node);
            // Right place to add the visited set.
                        seen.add(node); 
            // keep on increasing distance level by level.
                        distances[node] = distances[curr] + 6; 
                    }
                }
            }   

            //returning distance array
            return distances;
        }
    }
    //driver function 
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
      
        int queries = scanner.nextInt();
        
        for (int t = 0; t < queries; t++) {
            
            // Create a graph of size n where each edge weight is 6:
            Graph graph = new Graph(scanner.nextInt());
            int m = scanner.nextInt();
            
            // read and set edges
            for (int i = 0; i < m; i++) {
                int u = scanner.nextInt() - 1;
                int v = scanner.nextInt() - 1;
                
                // add each edge to the graph
                graph.addEdge(u, v);
            }
            
            // Find shortest reach from node s
            int startId = scanner.nextInt() - 1;
            int[] distances = graph.shortestReach(startId);
 
            for (int i = 0; i < distances.length; i++) {
                if (i != startId) {
                    System.out.print(distances[i]);
                    System.out.print(" ");
                }
            }
            System.out.println();            
        }
        
        scanner.close();
    }
}