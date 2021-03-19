#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void calculate_the_maximum(int n, int k) {
   int a,b,AND=0,OR=0,XOR=0;             // initializing variables
  
  for (a=1;a<n;a++)
  {
      for (b=n;b>a;b--)
      {
          if ((a&b)<k && (a&b)>AND) 
          {
              AND = a&b;
          }
          if ((a|b)<k && (a|b)>OR) 
          {
              OR = a|b;
          }
          if ((a^b)<k && (a^b)>XOR) 
          {
              XOR = a^b;
          }
      }
  }
printf ("%d\n%d\n%d", AND,OR,XOR);  // printing output
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);      // getting user input
    calculate_the_maximum(n, k); // function  call
 
    return 0;
}
