#include <bits/stdc++.h>

using namespace std;

// Complete the isBalanced function below.
bool justBalanced(string str){
        stack<char> stk;
        for(int i=0;i<str.length();i++){
            char ch=str[i];
            if(ch=='('||ch=='{'||ch=='['){
                stk.push(ch);
            }
            else if(ch==')'||ch=='}'||ch==']'){
                if(stk.size()==0) return false;
            else if(ch==')' && stk.top()=='(') stk.pop();   //these conditions are inside elseif....
             else if(ch=='}' && stk.top()=='{') stk.pop();
              else if(ch==']' && stk.top()=='[') stk.pop();
              else return false;
            }
           
        }
        return stk.size()==0;
    }
    
string isBalanced(string s) {
    bool res=justBalanced(s);
    if(res==true) return "YES";
    else return "NO"; 
}

//driver function as in hackerrank.

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}
