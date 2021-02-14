
// C program to rotate the array elements to the left
#include<stdio.h>
#include<stdlib.h>

void leftrotation(int arr[],int n,int k){
    // rotating the array elements
    int b[n];
    for(int i=0;i<n;i++){
        b[((i+n)-k)%n]=arr[i];
    }
    //printing the elements
    for(int i=0;i<n;i++){
        printf("%d ",b[i]);
    }
}

int main(){

    // user input
    int n,k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for(int i=0;i<n;i++)
      scanf("%d",&arr[i]);\
      
    leftrotation(arr,n,k);
}

