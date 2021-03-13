// A program to find whether the chef will be able to complete a task or not


#include <iostream>

using namespace std;

int main() 
{
	int n,h,x;
	cin>>n>>h>>x;                          // Getting user input
    if (x >= h)
    {
        printf("YES");                   // Printing yes if required time is less than time having
        return 0;
    }
    
    for(int i = 0; i < n;i++)           // Calculating and printing how much more time is required
    {   
        int p;
        cin>>p;
        if (p + x >= h)
        {
            printf("YES");             // Printing yes if he will be able to do the task
            return 0;
        }
    }
    printf("NO");                       // Printing no if he will not be able to complete the task
	return 0;
}
