#include<stdio.h>

int main(){

    //taking input
    int n;
    scanf("%d", &n);
    int arr[100000];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    //storing index
    int idx=-1;

    //if size of array is only 1 then return idx 0
    if(n==1){
        idx=0;
    }

    //if first index is local minima
    else if(arr[1]>=arr[0]){
        idx=0;
    }

    //if last index is local minima
    else if(arr[n-2]>=arr[n-1]){
        idx=n-1;
    }

    //if local minima lies between 1 to n
    else{
        for(int i=1;i<n-1;i++){
            if(arr[i-1]>= arr[i] && arr[i+1]>=arr[i]){
                idx=i;
                break;
            }
        }
    }

    //printing local minima
    printf("%d", idx);
}