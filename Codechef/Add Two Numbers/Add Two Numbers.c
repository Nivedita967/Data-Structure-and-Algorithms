//TODO: Add two numbers given by user

#include <stdio.h> 

int main() {
	int T;
	scanf("%d", &T);                //TODO: Read number of test cases
	while (T>0) 
	{
		int a, b;
		scanf("%d %d", &a, &b);       //TODO: Read integers
		printf("%d\n", a+b);          //TODO: Print result
		T--;  //updating T.
	}

	return 0;
}

