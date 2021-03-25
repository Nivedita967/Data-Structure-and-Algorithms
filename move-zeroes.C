#include <stdio.h>
#include <stdlib.h>
void movezeroe(int* arr,int a)
{
    int i,j,k;
    for(i=0;i<a;i++)
    {
        if(arr[i]==0)
        {
        for(j=i;j<a;j++)
        {
            k=arr[j+1];
            arr[j+1]=arr[j];
            arr[j]=k;
        }
    }
    }
    for(j=0;j<a;j++)
    {
        printf("%d",arr[j]);
    }
}


void moveZeroes(int* nums, int numsSize)
{
  int i,j=numsSize-1,*k,l=0;
    k=(int*)malloc(numsSize*sizeof(int));
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)
        {
            k[l++]=nums[i];

        }
         if(nums[i]==0)
        {
            k[j--]=nums[i];
        }
    }
    for(i=0;i<numsSize;i++)
    {
        nums[i]=k[i];
    }

}
int main()
{
    int arr[10],a,b,i;
    printf("enter the size ");
    scanf("\n%d",&a);
    for(b=0;b<a;b++)
    {
        scanf("%d",&arr[b]);
    }
    moveZeroes(arr,a);
    for(i=0;i<a;i++)
        printf("%d",arr[i]);
}