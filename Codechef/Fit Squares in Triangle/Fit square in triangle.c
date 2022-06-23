#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
		for(int i=0;i<t;i++){
		    int base,squares=0;
		    scanf("%d",&base);
		    while(base > 2 )
	        {
	            squares+=(base-2)/2;
	            base = base-2;
	        }
		    printf("%d\n",squares);
		}
	return 0;
}