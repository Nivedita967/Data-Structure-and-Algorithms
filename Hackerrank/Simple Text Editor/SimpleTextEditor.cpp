#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string str="";

    //input number of queries
    int q;
    cin>>q;

    //implementing the stack using inbuilt stack
    stack<string>stk;
    stk.push(str);

    //loop for number of queries
    while(q--){

        //input query type
        int qtype;
        cin>>qtype;

        //if query type is 1, perform append operation
        if(qtype==1){
            string W;
            cin>>W;
            str+=W;
            stk.push(str);
        }

        //if query type is 1, perform delete operation
        if(qtype==2){
            int k;
            cin>>k;
            int y=str.length()-k;
            if(y<=0){
                str="";
            }
            else{
                 str=str.substr(0,y);
            }
            stk.push(str);
        }

        //if query type is 1, perform print operation
        if(qtype==3){
            int k;
            cin>>k;
            cout<<str[k-1]<<endl;
        }

        //if query type is 1, perform undo operation
        if(qtype==4){
            stk.pop();
            str=stk.top();
        }
    }
    return 0;
}
