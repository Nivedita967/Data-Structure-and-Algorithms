static void extraLongFactorials(int n) {
    int []arr=new int[10000];//array for storing our result
    arr[0]=1;
    int result_size=1;//size of resultant array
    for(int i=2;i<=n;i++)
    {
        int carry=0;// let default value of carry is 0 for each iteration 
        for(int j=0;j<result_size;j++)
        {
            int product=(arr[j]*i+carry);
            arr[j]=product%10;
            carry=product/10;
        }
        //now fill the value of carry in resultant array and increase the size of resultant array
        while(carry!=0)
        {
            arr[result_size]=carry%10;//store the last digit of carry in resultant array
            carry/=10;
            result_size++;
        }
    }
    //now print the array in reverse to make the required result
    for(int i=result_size-1;i>=0;i--)
    {
        System.out.print(arr[i]);
    }


    }
