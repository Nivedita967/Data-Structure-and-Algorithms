#include <stdio.h>


int main(void) 
{
    
    int a;
    float b;
    scanf("%d %f",&a,&b);
    if(a%5==0 && a+0.5<=b)
        printf("%.2f",b-a-0.5);
    else
        printf("%.2f",b);
  
	return 0;
}
