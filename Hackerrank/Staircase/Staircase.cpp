// A program in C++ to print a staircase of given length


#include <bits/stdc++.h>

using namespace std;

void staircase(int n) {
for(int i = 0; i < n; i++)
{
for (int sp = 0; sp < n-1-i; sp++)               // Printing spaces
{
    cout<<" ";
}
for (int st = 0; st < i+1; st++)                 // Printing hashes
{
    cout<<"#";
}
cout<<endl;                                      // Printing new line after every row is printed 
}
}

int main()
{
    int n;
    cin >> n;
    staircase(n);

    return 0;
}
