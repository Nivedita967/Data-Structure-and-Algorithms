#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

//define global variables
int max_sum;
int max;

int get_maximum_increasing_subsequence_sum(int *array, int size){
	int dp[100000]={0}; //initialize array to 0, for memoization
	int i,j;

	if(size==1){  //if size 1, return that array
		max = max_sum = array[0];
		return 0;
	}

	dp[0]=array[0];
	max_sum = array[0];
	max = array[0];
	
	for(i=1;i<size;i++){ //iterate through array
		dp[i]=array[i];
		if(dp[i-1]+array[i]>dp[i]){
			dp[i] = dp[i-1]+array[i];
		}

		if(max<dp[i]){ //determine whther to modify the value or not
			max = dp[i];
		}
		if(array[i]>0){
			max_sum += array[i];
		}
	}
	
	if(max_sum>0 && array[0]<0){
		max_sum -= array[0];
	}
	
	return 0;
}

int main(void)
{
	int array[100000]={0};
	int t,n,i;

	scanf("%d",&t);
	while(t>0){
		scanf("%d",&n);
		i=0;
		while(i<n){
			scanf("%d",&array[i]);
			i++;
		}
		get_maximum_increasing_subsequence_sum(array,n);
		printf("%d %d\n",max, max_sum);
		t--;
	}

	return 0;
}