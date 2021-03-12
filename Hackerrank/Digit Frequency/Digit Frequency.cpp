#include <bits/stdc++.h>

using namespace std;

int main(){
    int a[10]={0}; //initialize array of length 10 for hashing values for digits between 0-9.
    string s;
    cin>>s;
    int temp;
    for (int i=0;i<s.length();i++){ //iterate through the string.
        temp = (int(s[i])) - 48;
        if (temp<=9 && temp>=0 ){
            a[temp]++; //increment the number.
        }
    }
    for (int i=0;i<10;i++){ //print the array.
        cout<<a[i]<<" ";
    }
}