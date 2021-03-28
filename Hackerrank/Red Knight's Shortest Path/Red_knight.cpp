#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// * ALGORITHM ==>
// * In this algorithm , we can use Breadth First Search in order to travel the chess board
// * We maintain certain values at each instance :
// * Value 1: direction array (to determine all possible directions)
// * Value 2: visited array (to keep a track of all visited nodes)
// * Value 3: Parent of each vertex that is pushed into the queue
// * Value 4: bool flag to check if the destination is arrived
// * Value 5: distance of src to current node

// * struct to keep a pair as a key ; this generates the hash value .
struct hash_pair
{
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2> &p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        return hash1 ^ hash2;
    }
};

// Complete the printShortestPath function below
void printShortestPath(int n, int i_start, int j_start, int i_end, int j_end)
{

    vector<string> result;

    // * Values explained above are maintained here
    // * For start cell, all the values will be marked true
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    visited[i_start][j_start] = true;
    unordered_map<pair<int, int>, string, hash_pair> parent;
    parent[make_pair(i_start, j_start)] = "";

    // * Queue in order to implement breadth first search algorithm
    queue<pair<int, int>> pq;
    int count = 0;
    int size = 1;
    vector<vector<int>> dir = {{-2, -1}, {-2, 1}, {0, 2}, {2, 1}, {2, -1}, {0, -2}};
    vector<string> directions = {"UL", "UR", "R", "LR", "LL", "L"};
    pq.push(make_pair(i_start, j_start));
    bool flag = false;

    // * Until the size of the queue becomes 0 or the destination is arrived
    while (pq.size() != 0)
    {
        pair<int, int> top = pq.front();
        pq.pop();
        int x = top.first;
        int y = top.second;
        if (x == i_end && y == j_end)
        {
            flag = true;
            break;
        }
        for (int i = 0; i < dir.size(); i++)
        {
            int newx = x + dir[i][0];
            int newy = y + dir[i][1];

            // * if the new cell is good to be added in our queue, push it
            if (newx >= 0 && newy >= 0 && newx < n && newy < n && !visited[newx][newy])
            {
                pq.push(make_pair(newx, newy));
                parent[make_pair(newx, newy)] = parent[make_pair(x, y)] + " " + directions[i];
                visited[newx][newy] = true;
            }
        }

        // * this is used to calculate distance of src to destination
        size--;
        if (size == 0)
        {
            count++;
            size = pq.size();
        }
    }

    // * Print the distance along with the sequence of moves.
    if (!flag)
    {
        cout << "Impossible";
    }
    else
    {
        cout << count << endl
             << parent[make_pair(i_end, j_end)].substr(1);
    }
}

// * Driver code
int main()
{
    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string i_startJ_start_temp;
    getline(cin, i_startJ_start_temp);

    vector<string> i_startJ_start = split_string(i_startJ_start_temp);

    int i_start = stoi(i_startJ_start[0]);

    int j_start = stoi(i_startJ_start[1]);

    int i_end = stoi(i_startJ_start[2]);

    int j_end = stoi(i_startJ_start[3]);

    printShortestPath(n, i_start, j_start, i_end, j_end);

    return 0;
}

vector<string> split_string(string input_string)
{
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ')
    {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos)
    {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
