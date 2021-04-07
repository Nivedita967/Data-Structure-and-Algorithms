// Approach:
// 	if the number of elemnts are n then:

// 		leftDiagonal elements are 00,11,22,33..(n-1)(n-1)
// 	while rightDiagonal elements are:
// 		0(n-1),1(n-2),2(n-3)...n-1(0)
// 	we are just using this simple observation to find the difference

#include<stdio.h>
#include<stdlib.h> //To use abs function
int main()
{
	int n;
	scanf("%d",&n);
	int arr[n][n];
	for (int row = 0; row < n; ++row)
	{
		for (int col = 0; col < n; ++col)
		{
		
			scanf("%d",&arr[row][col]);
		
		}
		
	}
	
	int leftDiagonal=0,rightDiagonal=0;
	for (int i = 0; i < n; ++i)
	{
		leftDiagonal+=arr[i][i];
	}

	for (int i = 0,j=n-1; i < n; ++i,j--)
	{
		rightDiagonal+=arr[i][j];
	}

	int ans=rightDiagonal- leftDiagonal;

	printf("%d\n",abs(ans));

	return 0;
}
