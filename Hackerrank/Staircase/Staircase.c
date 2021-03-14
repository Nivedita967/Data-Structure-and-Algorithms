void staircase(int n)
{
    for(int i=1; i<=n; i++) //No of Rows
    {
        for(int j=n; j>i; j--) //No of Space 
            printf(" ");
        for(int j=1; j<=i; j++) //No of #
            printf("#");
        printf("\n");
    }
}
