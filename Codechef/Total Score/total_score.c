// Algorithm: 
// 		The basic crux of this question is to just add the respective scores to the total when the 
// 	character of the string is '1' (that is, the player has solved the problem).

#include <stdio.h>

int main() {

	int t;
	scanf("%d" , &t);

	while(t--) {

		int n , k;
		scanf("%d %d" , &n , &k);

		long int arr[n];
		for(int i = 0; i < k; i++) {
			scanf("%ld" , &arr[i]);
		}

		char str[n][k];
		for(int i = 0; i < n; i++) {
			scanf("%s" , str[i]);
		}

		long int total_score = 0;

		for(int i = 0; i < n; i++) {
			for(int j = 0; j < k; j++) {

				// Player has solved the problem
				if(str[i][j] == '1') {

					// Adding to the total score
					total_score += arr[j];
				}
			}
		}

		printf("%ld\n", total_score);
	}

	return 0;
}



