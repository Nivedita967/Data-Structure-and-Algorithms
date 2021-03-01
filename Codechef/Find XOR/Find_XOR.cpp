// Note: This is an interactive problem which means, the problem should be interacted with the grader at each step
// The cases returned by the grader at each step should also be handled properly
// In this question, it is like a trial and hit method, where you have to guess the correct input that you
// have to send it to grader so that the grader's output is helpful for you to solve this problem

#include <iostream>
#include <vector>
#define ll long long

using namespace std;

// To find the power of the 'base' raised to the exponent 'pow'
ll fpow(ll base , ll pow) {
    if(pow == 0)
        return 1;
    if(pow & 1)
        return base * fpow(base * base , (pow - 1) / 2);
    return fpow(base * base , pow / 2);
}

int main() {

    int t;
    cin >> t;

    while(t--) {

        ll n;
        cin >> n;

        // The first guess made to the grader
        ll ask = 1048576;

        vector <ll> setBit;
        setBit.push_back(0);
        cout << "1 " << ask << endl;

        // The first guess gives us the original sum of the array
        ll receive;
        ll originalSum = 0;
        cin >> receive;

        if(receive == -1)
            exit(0);
        else {
            originalSum = receive - n * ask;
        }

        // After first guess, this is the second guess made to the grader
        ask = 2;
        ll tempSet;
        for(int i = 0; i < 19; i++) {
            cout << "1 " << ask << endl;
            cin >> receive;

            // If an improper guess is made, grader returns -1, so that the program should be exited safely, else
            // abnormal results may occur
            if(receive == -1)
                exit(0);
            else {
                tempSet = (n - ((receive - originalSum) / ask)) / 2;
                setBit.push_back(tempSet);
            }

            // After second guess, the next remaining guesses are twice the previous guess
            ask = ask * 2;
        }

        ll result = 0;
        for(int i = 1; i < 20; i++) {
            if(setBit[i] & 1) {
                result = result + fpow(2 , i);
            }
        }

        if(originalSum & 1)
            result++;
        cout << "2 " << result << endl;
        
        int check;
        cin >> check;

        // If an improper guess is made, grader returns -1, so that the program should be exited safely, else
        // abnormal results may occur
        if(check == -1)
            exit(0);
    }
    return 0;
}