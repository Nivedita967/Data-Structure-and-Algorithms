// Daanish as always is busy creating and solving his favourite and interesting graph problems. Chef assigns each problem a difficulty — 
// an integer between 1 and 10. For each valid i, there are Ai problems with difficulty i.

// A participant hacked Daanish's account and got access to the problem proposal document. He can delete up to K problems from 
// the document in order to reduce the difficulty of the contest for himself and his friends. Find the smallest possible value of the 
// difficulty of the most difficult problem which remains after removing K problems.

#include<stdio.h>

int main()
{
	int t;
    // t = number of test cases
	scanf("%d",&t);
	while(t--)
	{
        // ar[10] is the level of difficulty array
		int i,ar[10],k,sum=0,req;
		for(i=0;i<10;i++)
			scanf("%d",&ar[i]);
            // the number of problems to be deleted
		scanf("%d",&k);
		for(i=9;i>=0;i--)
		{
            // means: element has already been removed
			if(ar[i]==0)
			continue;
			if(k>=ar[i])
			{
                // deduct that arr[i] from k because it has been removed
				k-=ar[i];
				ar[i]=0;
			}
			else
			{
				ar[i]-=k;
				break;
			}					
		}
		int j;
		for(j=9;j>=0;j--)
		{
            // if true: then j+1 would give the minimum difficulty of the most difficult remaining problem
			if(ar[j]!=0)
				break;
		}	
		printf("%d\n",j+1);
	}
	return 0;
}