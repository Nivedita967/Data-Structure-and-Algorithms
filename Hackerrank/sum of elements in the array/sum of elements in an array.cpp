#include<iostream>
using namespace std;
int main ()
{
    int arr[1000], n, i, sum = 0, pro = 1;
    cout << "";
    cin >> n;
    cout << "";
    for (i = 0; i < n; i++)
    cin >> arr[i];
    for (i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "" << sum;
    return 0;
}
