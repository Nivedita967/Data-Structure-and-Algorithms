#include<bits/stdc++.h> 
using namespace std;

// This is the function used to convert 12 hr time to 24 hr time
string print24(string str , string s)
{
    int h1 = (int)str[1] - '0';
    int h2 = (int)str[0] - '0';
    int hh = (h2 * 10 + h1 % 10);
   string f;
    if (s == "AM")
    {
        if (hh == 12)
        {  
           f = "00";
           f.append(str,2,5);
           return f;
        }
        else
        {
            f = str;
            return f;
        }
    }
 
     else
    {
        if (hh == 12)
        {
            f = "12";
            f.append(str,2,5);
           return f;

        }
        else
        {
            hh = hh + 12;
            f = to_string(hh);
            f.append(str,2,5);
            return f;
        }
    }
}
int32_t main() 
{ 
    ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    string str,s; 
    int t;
    cin >> t; 
    while (t--) 
    {  
        cin >> str >> s;
       int n;
       cin >> n;
       string s1 , s2 ,s3 ,s4,s5;
         string k = print24(str,s);
          int j = 0 ;

       for(int i = 0 ;  i < n ; i++)
       {  
          cin >> s1 >> s2 >> s3 >> s4;
          string r = print24(s1,s2);
          string g = print24(s3,s4);
        //   This is the compare function used to compare both the strings
            int x = k.compare(r);
            int y = k.compare(g);
            if(x>=0 && y<=0)
            {
               string so ="1";
               s5.append(so);
            }
            else
            {
               string so ="0";
               s5.append(so);         
            }
       }
       cout << s5 << endl;
    } 
    return 0; 
}
