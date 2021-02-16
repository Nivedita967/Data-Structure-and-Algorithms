#include <iostream>
using namespace std;
 
int main()
{
    int test;
    cin >> test;
    char out[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p'}; //All possible chars
    while(test>0)
    {
        int n;
        cin >> n;
        char bin[n];
        for(int i =0; i<n; i++) //Taking Input in an array
        {
            cin >> bin[i];
        } 
        for(int i=0; i<n; i)
        {
            int dec =0;
            int p=8;
            for(int j=i, c=1;c<=4;c++, j++) //Decoding the Code according to requirement of the problem 
            {
                int bit = bin[i];
                bit -= 48;
                bit *= p;
                dec  += bit;
                p /= 2; reducing power of 2
                i=j+1;
            }
            cout << out[dec];
        }
        cout << endl;
        --test;
    }
    return 0;
}
