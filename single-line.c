#include <stdio.h>
#include <stdlib.h>
int singlenumber(int* arr,int a)// function for single number
{
    int i,j,k;
    for(i=0;i<a;i++)
    {
        for(j=0;j<a;j++)
        {
            if(i!=j)
            {
                if(arr[i]==arr[j])
                {
                    break;
                }
            }
        }
        if(j==a)
        {
            k=arr[i];
            return k;
        }
    }
    return 0;

}
int main()
{
  int arr[100],a,b,c;
  printf("enter the size \n");
  //taking the input from user
  scanf("%d",&a);
  for(b=0;b<a;b++)
  {
      scanf("%d",&arr[b]); // taking the data fro the user
  }
  c=singlenumber(arr,a);
  printf("\n%d",c); // printing the output

}