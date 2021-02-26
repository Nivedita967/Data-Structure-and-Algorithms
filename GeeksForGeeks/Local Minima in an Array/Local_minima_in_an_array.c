#include<stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[100000];
    for(int i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }

    int idx=-1;
    if(n==1){
        idx=0;
    }
    else if(arr[1]>=arr[0]){
        idx=0;
    }
    else if(arr[n-2]>=arr[n-1]){
        idx=n-1;
    }
    else{
        for(int i=1;i<n-1;i++){
            if(arr[i-1]>= arr[i] && arr[i+1]>=arr[i]){
                idx=i;
                break;
            }
        }
    }
    printf("%d", idx);
}