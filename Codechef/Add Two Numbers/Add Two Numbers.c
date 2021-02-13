#include <stdio.h> 

int main() {
	int T;
	scanf("%d", &T);  //read number of cases
	while (T>0) 
	{
		int a, b;
		scanf("%d %d", &a, &b);  //read integers
		printf("%d\n", a+b);  //displaying sum
		T--;  //updating T.
	}

	return 0;
}
