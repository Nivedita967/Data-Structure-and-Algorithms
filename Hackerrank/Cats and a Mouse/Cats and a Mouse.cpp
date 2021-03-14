// A program to find who will win the race , cat a , cat b or the mouse


#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

// we have to complete the catAndMouse function below only, rest of the code will be given by hackerrank itself  
string catAndMouse(int x, int y, int z) {
    int a = x - z;                           // Calculating length to be travelled by both the cats
    int b = y - z;
    if (a < 0) a *= -1;                      // Converting length to positive if it is negative
    if (b < 0) b *= -1;
    if (a == b) return "Mouse C";            // Printing result
    else if (a > b) return "Cat B";
    else return "Cat A";

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int q;
    cin >> q;                                                   // Getting user input
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string xyz_temp;
        getline(cin, xyz_temp);

        vector<string> xyz = split_string(xyz_temp);         

        int x = stoi(xyz[0]);                                  // Converting iput into integer

        int y = stoi(xyz[1]);

        int z = stoi(xyz[2]);

        string result = catAndMouse(x, y, z);

        fout << result << "\n";                               // Printing result
    }

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
