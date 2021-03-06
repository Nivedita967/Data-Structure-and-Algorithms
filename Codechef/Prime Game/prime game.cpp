#include <bits/stdc++.h>
using namespace std;
#define int long long int 
#define endl '\n'
#define MOD 1000000007
vector<int > primeSeive(int n){
    bool visited[n+1]; 
    memset( visited, true, sizeof( visited)); 
    //initially mark as all number till n are prime number
  
    for (int p=2; p*p<=n; p++) 
    { 
     
        if (visited[p] == true) 
        { 
           
            for (int i=p*p; i<=n; i += p) 
               visited[i] = false; 
        } 
    } 
  //now add those element in a vector which are marked as true
    vector<int > primeNumber;
    for (int p=2; p<=n; p++) {
         if (visited[p]) {
           primeNumber.push_back(p);
       }

    }
    return primeNumber;
      
         
}
void TestCase(){
    int x,y;
    cin>>x>>y;
    vector<int > v =primeSeive(x);
    if(v.size()<=y){
        cout<<"Chef"<<endl;
    }
    else{
        cout<<"Divyam "<<endl;

    }

}
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    vector<int > v=primeSeive(1000001);
    map<int, int > mymap;
    int prevprime=0;
    int prev=1;
    mymap[1]=0;

    for(int j=0;j<v.size();j++){
    prevprime++;
   mymap[v[j]] =prevprime;    
    
    

    }
   
    while(t--){
        int x,y;
        cin>>x>>y;
        if(mymap.find(x)!=mymap.end()){
            if(mymap[x]<=y){
            cout<<"Chef"<<endl;
        }
        else{
            cout<<"Divyam"<<endl;
        }

        }
        else{
           auto it = mymap.lower_bound(x);
            it--;
            if((*it).second<=y){
                cout<<"Chef"<<endl;
            }else{
                cout<<"Divyam"<<endl;
            }

        }
        
    }
   
    
    
   
   

  return 0;  
}
