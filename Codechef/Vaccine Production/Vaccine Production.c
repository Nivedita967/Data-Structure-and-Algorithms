//TODO: A Program in C to analise production of vaccine

#include <stdio.h>
#include <math.h>

int main(void) 
{
    int v1,d1,v2,d2,p,prod=0;
    scanf("%d %d %d %d %d",&d1,&v1,&d2,&v2,&p);          //TODO: Reading input
    int day = 1;
    while(prod < p)                                      //TODO: Calculating Production
    {
        if (day >= d1)
        {
            prod+=v1;
        }
        if (day >= d2)
        {
            prod+=v2;
        }
        day++;
    }
    printf("%d",day-1);                                  //TODO: Printing Result
    
}

