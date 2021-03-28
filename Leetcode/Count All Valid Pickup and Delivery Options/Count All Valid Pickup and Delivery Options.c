
//C program for Counting All Valid Pickup and Delivery Options

int countOrders(int n){
    //initialize m to 1e9+7
  int m=1e9+7;
        int prev=1;
        for(long long i=2;i<=n;i++)
        {
            //calculate x 
            int x=(((i%m)*(2*i-1)%m)%m*(prev%m))%m;
            //store x in prev
            prev=x;
        }
        //return answer
        return prev;
}
