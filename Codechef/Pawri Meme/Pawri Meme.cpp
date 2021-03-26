#include<bits/stdc++.h>
using namespace std;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {  
        // Taking String as Input
       string s;
       cin >> s;
       int n = s.length();
       for(int i = 0 ;  i < n-4 ; i++)
       {  
        //    if we got party as string then change it to "pawri"
           if(s[i] == 'p' && s[i+1] == 'a' && s[i+2]=='r' && s[i+3]=='t' && s[i+4] == 'y')
           {
               s[i+2] = 'w';
               s[i+3] = 'r';
               s[i+4] = 'i';
           }
       }
    //    Finally Print our updated string
       cout << s << endl;    
    }
    return 0;
}