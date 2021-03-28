#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'stockmax' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts INTEGER_ARRAY prices as parameter.
 */

// * ALGORITHM ==>
// * In this we travel prices array in reverse order and consider all possible profits we can earn.
// * In stacks, we maintain the current highest price for sale.
// * Keep on updating the max with the currprofit.
// * This is an indirect application of Next Greater element on the Left

long stockmax(vector<int> prices)
{
    long max_ = 0;
    stack<long> stk;

    // * maintaining last maximum that occurred
    int lastmax = prices[prices.size() - 1];
    stk.push(prices[prices.size() - 1]);
    for (int i = prices.size() - 2; i >= 0; i--)
    {

        // * Base case
        if (stk.size() == 0 || stk.top() >= prices[i] || prices[i] <= lastmax)
        {
            stk.push(prices[i]);
        }

        // * Subcase: when we can get a profit greater than maxprofit
        else
        {
            while (stk.size() != 0)
            {
                max_ += (lastmax - stk.top());
                stk.pop();
            }
            lastmax = prices[i];
            stk.push(prices[i]);
        }
    }

    // * emptying the stack at last in order to consider all maximum
    while (stk.size() != 0)
    {
        max_ += (lastmax - stk.top());
        stk.pop();
    }
    return max_;
}

// * driver code
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++)
    {
        string n_temp;
        getline(cin, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        string prices_temp_temp;
        getline(cin, prices_temp_temp);

        vector<string> prices_temp = split(rtrim(prices_temp_temp));

        vector<int> prices(n);

        for (int i = 0; i < n; i++)
        {
            int prices_item = stoi(prices_temp[i]);

            prices[i] = prices_item;
        }

        long result = stockmax(prices);

        fout << result << "\n";
    }

    fout.close();

    return 0;
}

string ltrim(const string &str)
{
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace))));

    return s;
}

string rtrim(const string &str)
{
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end());

    return s;
}

vector<string> split(const string &str)
{
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos)
    {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
