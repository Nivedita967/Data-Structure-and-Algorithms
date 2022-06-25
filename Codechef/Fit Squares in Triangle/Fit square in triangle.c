#include <stdio.h>

int main(void) {
	// your code goes here
	int t;
	scanf("%d",&t);
		for(int i=0;i<t;i++){
			/* Let consider the right angle isosceles triangle ABC with base 12. It has many layers of squares, each layer that may contain many squares,is'nt it */
		    int base,squares=0;
		    scanf("%d",&base);
		    while(base > 2 )//check for base whether is it less than two. when base is not two then no more square can be added to triangle.
	        {
	            squares+=(base-2)/2;/*
				* We are reducing the base by 2 and divide by 2
	            * In single layer of a triangle,
	            * We minus 2, make sure we remove the part where we can't fit the square due to the slope in triangle
	            * Then we divide by two which caculate the number of square that can fit in that layer*/
	            base = base-2;/*  Now we reduce the base by two, moving to above layer (like from bottom to top)
	            * And the loop continue till it reach the base equal to 2 where we can no more fit the square
	            */
	        }
		    printf("%d\n",squares);
		}
	return 0;
}