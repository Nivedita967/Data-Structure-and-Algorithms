
// C program to find Minimum Insertion Steps to Make a String Palindrome
// Using dynamic programming approach
#include <stdio.h>
#include <string.h>
 
// A utility function to find minimum of two integers
int min(int a, int b)
{   return a < b ? a : b;  }
 
// A DP function to find minimum number of insertions
int findMinInsertions(char str[], int n)
{
    // Create a table of size n*n. table[i][j]
    int table[n][n], l, h, gap;
 
    // Initialize all table entries as 0
    memset(table, 0, sizeof(table));
 
    // Fill the table
    for (gap = 1; gap < n; ++gap)
        for (l = 0, h = gap; h < n; ++l, ++h)
            table[l][h] = (str[l] == str[h])?
                          table[l+1][h-1] :
                          (min(table[l][h-1], 
                           table[l+1][h]) + 1);
 
    // Return minimum number of insertions for
    return table[0][n-1];
}
 
// Driver program to test above function.
int main()
{
    char str[50];
    scanf("%s",str);
    printf("%d", findMinInsertions(str, strlen(str)));
    return 0;
}

