//TODO: Add two numbers given by user

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;                  //TODO: Read number of cases
	while (T>0) 
	{
		int a, b;
		scanf("%d %d", &a, &b);    //TODO: Read integers
		cout<<(a+b)<<endl;         //TODO: Print result
		T--;  //updating T.
	}

	return 0;
}

