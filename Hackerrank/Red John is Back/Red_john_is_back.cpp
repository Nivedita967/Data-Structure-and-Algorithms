#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#include<algorithm>
#include<string>
#include<utility>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7
#define sieve_limit 10e6
#define mod 1000000007

typedef pair<int, int> pi;
typedef long long ll;
typedef long long int lli;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<long> vl;
typedef vector<long long> vll;
typedef vector<long long int> vlli;
typedef vector<vector<int> > vvi;
typedef vector<vector<bool> > vvb;
typedef vector<vector<long> > vvl;
typedef vector<vector<long long> > vvll;
typedef vector<vector<long long int> > vvlli;
 
// * ALGORITHM ==> 
// * This question is a mix of dynamic programming and number theory. Basically it tests out the knowledge of basic dynamic programming and sieve of eratosthenes which lies under the topic of number theory which deals with the easy calculation of prime numbers.
// * First we need to calculate the number of combination in which a given a wall can be covered with 2 types of bricks and then we need to calculate the count of prime numbers in the inclusive range of [0 - combination count]
// * For the calculation of tiles what we do is, we calculate the number of ways in which we can lay one brick vertically at the start and then calculate the ways to lay the same brick horizontally. And then we simply add the numbers to get the total sum.
// * When we lay the brick vertically in {4 * N} wall, the overall problem reduces to the same problem with {4 * (N - 1)} dimension, which makes the nth size problem dependent on the (n - 1)th size problem.
// * When we lay the brick horizontally in {4 * N} wall, the overall problem reduces to the same problem with {4 * (N - 4)} dimension, which make the nth size problem dependent on the (n - 4)th size problem.
// * And for the values of n < 4, there is simply one way, that is to put all the bricks vertically to cover the wall.
// * And for the value of n = 4, there are two ways, one is to put all the bricks vertically, and one is to put all the bricks horizontally.
// * And for n > 4, let value at every length be 'x', so the total combinations which can be formed  ==>  C(x) = ∑(C(x - 1), C(x - 4)), where C stands for combinations of covering the wall at that particular length.
// * Then we just run a loop, and count the number of prime numbers in the inclusive range of [0 - C(x)] 



// * Globally declared sieve so that it is accessible everywhere in the code
vb *v_sieve = new vb(sieve_limit + 1, 0);


// * Function 'sieve' to generate the sieve
void sieve(){
    for(int i = 3; i <= sieve_limit; i += 2){
        v_sieve-> at(i) = true;
    }

    v_sieve-> at(2) = true;

    for(int i = 3; i*i <= sieve_limit; i++){
        if(v_sieve-> at(i)){
            for(int j = i*i; j <= sieve_limit; j += i){
                v_sieve-> at(j) = false;
            }
        }
    }
}

// * Function 'wall_solver' to calculate and return the number of combinations for any given length 'n'
ll wall_solver(int n){
   vll dp(n + 1, 0);
   for(int i = 1; i <= n; i++){
      if(i < 4){
          dp[i] = 1;
      }
      else if(i == 4){
          dp[i] = 2;
      }
      else{
          dp[i] = dp[i - 1] + dp[i - 4];
      }
   }
   return dp[n];
}

// * Driver Code 
int main(){
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    sieve();

    int tc;
    cin >> tc;
    for(int i = 0; i < tc; i++){
        int n;
        cin >> n;
        ll brick_comb = wall_solver(n);
        int count = 0;
        for(int j = 0; j <= brick_comb; j++){
            if(v_sieve-> at(j)){
                count++;
            }
        }
        cout << count << '\n';
    }
}