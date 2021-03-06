// Approach:-
// 	All we have to do is check from the car which entered last, as the car in frount will stop current car from 
// 	going to max speed. So if, there is any car in frount which have slower or equal as current car
// 	then current car cant go full speed  


#include<stdio.h>
#include <stdbool.h>
int main(int argc, char const *argv[])
{
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);

		int arr[n];

		for (int i = 0; i < n; ++i) // Taking array input
		{
			scanf("%d",&arr[i]);
		}

		int maxSpeedCar=0;

		for (int i = n-1; i>=0 ; i--)// Traversing the array from behind
		{
			bool found=true;
			for(int j=i-1; j>=0;j--)
			{
				if(arr[i] >= arr[j])// if there is any slower car in frount then you cant go full speed
				{
					found=false;
					break;
				}
			}
			if(found) //if there is no slow car, this car is going full speed.
				maxSpeedCar+=1;
		}

		printf("%d\n",maxSpeedCar);

	}	
	return 0;
}
