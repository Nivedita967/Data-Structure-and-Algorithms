#include<stdio.h>
int main()
{	

    //declare variables and take input
	int n,i,j,toffee[100002]={0},a[100002],candy=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)	
	{
		scanf("%d",&a[i]);
		toffee[i]=1;
	}
	

    //main solution starts here
	for(i=1;i<=n;i++) //iterate through the array
	{
		
		if(a[i+1]>a[i]) //check for higher rating student
		{
			toffee[i+1]=toffee[i]+1;
		}
		else if(a[i]>a[i+1])
		{	
			if(toffee[i]<=toffee[i+1])
			toffee[i]+=(toffee[i+1]-toffee[i]+1);
			for(j=i-1;j>=1;j--)
			{
				if(a[j]>a[j+1] && toffee[j]<=toffee[j+1]) //check for higher or lesser rating 
				{	
					toffee[j]+=(toffee[j+1]-toffee[j]+1);
				}
				else break;
			}
		}
	}
	for(i=1;i<=n;i++)	//calculate total candies by iterating through toffee array which holds candies for a specific student at specific index
	{
		candy+=toffee[i];
	}
	printf("%d\n",candy);
	return(0);
}		