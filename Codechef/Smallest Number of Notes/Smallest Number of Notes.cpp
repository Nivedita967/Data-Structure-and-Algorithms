//TODO: A program to calculate smallest number of notes to be given

#include <iostream>


int main(void) 
{
    int t;
    cin>>t;
    for(int i = 0; i < t;i++)                   //TODO: Take user input
    {
        int n = 0;
        cin>>n;
        int count = 0;
        while (n >= 100)                        //TODO: Calculating 100 rupees note
        {
            n -= 100;
            count++;
        }
        while (n >= 50)                         //TODO: Calculate 50 rupees note
        {
            n -= 50;
            count++;
        }
        while (n >= 10)                        //TODO: Calculate 10 rupees note
        {
            n -= 10;
            count++;
        }while (n >= 5)                        //TODO: Calculate 5 rupees note
        {
            n -= 5;
            count++;
        }
        while (n >= 2)                          //TODO: Calculate 2 rupees note
        {
            n -= 2;
            count++;
        }
        while (n >= 1)                           //TODO: Calculate 1 rupee note
        {
            n -= 1;
            count++;
        }
        cout<<count<<endl;                      //TODO: Printing result
    }
}
