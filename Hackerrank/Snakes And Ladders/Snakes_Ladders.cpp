#include <bits/stdc++.h>

using namespace std;

// Complete the quickestWayUp function below.
int quickestWayUp(vector<vector<int>> ladders, vector<vector<int>> snakes) {
    vector<int>distance(101, 0);
        for(int i=0;i<ladders.size();i++){
            distance[ladders[i][0]]+=(ladders[i][1]-ladders[i][0]);
        }
        for(int i=0;i<snakes.size();i++){
            distance[snakes[i][0]]+=(snakes[i][1]- snakes[i][0]);
        }
        int count=0;
        queue<int>que;
        que.push(1);
        vector<int>moves(101,INT_MAX);
        bool res=false;
        moves[1]=0;
        for(int i=2;i<7;i++){
            moves[i+distance[i]]=1;
        }
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
        if(!res){
            return -1;
        }
        return moves[100];
}

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
