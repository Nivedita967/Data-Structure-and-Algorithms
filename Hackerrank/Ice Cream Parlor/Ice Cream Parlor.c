//NOTE: took my own i/o

#include<stdio.h>
int main()
{
    int t,c,l,i,j,arr[20000];
    for(scanf("%d",&t);t>0;t--) //take input
    {
        scanf("%d%d",&c,&l);
        for(i=0;i<l;i++)  //iterate through array to take array value inputs
        scanf("%d",&arr[i]);
        for(i=0;i<l-1;i++) //iterate through array inner and outer, O(n^2)
        for(j=i+1;j<l;j++)
        {
            if(arr[i]+arr[j]==c)   //if sum found i.e sum of two ice creams is the money they have
            printf("%d %d\n",i+1,j+1);
        }
    }
    return 0;
}