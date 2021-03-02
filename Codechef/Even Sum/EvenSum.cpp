#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		long long int i, odd = 0; // taking the inputs as long long int because the input values can exceed the limit of data type int
		// making a variable odd to store the no of odd inputs
		for (int j = 1; j <= n; j++)
		{
			cin >> i;
			if (i % 2 != 0) //checking whether the input no is even or odd
			{
				odd++;    // increasing the value of odd on addition of odd input
			}
		}
		if (odd % 2 == 0) // if the no of odd inputs is even then person 1 will the game else the person 2 will win.
		{
			cout << "1" << endl;;
		}
		else
		{
			cout << "2" << endl;
		}
	}
	return 0;
}

/* Documentation: -
If the sum of elements is even then player 1 will win else player will win
To check this we calculate the no off odd inputs.
If the no of odd inputs re even then the sum will be even else it will be odd.
The output doesnt depend on the even inputs
*/

