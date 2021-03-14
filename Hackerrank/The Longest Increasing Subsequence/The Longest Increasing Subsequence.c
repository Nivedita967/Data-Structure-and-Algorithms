// A program to find The Longest Increasing Subsequence


#include <stdio.h>

// Declaring global variables
int n,a[1000000],b[1000000]; 

// Counting length of all the correct elements in right of the current element 
int getRight(int *Arr,int left,int right,int value)
{
    int mid;
    while(right>left+1)
    {
        mid=left+(right-left)/2;
        if(Arr[mid]>=value)right=mid;
        else left=mid;
    }
    return right;
}
 

// Calculating length of subsequent arrays
int CalcLIS()
{
    int i,res=1;
    b[0]=a[0];
    for(i=1;i<n;i++)
    {
        if(a[i]<b[0])
            b[0]=a[i];
        else if(a[i]>b[res-1])
            b[res++]=a[i];
        else
            b[getRight(b,-1,res-1,a[i])]=a[i];
    }
    return res;
}
 
int main()
{
    int i;
    // Getting user input number of test cases 
    scanf("%d",&n);
  
    // Getting the test cases
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    
    // Printing result
    printf("%d",CalcLIS());
    return 0;
}
