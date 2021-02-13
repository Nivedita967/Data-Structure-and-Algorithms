#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;  //read number of cases
	while (T>0) 
	{
		int a, b;
		scanf("%d %d", &a, &b);  //read integers
		cout<<(a+b)<<endl;  //displaying sum
		T--;  //updating T.
	}

	return 0;
}
