//Time Complexity O(n)
#include <stdio.h>
int main(void)
{
	int n, h, x, q=0;
	scanf("%d %d %d", &n, &h, &x);
	int t[n];
	for(int i=0; i<n; i++)
	{
	    scanf("%d", &t[i]); 
	    if(t[i]+x>=h) //Checking for the required sum
	    {
	        q = 1;
	        printf("YES");
	        break;
	    }
	}
	if(q==0)
	    printf("NO");
	return 0;
}
