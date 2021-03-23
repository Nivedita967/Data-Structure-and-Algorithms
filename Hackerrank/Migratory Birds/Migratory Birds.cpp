// A program to find out what type of birds are migrated


#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

// we have only to complete the migratoryBirds function below, rest of the code will be given by hackerrank itself
int migratoryBirds(vector<int> arr) {
    vector<int> a(5,0);                          // Creating a vector to find number of migrations
    int siz = arr.size();
    for (int i = 0; i < siz; i++)
    {
        a[arr[i]-1]++;                          // Updating the array
    }
    
    int res = 1;
    int max = 0;
    for (int i = 0; i < 5; i++)                // Finding maximum migrated birds
    {
        if (a[i]>max)
        {
            max = a[i];
            res = i+1;
        }
    }
    return res;                               // Returning the result

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string arr_count_temp;
    getline(cin, arr_count_temp);                         // Taking input

    int arr_count = stoi(ltrim(rtrim(arr_count_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));       // Keeping input inside a vector

    vector<int> arr(arr_count);

    for (int i = 0; i < arr_count; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    int result = migratoryBirds(arr);

    fout << result << "\n";                               // Printing result

    fout.close();

    return 0;
}

string ltrim(const string &str) {                                  // Trimming the input provided to make it integer
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

vector<string> split(const string &str) {
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
