#include <iostream>
#include <unordered_map>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <climits>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<vector<bool>> vvb;

// * ALGORITHM =>
// * In this question we need to find the max number of connected filled cells (filled cells : 1)
// * To do this question we use Depth First Search or DFS, which is a linear time O(V + E) graph traversing algorithm.
// * We traverse the matrix array, and for every '1' which is not visited, we call the function 'dfs' over it to find the size of largest region in the matrix.
// * The 'dfs' function calls dfs on every other adjacent cell which is not visited and has a value of '1'.
// * For every cell which we find with this algorithm, we return 1 to the parent function.
// * So after the completion of the function we will have the size of a region and then we just compare it with the value stored in the max_size variable and assign this value to max_size if the returned value is greater than previous max_size value.

// * 'dfs' function to find out the size of a region in the matrix
int dfs(int r, int c, int i, int j, vvi &matrix, vvb &visited)
{
    if (i >= r || i < 0 || j >= c || j < 0 || visited[i][j] == true || matrix[i][j] == 0)
    {
        return 0;
    }
    visited[i][j] = true;
    return 1 + dfs(r, c, i - 1, j, matrix, visited) + dfs(r, c, i - 1, j + 1, matrix, visited) + dfs(r, c, i, j + 1, matrix, visited) + dfs(r, c, i + 1, j + 1, matrix, visited) + dfs(r, c, i + 1, j, matrix, visited) + dfs(r, c, i + 1, j - 1, matrix, visited) + dfs(r, c, i, j - 1, matrix, visited) + dfs(r, c, i - 1, j - 1, matrix, visited);
}

// * Driver Code =>
int main()
{
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c;
    cin >> r >> c;
    vvi matrix(r, vi(c));
    vvb visited(r, vb(c, 0));

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> matrix[i][j];
        }
    }

    int max_size = 0;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (matrix[i][j] == 1 && !visited[i][j])
            {
                max_size = max(max_size, dfs(r, c, i, j, matrix, visited));
            }
        }
    }
    cout << max_size << '\n';
}