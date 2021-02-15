 static void extraLongFactorials(int n) {

    int []arr=new int[10000];//resultant array
    arr[0]=1;
    int result_size=1;
    for(int i=2;i<=n;i++)// iteration from 2 to n , where n is the number of which you want to calculate factorial
    {
    // by default for each iteration the carry should be 0
        int carry=0;
        for(int j=0;j<result_size;j++)
        {
            int product=(arr[j]*i+carry);
            arr[j]=product%10;
            carry=product/10;
        }
        // fill the carry in the last of resultant array and increase the size of result_size
        while(carry!=0)
        {
            arr[result_size]=carry%10;
            carry/=10;
            result_size++;
        }
    }
    //print the required resultant array in reverse order
    for(int i=result_size-1;i>=0;i--)
    {
        System.out.print(arr[i]);
    }

    }
