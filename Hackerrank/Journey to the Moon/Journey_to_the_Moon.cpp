#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef pair<ll, ll> pll;


// * ALGORITHM ==>

// * The easiest way to solve this problem is to visualise it as a simple questions of mathematics where the concept of            permutations and combinations come into play.
// * The questions demands that you need to find all the possible valid pairs of astronauts, when total number of astronauts is given as 'n'.
// * The only condition is that the pairs should not contain astronauts having same nationality.
// * The following approach is simple, calculating the total pairs which can be formed by 'n' astronauts, and then subtracting the pairs which have astronauts having same nationality.

/* 
To to this, firstly we need to find the total pairs of astronauts -
(n C 2), where C is the symbol for combinations. ==> Value = (n(n - 1))/2 <== This value includes the pairs of astronauts belonging to the same country as well as from different countries.
Now we need to find the find the number of astronauts belonging to the same country. For doing this we can use the concept of connected components.
*/

/* 
The following algorithm uses BFS to find the connected components. The astronauts belonging to the same connected component will also belong to the same country.So for example, if there are 'x' astronauts in a connected component, then the total pairs which can be formed will be equal to ==> [ (x * (x - 1))/2 ] <== This value here represents all the pairs which can be formed from 'x' astronauts belonging to the same country.
*/  

/*
 The only case where the question can trick a solver is when there is only 1 astronaut from a country. If there is only 1 astronaut then it is not possible to select 2 astronauts from that country. So to resolve this we just need to skip the case when the size of connected component is 1 by including a conditional statement like 'if'.
*/

// * IMPORTANT NOTE - As this question involves combinations, use datatypes such as 'long long' or 'long' to prevent integer overflow.

// * Graph class -> For generation of Graph using Adjacency List
class Graph{   
    unordered_map<int, list<pll> > gmap;

public:
    void addEdge(ll src, ll dest, ll weight, bool bidir = true){
        gmap[src].push_back(mp(dest, weight));
        if(bidir){
            gmap[dest].push_back(mp(src, weight));
        }
    }

private:
    ll valid_astronauts_pairs_helper(ll src, vb &visited){ // * Normal BFS search using queue
        queue<ll> q;
        ll count = 0;
        q.push(src);
        visited[src] = true;
        count++;
        while(!q.empty()){
            ll front = q.front();
            q.pop();
            for(auto neighbour : gmap[front]){
                if(!visited[neighbour.first]){
                    q.push(neighbour.first);
                    visited[neighbour.first] = true;
                    count++;
                }
            }
        }
        return count;
    }

public:
    ll valid_astronauts_pairs(ll astronauts, ll pairs){
        vb visited(astronauts, false);
        ll connected_astronauts, total_pairs = (astronauts * (astronauts - 1))/2;
        for(int i = 0; i < astronauts; i++){
            if(!visited[i]){
                connected_astronauts = valid_astronauts_pairs_helper(i, visited);
                if(connected_astronauts > 1){             // * Important 'if' condition to skip the useless case as mentioned above 
                    total_pairs -= (connected_astronauts * (connected_astronauts - 1))/2;
                }
            }
        }
        return total_pairs;
    }
};

//* Driver Code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    Graph g;
    ll astronauts, pairs, u, v;
    cin >> astronauts >> pairs;
    for(int i = 0; i < pairs; i++){
        cin >> u >> v;
        g.addEdge(u, v, INFI);
    }
    ll valid_pairs = g.valid_astronauts_pairs(astronauts, pairs);
    cout << valid_pairs << '\n';
}