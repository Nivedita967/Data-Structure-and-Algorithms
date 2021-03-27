//Note:: self input output, to pass all test cases, clear hackerrank default code and run this code

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long max(long a,long b) // function to return greater number
{
	return ((a>b)?a:b) ;
}
long min(long a,long b) // function to return smaller number
{
	return ((a<b)?a:b) ;
}
long func(long n, long a ,long b)  
{
	long ret=1, ret2=1, i;
	for (i=(max(a,b)+1);i<=n;i++)
	{
		ret*=i;
	}
	for (i=1;i<=min(a,b);i++)
	{
		ret2*=i;
	}
	
	return ret/ret2;
}

int isprime(long m)  // function to check if number is prime
{
	long i;
    if (m==1) return 0;
     if (m==2) return 1;      if (m==3) return 1;      if (m==5) return 1;
	
	for (i=2;i<=(long)(sqrt(m));i++) //check if the number is divisible by any number, if yes return 0
	{
		if (m%i ==0) return 0;
	}
	return 1; //else return 1 which implies number is prime
}
long redJohn(long m)
{
    int i,ret=0;
    for (i=2;i<=m;i++)
    {
        if(isprime(i)==1) ret++;
    }
    return ret;
}



//function to call our solution function and take input
int main() 
{

	long c=4,n,m,p,t,i,num4,num1,j;
	scanf("%ld",&t);
	for (i=0;i<t;i++)
	{
		m=0;
		p=0;
		scanf("%ld",&n);
        
		for (num4=0;num4<=(n/c);num4++)
		{
			m=m+func(n-3*num4,n-4*num4,num4);
     		
		}
		printf("%ld\n",redJohn(m));
	}
	return 0;
}