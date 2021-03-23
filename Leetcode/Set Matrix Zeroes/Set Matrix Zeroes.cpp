#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void setZeroes(vector<vector<int>> &matrix)
  {
    // This is the Optimal Approach using O(m*n) time and O(1) Space
    int r = matrix.size();
    int c = matrix[0].size();

    // We use separate variables to track whether
    // 1st row and 1st column have to be made 0
    bool firstRow = 1;
    bool firstCol = 1;

    // We use the 1st cell

    // If any cell in the 1st R or C is a zero then the 1st R or C
    // have to be made 0 respectively
    for (int i = 0; i < c; ++i)
      if (matrix[0][i] == 0)
        firstRow = 0;
    for (int i = 0; i < r; ++i)
      if (matrix[i][0] == 0)
        firstCol = 0;

    // For keeping track of all other Rs and Cs we use the 1st cell of each
    // R & C to keep track whether those R and C need to be made 0
    // Since we are using the 1st R & C to store this info, thats why we had
    // to keep separate variables to know whether 1st R & C have to be made 0
    for (int i = 0; i < r; ++i)
    {
      for (int j = 0; j < c; ++j)
      {
        if (matrix[i][j] == 0)
        {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    // Traverse through the 1st row and make whole columns 0 where we find a 0
    //       ↓     ↓
    //
    // | -  1  0  2  0  | <-
    // |       0     0  |
    // |       0     0  |
    // |       0     0  |
    for (int i = 1; i < c; ++i)
    {
      if (matrix[0][i] == 0)
      {
        for (int j = 0; j < r; ++j)
        {
          matrix[j][i] = 0;
        }
      }
    }

    // Traverse through the 1st Col and make whole Rows 0 where we find a 0
    //   ↓
    //
    // | -             |
    // | 0  0  0  0  0 |  <-
    // | 0  0  0  0  0 |  <-
    // | 2     0     0 |
    for (int i = 1; i < r; ++i)
    {
      if (matrix[i][0] == 0)
      {
        for (int j = 0; j < c; ++j)
        {
          matrix[i][j] = 0;
        }
      }
    }

    // Make the 1st Row and Column 0s using the 1st conditional vars
    if (firstRow == 0)
      for (int i = 0; i < c; ++i)
        matrix[0][i] = 0;
    if (firstCol == 0)
      for (int i = 0; i < r; ++i)
        matrix[i][0] = 0;

    // DEBUG OUTPUT
    for (auto x : matrix)
    {
      for (auto y : x)
        cout << y << " ";
      cout << endl;
    }
  }
};