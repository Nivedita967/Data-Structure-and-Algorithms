
//Returns length of LCS for X[0..m-1], Y[0..n-1] 
int lcs( char *X, char *Y, int m, int n )
{
   int l[m+1][n+1];
   
   //steps building l[m+1][n+1] in bottom up fashion.
   for (int i=0; i<=m; i++)
   {
     for (int j=0; j<=n; j++)
     {
       if (i == 0 || j == 0)
         l[i][j] = 0;
   
       else if (X[i-1] == Y[j-1])
         l[i][j] = l[i-1][j-1] + 1;
   
       else
         l[i][j] = max(l[i-1][j], l[i][j-1]);
     }
   }
     
   //returning longest common subsequence
   return l[m][n];
}
   