//TODO: Reverse the digits of a given number

#include <iostream>                                      //TODO: Including header file
using namespace std;

int main(void)
{
    int t;
    cin >> t;
    int mul;
    for (int i = 0; i < t; i++)                         //TODO: Getting user input
    {
        int num = 0;
        int num2 = 0;
        cin >> num;
        while (num > 0)
        {
            num2 = num2 * 10 + (num % 10);              //TODO: Reversing the given digit
            num = (num - (num % 10)) / 10;
        } 
        cout << num2 << endl;                           //TODO: Printing result
    }
}
