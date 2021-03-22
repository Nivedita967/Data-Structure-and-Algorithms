#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t; // For test cases.
    while(t--){
        long int m,n;
        cin>>m>>n; //Take inputs
        long long int temp;
        vector< long long int> a,b;
        for (long int i=0;i<m-1;i++){
            cin>>temp;
            a.push_back(temp);  //Take inputs.
        }
        for (long int i=0;i<n-1;i++){
            cin>>temp;
            b.push_back(temp);
        }

        //Sort both the vectors to accomplish greedy strategy.
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        long int x=1,y=1;
        long long int cost=0;

        while(true){
            if (a.size()!=0 && b.size()!=0){ //while both are not empty.
                if(a.back()>=b.back()){
                    cost+=(y*a.back())%1000000007;
                    x++;
                    a.pop_back();
                    //cout<<"hello";
                }
                else if(a.back()<b.back()){
                    cost+=(x*b.back())%1000000007;
                    y++;
                    b.pop_back();
                    //cout<<"world";
                }
            }
            else if (a.size()==0 && b.size()==0) break; // if both empty we are done
            else if (a.size()==0){ // if one is empty, keep adding costs from the other array until it is empty
                cost+=(x*b.back())%1000000007;
                b.pop_back();
                //cout<<"end";
            }
            else if (b.size()==0){
                cost+=(y*a.back())%1000000007;
                a.pop_back();
            }
        }
        cout<<cost%1000000007<<endl;
    }
}
