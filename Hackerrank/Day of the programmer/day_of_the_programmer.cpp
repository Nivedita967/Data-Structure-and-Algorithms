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

        //to_string is used to convert int into a string
    }

    else
    {
        return "13.09." + to_string(year);
    }

}

//main function
int main()
{
    //opening file
    ofstream fout(getenv("OUTPUT_PATH"));

    //declaration of string 
    string year_temp;

    //taking input  of the year in string data type 
    getline(cin, year_temp);

    // stoi: converting input string into integer
    // rtrim and ltrim : for removing whitespaces from left and right of the string  
    int year = stoi(ltrim(rtrim(year_temp)));

    //passing it to dayofprogrammer function 
    string result = dayOfProgrammer(year);

    //printing result 
    fout << result << "\n";

    //closing file
    fout.close();

    return 0;
}

//function definition of ltrim
string ltrim(const string &str) {
    string s(str);

    //triming the 'year' string from start by using these inbuilt funtions
    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

//function definition of rtrim
string rtrim(const string &str) {
    string s(str);

    //triming the 'year' string from end by using these inbuilt funtions
    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
