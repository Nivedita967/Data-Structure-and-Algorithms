#include <bits/stdc++.h>
using namespace std;

int main()
 {
    //declaration of required variables
    string s;
    string h;
    int hr;
    
    //taking input
    cin>>s;
    
    //checking and converting the string to 24hr format
    hr = ((s[0]-'0')*10)+(s[1]-'0');
    if(s[8]=='P'&&s[9]=='M'&& hr ==12)
     {cout<<to_string(hr);}
    else if(s[8]=='P'&&s[9]=='M')
     {cout<<to_string(hr+12);}
    else if(s[8]=='A'&&s[9]=='M'&&hr==12) 
    {cout<<"00";}
    else
     {cout<< s[0]<<s[1];}
    
    //printing the output
    for(int i =2;i<8;i++)
     {
         cout<<s[i];
     }   
    cout<<endl;
    return 0;
}