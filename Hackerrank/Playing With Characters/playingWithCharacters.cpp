#include<iostream>
#include<string>
#include<stdio.h>
using namespace std;

int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //to take character input
    char ch;
    cin>>ch;

    //to take string input
    string str;
    cin>>str;
    string sentence;

    //to ignore newline character in buffer
    cin.ignore();

    //to take sentence input 
    getline(cin, sentence);

    cout<<ch<<endl<<str<<endl;
    cout<<sentence<<endl;
}