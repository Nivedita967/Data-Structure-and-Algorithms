// A program in C++ count the number of cars which were moving at their maximum speed on the straight segment.


#include <iostream>

using namespace std;

int main() 
{
	int t;
    scanf("%d",&t);                          // Getting number of test cases.
    for(int i = 0; i < t;i++)
    {   
        int n, min = 0;
        cin>>n;                              // Getting number of cars
        int count = n;
        int arr[n];
        for (int j = 0; j < n; j++)
        {
            cin>>arr[j];                     // Getting maximum number of cars
            if(arr[j]<min || j==0)
            {
                min = arr[j];
            }
            
            if (j > 0)
            {
                if (arr[j] >min)
                {
                    count--;
                }
            }
        }
        cout<<count<<endl;                 // Printing result
        
        
    }
	return 0;
}
