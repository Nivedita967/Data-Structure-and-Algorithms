#include <stdio.h> 

int main() {
	int T; 
	scanf("%d", &T);
  
	while (T>0) {
		// Read the input a, b
		int a, b;
		scanf("%d %d", &a, &b);
    
		int ans = a%b;
		printf("%d\n", ans);
    
		T--;
	}
  
	return 0;
}

