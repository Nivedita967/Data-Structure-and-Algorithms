class Solution
{
public:
    int reverse(int x) 
     long long int sum = 0, pos=1; //Taking Long one as int wasn't able to fit the reverse
    if(x== -2147483648) //Taking this exception case of negative max term out as positive is one less so it can't be changed to +ve
        return 0;
    if(x<0)
    {
        pos =0;
        x *= -1;
    }
    while(x>0)
    {
        int rem = x%10;
        sum = (sum*10) + rem;
        x /= 10;
    }
    if(sum >(INT_MAX)-1) //Checking with max value of int here
        return 0;
    if(pos == 0)
        sum *= -1; //Making it -ve if original num was -ve
    return sum;
};
