//TODO: Print sum of digits of a 5 digit number

#include <iostream>

using namespace std;

int main()
{
    int num = 0, sum = 0, count = 0;
    cout<<"Enter the 5 digit number: ";
    cin>>num;                                        //TODO: Take user input
    int check = num;
    for(int i = 0; i < 5; i++)                       //TODO: Calculating sum
    {
        sum += num % 10;
        num = (num - (num % 10)) / 10;
        count++;
    }
    if (check >= 10000 && check <= 99999)            //TODO: Exception Handling
    {
        cout<<sum<<endl;
    }
    else
    {
        cout<<"Invalid Entry (Enter a 5 digit Integer)"<<endl;
    }
}

