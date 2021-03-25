/*Time complexity = O(t) and Space complexity = O(t) where t = number of testcases*/
#include<iostream>
using namespace std;
int main()
{
    int no_of_testcases;
    cin>>no_of_testcases;
    while(no_of_testcases--)
    {
        int a,b,c; 
        cin>>a>>b>>c; // Take 3 numbers from user
        int maximum_number = max(max(a,b),c); // maximum_number is the maximum number among 3 user-inputs
        /* 2nd maximum number =  maximum number from remaining 2 numbers(numbers except maximum_number) */
        if(maximum_number==a)
            cout<<max(b,c)<<endl;
        else if(maximum_number==b)
            cout<<max(a,c)<<endl;
        else
            cout<<max(a,b)<<endl;
    }
}
