//TODO: A program to find difference of primary and secondary diagonals of a given square matrix

#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * We have to Complete the 'diagonalDifference' function below.
 * Rest of the code will be provided by Hackerrank itself
 */

int diagonalDifference(vector<vector<int>> arr, int n) {
    long psum=0,ssum=0;
    for (int i = 0; i < n; i++)                                //TODO: Updating/Calculation of sum of primary and secondary diagonal
    {
        psum += arr[i][i];
        ssum += arr[i][n-i-1];
    }
    long sum = psum-ssum;                                      //TODO: Calculating difference
    if(sum<0)
    {
        sum *=-1;
    }
    return sum;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<vector<int>> arr(n);

    for (int i = 0; i < n; i++) {
        arr[i].resize(n);

        string arr_row_temp_temp;
        getline(cin, arr_row_temp_temp);

        vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

        for (int j = 0; j < n; j++) {
            int arr_row_item = stoi(arr_row_temp[j]);

            arr[i][j] = arr_row_item;
        }
    }

    int result = diagonalDifference(arr,n);

    fout << result << "\n";                              //TODO: Printing result

    fout.close();

    return 0;
}

string ltrim(const string &str) {                        //TODO: Trimming the string to get elements of the matrix
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {                      //TODO: Trimming the string to get elements of the matrix
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {              //TODO: Trimming the string to get elements of the matrix
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
