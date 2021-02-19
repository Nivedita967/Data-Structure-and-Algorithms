#include <bits/stdc++.h> 

using namespace std;

int main() 
{
	// Read the number of test cases.
	int T;
	cin>>T;

    //loop for running testcases
	while (T--) 
    {
        //declaration of required variables
		int a, b;

        //taking input
		cin>>a>>b;

        //calculating remainder
		int ans = a%b;

        //printing result 
		std::cout << ans << std::endl;
	}

	return 0;
}