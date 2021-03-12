#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //taking input
    int year;
    cin>>year;
    
    //declaring varibales
    int a,b,c,d;
    
   while(1)
   {
       //taking individual digit of the year 
       year++;
      a = year / 1000;
      b = year / 100 % 10;
      c = year / 10 % 10;
      d = year % 10;

      //checking the digits distinctness
        if (a != b && a != c && a != d && b != c && b != d && c != d)
        {
            break;
        }
       
   }
   //printing beautiful year as output
   cout<<year<<endl;
 
    return 0;
}