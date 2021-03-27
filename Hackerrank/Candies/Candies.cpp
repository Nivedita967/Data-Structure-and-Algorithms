#include <bits/stdc++.h>

using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> a) {
    long int left[n],right[n];
    left[0]=1; // iterate from left
    right[n-1]=1; //iterate from right
    long sum=0;

    //iterate from left
    for (int i=1;i<n;i++){
        if (a[i]<=a[i-1]){
            left[i]=1;
        }
        else left[i]=left[i-1]+1;
    }

    //iterate from right
    for (int i=n-2;i>=0;i--){
        if (a[i]<=a[i+1]){
            right[i]=1;
        }
        else right[i]=right[i+1]+1;
    }

    //calculate the sum
    for (int i=0;i<n;i++){
        sum+=max(left[i],right[i]);
    }
    return sum;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item;
        cin >> arr_item;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}
