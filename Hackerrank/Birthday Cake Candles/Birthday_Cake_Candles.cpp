#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<string>
#include<climits>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;


// * ALGORITHM

// * 1) Find out the maximum whilst travelling through the numbers and count the maximum if it occurs again during the course of travel.
// * 2) If at any point of time the maximum changes then, we can just reset the count to 1, and again follow the same procedure.

// * maximum - To store the current maximum
// * old_maximum - To store and compare the old maximum with the current maximum if the maximum changes at any point of time.

// * Driver code + main code
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, count = 0, maximum = INT_MIN, element, old_maximum = INT_MIN;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> element;
        maximum = max(element, maximum);
        if(old_maximum != maximum){     // * If the old maximum doesn't match with the current maximum, then it means that the maximum has been changed now. 
            count = 1;                 // * So we reset the count = 1
            old_maximum = maximum;    //  * And make the value of old maximum equal to the new maximum
        }
        else if(element == maximum){  // * Whilst traversing the array if we find the current maximum again we increment the count by 1
            count++;
        }
    }
    cout << count << '\n';      // * Printing the value of count 
}