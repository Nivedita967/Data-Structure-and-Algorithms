//  Given an array of integers arr and an integer d. In one step you can jump from index i to index:

// i + x where: i + x < arr.length and 0 < x <= d.
// i - x where: i - x >= 0 and 0 < x <= d.
// In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).

// You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.

    //declaration of global variables
    int n;
    int** a;
    int dp[1001]={0};

// for finding the max among two
    int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
    
// for finding the max among two
    int min(int num1, int num2)
{
    return (num1 > num2 ) ? num2 : num1;
}
    //function
    int jumps(int i,int d)
    {
        //checking the condition  
        if(dp[i]!=0)
        {   return dp[i]; }
        
        //declaration of variables
        int res=1;
        int curr=a[i];
        
        //loops for finding the indices 
        for(int j=i+1;j<=min(n-1,i+d);j++)
        {
            if(a[j]<curr)
            {
                res=max(res,1+jumps(j,d));
            }
            else
                break;
        } 
        for(int j=i-1;j>=max(0,i-d);j--)
        {
            if(a[j]<curr)
            {
                res=max(res,1+jumps(j,d));
            }
            else
                break;
        }
        
        //returning variables
        return dp[i]=res;
    }
    
    //function 
    int maxJumps(int** arr, int size, int d) 
    {
        //declaration of variables
        a=arr;
        n=size;
        int res=0;
        
        //loop for finding maximum 
        for(int i=0;i<n;i++)
        { res=max(res,jumps(i,d));}
        
        //returning maximum number of indices 
        return res;
    }
