#include <iostream>


int main(void) 
{
    int t;
    cin>>t;
    for(int i = 0; i < t;i++)
    {
        int n = 0;
        cin>>n;
        int count = 0;
        while (n >= 100)
        {
            n -= 100;
            count++;
        }
        while (n >= 50)
        {
            n -= 50;
            count++;
        }
        while (n >= 10)
        {
            n -= 10;
            count++;
        }while (n >= 5)
        {
            n -= 5;
            count++;
        }
        while (n >= 2)
        {
            n -= 2;
            count++;
        }
        while (n >= 1)
        {
            n -= 1;
            count++;
        }
        cout<<count<<endl;
    }
}
