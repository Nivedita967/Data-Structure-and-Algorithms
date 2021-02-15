#include <iostream>
using namespace std;

int main() 
{
	// declaration of variables required
	int t,n;
	long long int k,d,sum=0;

    // inputting the number of test cases 
	cin>>t;

    //loop for running test cases
	for(int i=0; i<t; i++)
	{
        // equating sum to 0
	    sum=0;

        // inputting the values for N,D and K as mentioned in the question
	    cin>>n>>k>>d;

        // creating array dynamically
	    long int *a=new long int[n];

        // loop for inputting in array and calculating sum
	    for(int i=0; i<n;i++)
	    {
	        cin>>a[i];
	        sum+=a[i];
	    }

        //checking the maximum number of contests can be hosted in a day
	     long long int s;
	        s=sum/k;

        // checking and printing maximum no of contests   
	    if(s<d)
	    {
	        cout<<s<<endl;
	    }
	    else
	    {
	        cout<<d<<endl;
	    }
	}

	return 0;
}
