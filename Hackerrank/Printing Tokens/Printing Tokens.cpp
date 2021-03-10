// A program in C++ to print every word of a sentence in a new line


#include <iostream>
#include  <bits/stdc++.h>

using namespace std;

int main()
{
    char c[1000];
    cin.getline(c, 1000);                     // Getting input (the sentence)
    
    for (int i = 0; c[i] != '\0'; i++)        // Iterating through the string to find spaces and then printing a new line
    {
        if (c[i] == ' ')
        {
            cout<<"\n";
        }
        else
        {
            cout<<c[i];
        }
    }
    cout<<endl;                               // Priting a new line at the end of output
}
