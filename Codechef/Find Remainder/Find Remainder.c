//TODO: Printing remainder of given inputs

#include <stdio.h> 

int main() {
	int T; 
	scanf("%d", &T);                   

	while (T>0) {
		                          //TODO: Read the input a, b
		int a, b;
		scanf("%d %d", &a, &b);

		int ans = a%b;
		printf("%d\n", ans);      //TODO: Printing result

		T--;
	}

	return 0;
}
