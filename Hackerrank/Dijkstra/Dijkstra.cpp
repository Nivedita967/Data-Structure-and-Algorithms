#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>
#include<climits>
#include<utility>
using namespace std;


//this is a very famous Shortest Path Algorithm : Dijkstra
//this has been implemented using priority queue in order to keep it optimised 

class Graph{
public: 

    // this is a graph class to keep a note of all the nodes in an unordered map
    // * [vertex, {dest, weight}]

    unordered_map<int, list<pair<int, int> > > gmap; //graph map

    //adding the edges to the graph 
    void addEdge(int src, int dest, int distance){
        pair<int, int> pair_src (dest, distance);
        gmap[src].push_back(pair_src);
        pair<int, int> pair_dest (src, distance);
        gmap[dest].push_back(pair_dest);
    }

    //function for algorithm with arguments as No of vertices, no of Edges, Graph object, starting vertex
    void djikstra(int V, int E, Graph g, int start){
  
        bool *visited = new bool[V];    //array to mark all visited nodes so that no repetition 

        int *distance = new int[V];    //to keep a record of shortest distance for all nodes

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> my_set;    //to sort on the basis of minimum distance

        for(int i = 0; i < V; i++){
            if(i == start){
                distance[i] = 0;
            }
            else{
                distance[i] = INT_MAX;
            }
            visited[i] = false;
        }

        //starting vertex is pushed to priority queue
        int vtx = start;
        my_set.push(make_pair(distance[vtx], vtx));


        //loop until priority queue is not empty
        while(!my_set.empty()){
            
            //remove the front pair of distance, vertex
            pair<int, int> curr_pair =my_set.top();
            my_set.pop();

            //check if already not visited
            if(visited[curr_pair.second]){
                continue;
            }

            //mark visited if not
            visited[curr_pair.second] = true;

            //traverse on its neighbour nodes using the hashmap 
            for(auto neighbour : gmap[curr_pair.second]){

                //for not visited neighbours , relax them/ update their distance if they could be reached with a shorter distance
            if(visited[neighbour.first] == false){
                int child_vtx, distance_from_src, distance_from_vtx;
                child_vtx = neighbour.first;
                distance_from_vtx = neighbour.second;
                distance_from_src = curr_pair.first + neighbour.second;

                //if the distance was updating then they need to be pushed in priority queue with minimum distance
                    if(distance[child_vtx]> distance_from_src){
                        distance[child_vtx] = distance_from_src;
                        my_set.push(make_pair(distance[child_vtx], child_vtx));
                    }
                }
            }
        }

        //printing as the required output
        for(int i = 0; i < V ; i++){
            if(i==start){
                continue;
            }
            else if(distance[i] == INT_MAX ){
                cout << "-1 ";
            }
            else{
                cout << distance[i] << " "; 
            }
        }
    }
};


//driver function
int main(){
    std::ios::sync_with_stdio(false);
    int t;  
    cin>>t;
    for(int j=0;j<t;j++){
        Graph g;
        int V, E, u, v, d;
        cin >> V >> E;
        for(int i = 0; i < E; i++){
            cin >> u >> v >> d;
            g.addEdge(u-1, v-1, d);
        }
        int start;
        cin>>start;
        start=start-1;
        g.djikstra(V, E, g, start);
        cout<<"\n";
    }
    return 0;
}
