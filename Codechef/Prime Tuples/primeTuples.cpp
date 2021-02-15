// Problem Link
// https://www.codechef.com/problems/PTUPLES

#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Finding the prime numbers till 10^6 beforehand so that we don't have to check again and again
    // This will work for every test cases
    const int n = 1000001;

    // Finding prime numbers using Sieve of Eratosthenes
    bool prime[n];
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    // This if for storing the number of good tuples for any value till 10^6
    int ans[n] = {0};
    int cntr = 0;
    for (int i = 5; i < n; i++)
    {
        // Odd + Odd = Even (so it wont' remain prime)
        // Odd prime + 2 may give odd prime
        // so we are checking for each number that whether
        // i and i-2 is prime or not
        if (prime[i] and prime[i - 2]){
            cntr++;
        }
        ans[i] = cntr;
    }
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;

        // If the number is less than 5 then answer will be always zero
        // because we have only two prime numbers 2 and 3
        if (m < 5)
        {
            cout << 0 << "\n";
            continue;
        }
        cout << ans[m] << "\n";
    }
    return 0;
}