
//C Program to Count the number of ways to tile the floor of 
//size n x m using 1 x m size tiles

int main(){
    int t,i,m,n,count[100001];
    //number of inputs
    scanf("%d",&t);
    
    while(t--){
        //accepting the inputs
        scanf("%d %d",&n,&m);
        
        count[0]=0;
        
        for(i=1;i<=n;i++){
            //if i<m then store ! in count
            if(i<m)
            count[i]=1;
            else if(i>m)
           {
               //if i>m then modulus with 1000000007
                count[i]=count[i-1]+count[i-m];
                count[i]%=1000000007;
           }
            else count[i]=2;
        }
        //print the result
        printf("%d\n",count[n]);
        }
    
    
    return 0;
}

