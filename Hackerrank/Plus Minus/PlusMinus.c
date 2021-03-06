void plusMinus(int arr_count, int* arr) 
{
    double p=0,n=0,z=0;
    for(int i=0; i<arr_count; i++) //Checking each element of array
    {
        if(arr[i]==0)
        z++;
        else if(arr[i]>0)
        p++;
        else
        n++;
    }
    printf("%.6f\n", (p/arr_count));
    printf("%.6f\n", (n/arr_count));
    printf("%.6f", (z/arr_count));
}
