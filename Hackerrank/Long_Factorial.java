static void extraLongFactorials(int n) {
    int []arr=new int[10000];
    arr[0]=1;
    int result_size=1;
    for(int i=2;i<=n;i++)
    {
        int carry=0;
        for(int j=0;j<result_size;j++)
        {
            int product=(arr[j]*i+carry);
            arr[j]=product%10;
            carry=product/10;
        }
        while(carry!=0)
        {
            arr[result_size]=carry%10;
            carry/=10;
            result_size++;
        }
    }
    for(int i=result_size-1;i>=0;i--)
    {
        System.out.print(arr[i]);
    }


    }
