
#include <bits/stdc++.h> 
using namespace std; 
  
// Function to find element occurring odd number of times 
int OddOccurrence(int ar[], int ar_size) 
{ 
    //declaration of required variable
    int res = 0;  

    //loop for finding number occuring odd number of times
    for (int i = 0; i < ar_size; i++)      
    { 
        //perfroming XOR operation on elements
        res = res ^ ar[i]; 
    }  

    //returning result
    return res; 
} 
int main() 
{ 
    //declaration and input of size no of elemets in an array
    int size;
    cin>>size;

    //declarationa of required array
    int ar[size];

    //loop for inputting elements in array
    for(int i=0; i<size; i++)
    {
        cin>>ar[i];
    }

    // Function calling and printing output
    cout << OddOccurrence(ar, size); 
      
    return 0; 
} 