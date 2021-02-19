#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
    //declaration of variables 
    int i,a, b;
    
    //taking input
    scanf("%d\n%d", &a, &b);
    
    //loop for checking the numbers
  	for(i=a; i<=b; i++)
      {
        //if number is between 1-9 it will print its english name
          if(i==1)
          {
              printf("one\n");
          }
          else if(i==2)
          {
              printf("two\n");
          }
          else if(i==3)
          {
              printf("three\n");
          }
          else if(i==4)
          {
              printf("four\n");
          }
          else if(i==5)
          {
              printf("five\n");
          }
          else if(i==6)
          {
              printf("six\n");
          }
          else if(i==7)
          {
              printf("seven\n");
          }
          else if(i==8)
          {
              printf("eight\n");
          }
          else if(i==9)
          {
              printf("nine\n");
          }
        
         // it will check for numbers greater than 9 whether they are odd or even and print output accordingly 
          else if(i>9)
          {
              if(i%2==0)
              {
                  printf("even\n");
              }
              else  {
                  printf("odd\n");
              }
          }

      }

    return 0;
}
