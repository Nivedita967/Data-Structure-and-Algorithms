// Complete the maxSubsetSum function below.
int dp[100005];

//function for returning maximum element
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}

//function for retruning max array sum
int maxSubsetSum(int arr_count, int* arr) 
{
    //assigning maximum value to dp[0]
    dp[0]=max(0,arr[0]);

    //if there is only one element
    if(arr_count==1)
        {return dp[0];}

    //loop for finding array sum and storing it into dp    
    for(int i=1;i<arr_count;i++)
    {
        dp[i]=max(dp[i-2],max(dp[i-1],dp[i-2]+arr[i]));
    }

    //declaring and initialising n to total no. of elements
    int n=arr_count;

    //returning max array sum
    return max(dp[n-1],dp[n-2]);

}