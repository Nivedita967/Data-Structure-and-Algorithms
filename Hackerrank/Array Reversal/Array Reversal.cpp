#include <bits/stdc++.h>

using namespace std;

int main(){

   int n; //Size of array.
   cin>>n;
   int arr[n];
   for (int i=0;i<n;i++){
       cin>>arr[i]; //Take input for the array.
   }
   for (int low = 0, high = n - 1; low < high; low++, high--){
      swap(arr[low], arr[high]); //Swap the two elements.
   }
   //Printing the array.
   for (int i = 0; i < n; i++){
      cout << arr[i] << " ";
   }
   return 0;
}