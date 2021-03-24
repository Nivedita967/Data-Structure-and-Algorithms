#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
        //declaration of variable
        long long int i,j,k;
        bool f1=true;
        map<char,int> mp;
        string s1,s2;
 
        //taking input
        getline(cin,s1);
        getline(cin,s2);

        //loop for initialising map
        for(i=0;i<s1.length();i++)
        {
            mp[s1[i]]++;
        }
 
        //loop for checking if Vasya can write the given anonymous letter
        for(i=0;i<s2.length();i++)
        {
            if(mp[s2[i]]>0 || s2[i]==' ')
            {
                mp[s2[i]]--;
                continue;
            }
 
            else
            {
                f1=false;
                break;
            }
        }
 
        // if its true print YES else print NO
        if(f1==true)
          {  cout<<"YES";}
        else
          {  cout<<"NO";}
 
    return 0;
}