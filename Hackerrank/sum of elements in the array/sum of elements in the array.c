#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

int a[1000];
    int i, n, sum=0;

       printf("");
       scanf("%d",&n);
   
       printf("");
       for(i=0;i<n;i++)
        {
          printf("");
          scanf("%d",&a[i]);
        }

    for(i=0; i<n; i++)
    {
        sum += a[i];
    }

    printf("%d", sum);
}