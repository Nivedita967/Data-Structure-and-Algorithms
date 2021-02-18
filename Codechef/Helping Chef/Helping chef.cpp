#include <iostream>
using namespace std;

int main()
{
	//declaration of no of test cases
	int t;

    //taking input of no of test cases
	cin>>t;

    //loop for running all the test cases
	while(t--)
	{
        //declaration of n
	    int n;

        //inputting value of n
	    cin>>n;

        //checking if n is less than 10 or not and printing the output accordingly
	    if(n<10)
	    {
	        cout<<"Thanks for helping Chef!"<<endl;
	    }
	    else
	    {
	        cout<<"-1"<<endl;
	    }
	}
	return 0;
}