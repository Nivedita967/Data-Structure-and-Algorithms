#include <bits/stdc++.h>

using namespace std;

//function prototypes
string ltrim(const string &);
string rtrim(const string &);

// definition of dayOfProgrammer function below.
string dayOfProgrammer(int year) {

  if(year==1918)
    {
        return "26.09.1918";
    }
    else if((year<1918 && year%4==0) ||(year>1918  &&(year%4==0 && year%100 !=0 || year%400==0))) 
    {
        return "12.09." + to_string(year);
    }
    else
    {
        return "13.09." + to_string(year);
    }

}

//main function
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string year_temp;
    getline(cin, year_temp);

    int year = stoi(ltrim(rtrim(year_temp)));

    string result = dayOfProgrammer(year);

    fout << result << "\n";

    fout.close();

    return 0;
}

//function definition of ltrim
string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

//function definition of rtrim
string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
