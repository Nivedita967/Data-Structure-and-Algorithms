#include <bits/stdc++.h>

using namespace std;

int main() {
	// your code goes here
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long int t,n,count=0,i;
    cin>>t; //test cases
    while(t--){
        cin>>n;
        stack<int> binary; //stack to store binary 0, 1 values
        i = 0; 
        while (n > 0) { 
      
            // storing remainder in binary array 
            binary.push(n%2);
            n = n / 2; 
            i++; 
        } 
        count=i;
        vector<int> num1,num2; //binary digits of both numbers stored

        for (int i=0;i<count;i++){ //iterate through the binary form of the entered digit
            if (i==0){
                num1.push_back(1);
                if (binary.top()==0){
                    num2.push_back(1);
                }
                else num2.push_back(0);
            }
            else if (i==1){
                num2.push_back(1);
                if (binary.top()==0){
                    num1.push_back(1);
                }
                else num1.push_back(0);
            }
            else if (binary.top()==0){
                num1.push_back(1);
                num2.push_back(1);
            }
            else{
                num1.push_back(0);
                num2.push_back(1);
            }
            binary.pop();
        }


        long long int n1=0,n2=0;

        //convert numbers from binary to decimal
        for (int i=0;i<num1.size();i++){
            n1*=2;
            n1+=(num1[i]*2);
        }
        for (int i=0;i<num2.size();i++){
            n2*=2;
            n2+=num2[i]*2;
        }
        // cout<<n1<<" "<<n2<<" ";
        cout<<n1*n2/4<<"\n";
    }
	return 0;
}
