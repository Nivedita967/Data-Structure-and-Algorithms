#include <iostream>
using namespace std;

void multiply(int *a, int &n, int no)
{
  int carry = 0;
  for (int i = 0; i < n; i++)
  {
    int product = a[i] * no + carry;
    a[i] = product % 10;
    carry = product / 10;
  }

  while (carry)
  {
    a[n] = carry % 10;
        carry = carry / 10;
    n++;
  }
}

void big_factorial(int numbers)
{
  //Assumming max digit 1000 Digits
  int *a = new int[1000]{0};
  a[0] = 1;
  int n = 1; //n denotes the array index
  for (int i = 2; i <= numbers; i++)
  {
    multiply(a, n, i);
  }

  for (int i = n - 1; i >= 0; i--)
  {
    cout << a[i];
  }
  cout << endl;
}

int main()
{
  big_factorial(100);
}