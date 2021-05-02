/* Program to find minimum distance (hackerrank problem solution) */

#include<stdio.h>
#include<stdlib.h>
//function to find minimum distance
int minimumDistances(int a_count, int* a) {
int min=100000,distance=10000;
int i,j,p=0;
for(i=0;i<a_count-1;i++)
{
     distance=100000;
    for(j=i+1;j<a_count;j++)
    {
        if(a[i]==a[j])
    {
        p++;
        distance=j-i;
        break;
    }
    }
    if(distance<min){
    min=distance;
    }

}
if(p==0)
return -1;
else
return min;
}
//driver code
int main()
{
    int size,*a,i,res;
    printf("Enter size: ");
    // taking size of array
    scanf("%d",&size);
    //dynamically allocation array
    a=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
        scanf("%d",&a[i]);
    res=minimumDistances(size,a);
    printf("Minimum distance: %d",res);
    return 0;

}
/*
Input: Enter size: 5
       1 2 3 1 4
Output: Minimum distance: 3

Time complexity: O(N^2)
*/
