#include <stdio.h>
int main(void)
{
	int test;
    scanf("%d",&test);
    char out[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'}; //All possible chars
    while(test>0)
    {
        int n;
        scanf("%d",&n);;
        char bin[n];
        scanf(" %s", bin); //Taking Input in an array as string
        for(int i=0; i<n; i)  
        {
            int dec =0;
            int p=8;
            for(int j=i, c=1;c<=4;c++, j++) //Decoding the Code according to requirement of the problem 
            {
                int bit = bin[i];
                bit -= 48;
                bit *= p;
                dec  += bit;
                p /= 2;
                i=j+1;
            }
            printf("%c",out[dec]);
        }
        printf("\n");
        --test;
    }
	return 0;
}
