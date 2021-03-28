// C Program for largest rectangle

#include <stdio.h>


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
   long long n,arr[100001],i,j,max,temp=-1,k,count=1,val;
    scanf("%lld",&n);
    for(i=0;i<n;i++){
        //accepting the array
        scanf("%lld",&arr[i]);
    }
    for(i=0;i<n;i++){
        val=arr[i];
      int cl1=1,cl=1;
        for(j=i-1,k=i+1;j>=0 || k<n;j--,k++){
            //checking the condition
            if(j>=0 && arr[j]>=val && cl1==1){
                count++;
            }
            //if cl1 is 0
            else cl1=0;
            if(k<n && arr[k]>=val && cl==1){
                count++;
            }
            //if cl is 0
            else cl=0;
            if(cl==0 && cl1==0)
                break;
        }
        //calculating max value
        max=val*count;
        if(max>temp){
            temp=max;
        }
        count=1;
        
    }
    //print result
    printf("%lld",temp);
    return 0;
}

