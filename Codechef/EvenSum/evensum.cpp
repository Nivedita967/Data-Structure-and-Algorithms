#include <iostream>

using namespace std;

// function to check whether the sum is even or odd
void evensum(int n)
{
	long long int i;
	long long int odd = 0; // this is the integer which stres the no of odd no inputs
	for (int j = 1; j <= n; i++)
	{
		cin >> i;
		if (i % 2 != 0) //check whether the input no is odd or even
		{
			odd++;  // if the input no is odd, add the integer odd
		}
	}
	if (odd % 2 == 0)
	{
		cout << "1" << endl;
	}
	else
	{
		cout << "2" << endl;
	}
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		long long int n;
		cin >> n;
		(evensum(n));
	}
	return 0;
}