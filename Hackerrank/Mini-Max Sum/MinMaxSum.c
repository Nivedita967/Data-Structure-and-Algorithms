void miniMaxSum(int arr_count, int* arr)
{
    long long unsigned int min=arr[0], max=arr[0], sum=arr[0]; //It was givrn in problem to use more than 32bit Int
    for(int i=1; i<arr_count; i++)
    {
        sum += arr[i];
        if(arr[i]>max)
            max = arr[i];
        else if(arr[i]<min)
            min = arr[i];
    }
    printf("%d %d",sum-max, sum-min); //Max sum = All - Min, Min sum = All - Max
}
