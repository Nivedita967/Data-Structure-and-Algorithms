#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    // input string
    string s;
    cin >> s;
    // storing length of string in n variable
    int n = s.length(); 
    // Here the logic Applied is , 
    // first will Print String from index 0 till end 
    // in next Iteration from index 1 till index and in this way we are increaing the value of our starting index  
    for(int i = 0 ; i < n ; i++)
    {
        for(int j = 1 ; j <= n - i ; j++)
        { 
            // substr is an inbuild function used to print string from mentioned indices inside the bracket
            cout << s.substr(i,j) << endl; 
        }
    }
    return 0;
}