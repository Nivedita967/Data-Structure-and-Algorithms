int hourglassSum(int arr_rows, int arr_columns, int** arr) 
{
    int max = INT_MIN;
    for(int i=0; i< arr_columns-2;i++) //taking 2 less as in sum we are increasing 2
    {
        for(int j=0; j< arr_rows-2; j++) //taking 2 less as in sum we are increasing 2
        {
            int sum = arr[i][j]+arr[i][j+1]+arr[i][j+2]+arr[i+1][j+1]+arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2]; //taking hourglass shape
            if(sum>max)
                max=sum;
        }
    }
    return max;
}
