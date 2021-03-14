#include <bits/stdc++.h>
using namespace std;
 
//declaring global array of primes within constraints  
int prime[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,100000000};
 
 int main()
{
    //variable declaration
    int n,m;

    //taking input
	cin>>n>>m;

    //bool variable
	bool flag=false;

    //loop for checking if m is the next prime number after n
	for(int i=0;i<15;i++)
    {
		if(prime[i]==n&&prime[i+1]==m)
        {
            //if yes, setting it as true
			flag=true;
			break;
		}
	}

    //printing the output
	if(flag)
    { cout<<"YES\n";}
	else
     {cout<<"NO\n";}
 
    return 0;
}