#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;


// * ALGORITHM =>
// * Prim's Algorithm is used to find the minimum spanning tree or (MST) of a graph. MST is a subgraph in which all the nodes present in the actual graph are there and the total weight of the graph is minimum.
// * Also MST has 2 properties. If the number of nodes in a graph is 'N', then the number of edges in it's MST will be 'N - 1'. Also an MST do not contain any cycle.

// * In this algorithm we maintain a minimum priority queue (PQ) which stores a pair of integer. The first value corresponds to the weight of the edge between the node and it's neighbour. And the second value represents the node itself.
// * Also we maintain a boolean visited array to track the nodes which become the part of MST and a weight array which tracks the minimum weight assigned to each node.
// * We assign the weight of source node as 0 and ∞ to all the other nodes.
// * We push the source node inside PQ.
// * Then we continue the algorithm until the PQ becomes empty.
// * We extract the pair which lies at the top of PQ and then mark it visited.
// * Then we travel the adjacency list of the node who's pair we extracted out.
// * If the node's neighbour is unvisited and weight of this neighbour is less than the weight of neighbour's weight stored at the index of neighbour inside the weight array, then we update the weight array with the new weight and make a pair/instance of this node and it's weight and push it in the PQ.
// * There can be multiple instances of same node with different weight inside the PQ, because the weight of the node can be updated many times in weight array.
// * The number of instances or pair for a node inside the PQ depends on how many times we update the weight array for that corresponding node.
// * But as the PQ is of minimum type, only the weight with minimum value will come out first.
// * The rest of the instances can be ignored using the keyword 'continue' inside a conditional statement checking for the visited status of the node. If the node is visited, we just continue to next pair.
// * At the end of the loop (After PQ becomes empty), we sum up the values stored in the weight array to get the total weight for the MST.




// * Graph class generated using Adjacency list
class Graph{
    unordered_map<int, list<pi> > gmap;


// * addEdge function to add edges to the graph
public:
    void addEdge(int src, int dest, int weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }


// * Prims function to solve for MST
    int prims(int V, int E, int src){
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vb visited(V, false);
        vi weight(V, INT_MAX);
        int total_weight = 0;
        weight[src] = 0;
        pq.push(mp(weight[src], src));
        while(!pq.empty()){
            pi top = pq.top();
            pq.pop();
            if(visited[top.second]){
                continue;
            }
            visited[top.second] = true;
            for(auto neighbour : gmap[top.second]){
                if(!visited[neighbour.first]){
                    int node = neighbour.first;
                    int weight_of_node = neighbour.second;
                    if(weight[node] > weight_of_node){
                        pq.push(mp(weight_of_node, node));
                        weight[node] = weight_of_node;
                    }
                }
            }
        }


// * Summing up the total weight of MST        
       for(int i = 0; i < V; i++){
           total_weight += weight[i];
       } 
      return total_weight; 
    }
};



// * Driver Code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Graph g;
    int V, E, u, v, w, src;
    cin >> V >> E;
    for(int i = 0; i < E; i++){
        cin >> u >> v >> w;
        g.addEdge(u - 1, v - 1, w);
    }
    cin >> src;
    int mst_weight = g.prims(V, E, src - 1);
    cout << mst_weight << '\n';
}