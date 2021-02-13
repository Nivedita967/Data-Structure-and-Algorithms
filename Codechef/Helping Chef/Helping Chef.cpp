#include <iostream>

using namespace std;

int main(void) 
{
    int t;
    cin>>t;
    for(int i = 0; i < t;i++)
    {   int n;
        cin>>n;
        if(n < 10)
        {
            cout<<"Thanks for helping Chef!\n";
            
        }
        else
        {
            cout<<"-1"<<endl;
        }
        
    }
}
