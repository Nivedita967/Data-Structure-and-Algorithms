// A program in c++ to find rounded grades of the students


#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main()
{
    int t = 0;
    cin>>t;                                          // Getting number of test cases
    for (int j = 0; j < t; j++)
    {
        int n;
        cin>>n;                                      // Getting the number
        if (n < 38 or n%5 == 0)                      // Printing the same marks if less than 38 or divisible by 5
        {
            cout<<n<<endl;
            continue;
        }
        int count = 0;
        while (n%5 != 0)                             // Rounding upto next multiple of 5
        {
            n += 1;
            count++;
        }
        if (count < 3)
        {
            cout<<n<<endl;                          // Printing result
        }
        else {
            cout<<n-count<<endl;
        }
    }    
}
