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
#include<math.h>
using namespace std;

#define mp make_pair
#define INFI 10e8
#define INF 10e7

typedef pair<int, int> pi;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef long long ll;

// * ALGORITHM =>
// * So to solve this problem, I have maintaine two priority queue (PQ), one is a MAX PQ and the other is the MIN PQ.
// * To solve it further, there are some conditions which the solver needs to remember. The main motive is that, addition of elements do not disturb the older medians.
// * The conditions are mentioned as follows -

// * INSERTION OF NEW ELEMENTS =>
// * We generally add elements to the LEFT PQ, but if the incoming element is greater than the value stored at the top of the RIGHT PQ and the RIGHT PQ is not empty, then we add the incoming element to the RIGHT PQ.
// * After EVERY insertion, we need to check the difference in the size of the PQ's. If the difference is greater than one ( > 1), then we pop the top element of the PQ with larger size, and shift it to other PQ.

// * TO FIND THE MEDIAN =>
// * If the size of the PQ are different, then the value at the top of PQ with larger size is the median.
// * If the size of the PQ is same, then the value at the top of LEFT PQ is the median. (But in this question, if size of both the PQ is same, then we have to return the mean of the top value of both the PQ)


// * Median PQ class -
class median_pq{
    priority_queue<float> lpq;      // * MAX PQ 
    priority_queue<float, vector<float>, greater<float> > rpq;  // * MIN PQ


// * Median function that returns the current median
    float median(){
        if(lpq.size() != rpq.size()){
            if(lpq.size() > rpq.size()){
                return lpq.top();
            }
            else{
                return rpq.top();
            }
        }
        else{
            return (lpq.top() + rpq.top())/2;
        }
    }


// * add function that adds the new element to Median PQ and calls the median function at the end.
public:
    float add(float element){           // * Addition of new element
        if(!rpq.empty() && rpq.top() < element){
            rpq.push(element);
        }
        else{
            lpq.push(element);
        }

        int diff = lpq.size() - rpq.size();
        diff = abs(diff);
        if(diff > 1){                       // * To balance the size of both the PQ's 
            if(lpq.size() > rpq.size()){
                float top = lpq.top();
                lpq.pop();
                rpq.push(top);
            }
            else{
                float top = rpq.top();
                rpq.pop();
                lpq.push(top);
            }
        }
       return median();
    }

};


// * Driver code
int main(){
    median_pq pq;
    int n;
    float element;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> element;
        float median = pq.add(element);
        printf("%0.1f \n", median);         //* printf used to print the value upto '1' decimal place. 
    }

}