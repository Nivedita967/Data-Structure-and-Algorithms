#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {

    //distance array to keep an account of the smallest distance for each cell of the board.  
    vector<int>distance(101, 0);
        for(int i=0;i<ladders.size();i++){
            distance[ladders[i][0]]+=(ladders[i][1]-ladders[i][0]);
        }
        for(int i=0;i<snakes.size();i++){
            distance[snakes[i][0]]+=(snakes[i][1]- snakes[i][0]);
        }

        //queue is used as a data structures for solving it using breadth first search algorithm.
        queue<int>que;
        que.push(1);

        //moves array in order to maintain the jump of the ladder or difference of the snake at each cell. 
        vector<int>moves(101,INT_MAX);
        bool res=false; //to know if we could travel till 100th position or not. 
        moves[1]=0;
        for(int i=2;i<7;i++){
            moves[i+distance[i]]=1;
        }

        //Breadth First Search Algorithm implemented !!!
        while(que.size()!=0){

            int rn=que.front();
            que.pop();
            if(rn==100){
                res=true;
                break;
            }

            for(int i=1;i<=6;i++){
                int x=rn+i;
                x=x+ distance[x];
                if(x<=100 && x>=1){
                    if(moves[x]>=moves[rn]+1){
                        moves[x]=moves[rn]+1;
                        que.push(x);
                    }
                }
            }
        }

        //if there is no way till 100th position, then returning -1
        if(!res){
            return -1;
        }

        //if there exists a path then returning the quickest possible path stored in moves array.
        return moves[100];
}

//driver function as given on hackerrank platform.

int main()
{
    std::ios_base::sync_with_stdio(false);
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> ladders(n);
        for (int i = 0; i < n; i++) {
            ladders[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> ladders[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int m;
        cin >> m;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        vector<vector<int>> snakes(m);
        for (int i = 0; i < m; i++) {
            snakes[i].resize(2);

            for (int j = 0; j < 2; j++) {
                cin >> snakes[i][j];
            }

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        int result = quickestWayUp(ladders, snakes);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
