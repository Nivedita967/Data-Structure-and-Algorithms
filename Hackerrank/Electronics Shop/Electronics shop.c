#include <stdio.h>

int main()
{
    //declaration
    int b,usb[1000],key[1000],no=-1,i,j,n,m,result=0;

    //input
    scanf("%d %d %d",&b,&n,&m);

    //loop for inputting 
    for(i=0;i<n;i++)
    {
        scanf("%d",&key[i]);
    }
    for(j=0;j<m;j++)
    {
        scanf("%d",&usb[j]);
    }

    //loop for finding possible maximum to buy both 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            result=key[i]+usb[j];
            if(result>no && result<=b)
            {
                no=result;
            }
        }   
    } 

    //printing the maximum 
    printf("%d",no);
}