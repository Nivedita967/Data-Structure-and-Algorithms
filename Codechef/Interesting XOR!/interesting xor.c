#include <stdio.h>
#include <math.h>
int main(void) {
	int t;
	scanf("%d",&t);  //test cases
	for(int i=1;i<=t;i++) //iterate through test cases
	{
	    long long int n;  
	    scanf("%lld",&n);

        //initialize variables
	    long long int i=1;
	    long long int x=0;

	    while(x<=n)  //keep incrementing i to reach highest value in power of 2 less than n
	    {
	        x=pow(2,i);
	        i++;
	    }
	    i=i-2;

	    long long int b=floor(log2(n))+1; //take log of n to know the power of 2 needed

	    long long unsigned int temp=((1<<b)-1)^n;  //left shift 1 by b places
	    temp=temp+pow(2,i);
	    long long int temp2=pow(2,i)-1;
	    printf("%lld\n",temp*temp2); //calculate and prrint product of both numbers
        
	}
	return 0;
}
