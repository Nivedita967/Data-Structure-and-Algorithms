#include<iostream>

using namespace std;

int main()
{
    int T;
    cin>>T;                 //TODO: reading number of test cases


    for(int i=0;i<T;i++)
    {
        int n,sum=0;
        cin>>n;             //TODO: reading integers 

        while(n>0)
        {
            sum += (n%10);
            n=n/10;
        }

        cout<<sum<<endl;    //TODO: displaying result
    }
}

