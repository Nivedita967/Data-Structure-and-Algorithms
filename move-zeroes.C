#include <stdio.h>
#include <stdlib.h>
void moveZeroes(int* nums, int numsSize)// function to move Zeroes
{
  int i,j=numsSize-1,*k,l=0;           // declrared variables
    k=(int*)malloc(numsSize*sizeof(int)); // dynamic memory allocation
    for(i=0;i<numsSize;i++)
    {
        if(nums[i]!=0)              // check the specific number is Zero or not
        {
            k[l++]=nums[i];

        }
         if(nums[i]==0)            // continue if number is zero
        {
            k[j--]=nums[i];
        }
    }
    for(i=0;i<numsSize;i++)   // change the array
    {
        nums[i]=k[i];
    }

}
int main()
{
    int arr[10],a,b,i;
    printf("enter the size ");  // ask the size of array
    scanf("\n%d",&a);           // take input from the user
    for(b=0;b<a;b++)
    {
        scanf("%d",&arr[b]);  // input from the user
    }
    moveZeroes(arr,a);   // function call
    for(i=0;i<a;i++)
        printf("%d",arr[i]);  // print the output
}
