// A program to find a specific subarray from a given array


#include <bits/stdc++.h>
#include <iostream>

using namespace std;


int main()
{
    int s[100];
    int t = 0;
    cin>>t;                                    // Getting length of array
    for (int k = 0; k < t; k++)
    {
        cin>>s[k];                              // Getting array
    }
    int d,m;
    cin>>d>>m;                                 // Getting characteristics of an array
    int count = 0;
    int ran = t - m; 
    if (t == m)
    {
        ran = t;
    }
    for (int i = 0; i <= ran; i++)             // Calculating answer
    {
        int sum = 0;
        for (int j = i; j < (i+m); j++)
        {
            sum += s[j];
        }
        if (sum == d)
        {
            count++;
        }
    }   
    cout<<count;                               // Printing answer
    return 0;
}
