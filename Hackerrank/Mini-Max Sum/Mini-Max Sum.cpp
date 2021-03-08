#include<bits/stdc++.h>
using namespace std;


int main() 
{
    //declaration of variables
    long long V[7], s = 0;

    //loop for input and calcluating sum
    for(int i = 1; i <= 5; ++i) 
    {
        cin >> V[i];
        s += V[i];
    }   

    //sorting the input
    sort(V + 1, V + 6);

    //printing the required output
    cout << s - V[5] << " " << s - V[1] << endl;
    return 0;
}