#include<stdio.h>
#include<string.h>
int dp[5001][5001];
int main()
{
    //declaration and inputs
    char st1[5001], st2[5001];
    scanf("%s", st1);
    scanf("%s", st2);
    
    //taking sizes of strings
    int m = strlen(st1), n = strlen(st2), i, j;
    
    //loop for finding the length of longest common string which is the child of input strings
    for(i=1;i<=m;i++)
    {    for(j=1;j<=n;j++)
        {  
              if(st1[i-1] == st2[j-1])
            {    dp[i][j] = dp[i-1][j-1] + 1;}
            else
             {   dp[i][j] = dp[i][j-1] > dp[i-1][j] ? dp[i][j-1] : dp[i-1][j];}
        }
    }
    
    //printing the length of longest common string
    printf("%d", dp[m][n]);
    return 0;
}