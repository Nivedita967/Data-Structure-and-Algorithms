#include<iostream>
using namespace std;
int main ()
{
    int arr[1000], n, i, sum = 0, pro = 1;      //initialising array and other variables
    cout << "";
    cin >> n;
    cout << "";
    for (i = 0; i < n; i++)          //input of elements of array using for loop
    cin >> arr[i];
    for (i = 0; i < n; i++)
    {
        sum += arr[i];            //addition of elements 0f array
    }
    cout << "" << sum;
    return 0;
}
