#include<bits/stdc++.h>
using namespace std;

void func(int b){
    if(b<=3) cout<<0<<endl;  // no squares can be fit if the base is less than or equal to 3
    else{
        int n = b/2 - 1;         // otherwise if the base is greater than 3 the number of squares can be calculated using this logic
        cout<<(n*(n+1))/2<<endl;  
    }
        
}

int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);  // reading input from input.txt file 
        freopen("output.txt","w",stdout);  // reading output from output.txt file
    #endif
    ios::sync_with_stdio(0);  // used for faster input output
    cin.tie(0);
    int t;       // used for storing the number of test cases
	cin>>t;
	while(t--){
	    int b;   // used for storing the base of the right angled isosceles triangle
	    cin>>b;
	    func(b);  // this function calculates the maximum number of 2X2 squares that can be fit in a right-angled isoceles traingle of base b
	}
    return 0;
}