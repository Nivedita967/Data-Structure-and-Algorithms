/*  Question link - https://www.hackerrank.com/challenges/extra-long-factorials/problem */

#include<stdio.h>
int main() {
  int n, a[10000] = {0}, i = 0, carry, cpy, len, func, neww;     // declared required variables
  scanf("%d", &n);
  if(n==1)
  printf("1");                                                 // If given input is 1 then print 1
  else
  {
  cpy = n;
  while (cpy != 0) {
    a[i] = cpy % 10;                                           // exteacting the digits from the given number
    cpy = cpy / 10;
    i++;
  }
  while (n != 1) {
    for (len = 0; len < i; len++);
    n--;
    i = 0;
    carry = 0;
    for (i = 0; i <= len + 1; i++) {                             //using supercarry method
      func = n * a[i] + carry;                               
      a[i] = func % 10;                                         //Propogate the remaining carry to higher order digits
      carry = func / 10;                                   
    }
  }
  for (i = len; i >= 0; i--)
    if (a[i] != 0) {                                           //removing extra zero's 
      neww = i;
      break;
    }
  for (i = neww; i >= 0; i--)
    printf("%d", a[i]);                                       // printing the factroial of given number
  }
}

/*          supper cary method explanation
This algorithm works the way we learned how to do multiplication in 3rd grade, 
but using a super carry as opposed to a one digit carry. So instead of multiplying each digit of the first number by each digit of the second number, 
we multiply each digit of the first number by the entire second number. This resuls in a "super carry", a carry that could be greater than a two digit number */
