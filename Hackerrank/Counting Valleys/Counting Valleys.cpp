#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

// We have to complete the following function only, rest of the code will be given by hackerrank itself
int countingValleys(int steps, string path) {
    int curlev = 0,ind = 0,count = 0;
    for (int i = 0; path[i]!='\0';i++)                       // Iterating through every element of the string
    {
        if (path[i]=='U')                                    // Increasing sea level if there is a U in string else decreasing it
        {
            curlev++;
        }
        else {
            curlev--;
        }
        if (curlev == -1)
        {
            ind = -1;
        }
        if (curlev == 0 && ind == -1)                       // If the sea level was -1 and now is going to be zero, count one valley
        {
            count++;
            ind++;
        }
    }
    return count;                                           // Returning counted valleys
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
