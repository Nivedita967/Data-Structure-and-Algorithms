#include <stdio.h>  
 
// Returns count of different partitions of n
// elements in k subsets
int countP(int n, int k)
{
  // Base cases
  if (n == 0 || k == 0 || k > n)
     return 0;
  if (k == 1 || k == n)
      return 1;
 
  //recursively get the subsets
  return  k*countP(n-1, k) + countP(n-1, k-1);
}
 
int main()
{
    int n, k;
    //take inputs
    scanf("%d", &n);
    scanf("%d", &k);
    //print output
    printf("%d", countP(n, k));
    return 0;
}