#include<bits/stdc++.h>
using namespace std;

int main(){
    int ar[10][10],maxSum = -36985247; //array declaration 
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++)cin >> ar[i][j];  // 6*6 iiteration of rows and columns
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            if(j+2 < 6 && i+2 < 6 ){
                int sum = ar[i][j] + ar[i][j+1] + ar[i][j+2] + ar[i+1][j+1] + ar[i+2][j] + ar[i+2][j+1] + ar[i+2][j+2]; //add all the value to the solution 
                if(sum > maxSum)maxSum = sum;// checks the maximum sum
            }
        }
    }
    cout << maxSum << endl;
    return 0;
}