#include <bits/stdc++.h>
using namespace std;
int main(){
    int k,n,x;
    cin>>n>>k; //take inputs
    int a[n],i,j,ans=0;
    for(i=0;i<n;i++) cin>>a[i]; //take array input
    i=0;
    while(i<n){ //iterate through array
        ans++;
        j=min(n-1,i+k-1); //sort through the minimum
        while(i-k+1<=j && a[j]==0) j--;
        if(j<i-k+1){
            cout<<-1; //print -1 indicating not possible
            return 0;
        }
        else i=j+k;
    }
    cout<<ans; //print answer
}
0|