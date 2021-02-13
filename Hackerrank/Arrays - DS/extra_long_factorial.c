/*  Question link - https://www.hackerrank.com/challenges/extra-long-factorials/problem */


int main() {
  int n, a[10000] = {0}, i = 0, carry, cpy, len, func, neww;
  scanf("%d", &n);
  if(n==1)
  printf("1");
  else
  {
  cpy = n;
  while (cpy != 0) {
    a[i] = cpy % 10;
    cpy = cpy / 10;
    i++;
  }
  while (n != 1) {
    for (len = 0; len < i; len++);
    n--;
    i = 0;
    carry = 0;
    for (i = 0; i <= len + 1; i++) {
      func = n * a[i] + carry;
      a[i] = func % 10;
      carry = func / 10;
    }
  }
  for (i = len; i >= 0; i--)
    if (a[i] != 0) {
      neww = i;
      break;
    }
  for (i = neww; i >= 0; i--)
    printf("%d", a[i]);
  }
}
