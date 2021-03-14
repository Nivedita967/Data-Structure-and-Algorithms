#include<bits/stdc++.h>
using namespace std;
int main()
{
    int d1,v1,d2,v2,p,k(1);
    cin >> d1 >> v1 >> d2 >> v2 >> p;
    if(d1>d2)
    {
        k = (d1-d2)*v2;
        if(p-k<=0 && v2!=0)
        {
            cout << d1-d2-((k-p)/v2) + d2 -1 << endl;
            return 0;
        }
        p = p-k;
        k = d1-d2;
        while(p>0)
        {
            p = p - (v1+v2);
            k++;
        }
    cout << k + (d2 - 1) << endl;
    return 0;
    }

    else if(d1<d2)
    {
        k = (d2-d1)*v1;
   
     if(p-k<=0 && v1!=0)
        {
            cout << d2-d1-((k-p)/v1) + d1 -1 << endl;
            return 0;
        }
        p = p-k;
        k = d2-d1;
        while(p>0)
        {
            p = p - (v1+v2);
            k++;
        }
    cout << k + (d1-1) << endl;
    return 0;
    }

    else
    {
        while(p>0)
        {
            p = p - (v1+v2);
            k++;
        }
        cout << (k-1) + (d1 - 1) << endl;
        return 0;
    }
 return 0;
}