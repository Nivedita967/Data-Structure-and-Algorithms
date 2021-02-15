bool isPerfectSquare(int num)
{
    for(long int i=1; i*i<=num; i++) //No need to check after sqrt of num
        if(num==i*i)
            return 1;
    return 0;            
}
