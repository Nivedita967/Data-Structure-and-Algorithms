#include <bits/stdc++.h>
using namespace std;

//defining auto to specify the type of the variable
auto op = [](auto& x, auto& y, char c) { x = (c -'A')/6; y = (c-'A')%6; };
class Solution {
public:
    
   //declaration for dp array 
   int dp[301][301];    
    int minimumDistance(string word) 
    {
        //setting values
        memset(dp, 0, sizeof(dp));
        
        //Finding the length of given word
        word.insert(0, 1,'0');
        
        //declaring required variables
        int x1, y1, x2, y2, x3, y3;
        
        //loop for finding characters
        for (int i=word.length()-2; i>=0; i--)
        {
            op(x1,y1,word[i]); 
            op(x3,y3,word[i+1]);
            
            //loop for finding maximum of current value and difference of the distance
            for (int j=i-1; j>=0; j--)
            {
                op(x2,y2,word[j]);
                int d1 = word[i] != '0' ? abs(x1-x3) + abs(y1-y3) : 0;
                int d2 = word[j] != '0' ? abs(x2-x3) + abs(y2-y3) : 0;
                dp[i][j] = min(dp[i+1][j] + d1,
                               dp[i][i+1] + d2);
                dp[j][i] = dp[i][j];
            }
        }
        
        //returning minimum distance
        return dp[1][0];
    }
};