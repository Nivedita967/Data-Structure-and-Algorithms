#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    //declaration and input
    string s;
    cin>>s;

    //bool variable
     bool odd[26] = {false};

     //loop for removing an element from string
    for (int i = 0; i < s.length(); ++i)
    {
        odd[s[i]-'a'] =! odd[s[i]-'a'];
    }
    int oddcount = count(odd, odd + sizeof(odd) / sizeof(odd[0]), true);

    //checking and printing the winner
    cout << (oddcount == 0 || oddcount % 2 == 1 ? "First" : "Second") << endl;
    return 0;
}