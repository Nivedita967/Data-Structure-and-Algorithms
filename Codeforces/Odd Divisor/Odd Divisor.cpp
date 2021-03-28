// Approach:- If the number is in power of 2 then it won't have odd divisor else it will always have odd divisor
#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#define ll long long
using namespace std;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		if(log2(n)==ceil(log2(n))) //check if the number is power of 2
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;

	}
	return 0;
}