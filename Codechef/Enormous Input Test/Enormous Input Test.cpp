#include <iostream> 

using namespace std;

int main() {
	// Read the input n, k
	int n, k;
	scanf("%d %d", &n, &k);

	// ans denotes number of integers n divisible by k
	int ans = 0;

	for (int i = 0; i < n; i++) {
		int t;
		cin>>t;

		if (t % k == 0) {
			ans++;
		}		
	}

	// Print the ans.
	cout<<ans<<endl;

	return 0;
}

