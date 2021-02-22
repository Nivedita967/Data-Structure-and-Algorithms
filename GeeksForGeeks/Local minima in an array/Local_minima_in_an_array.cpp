#include <stdio.h> 
  
// function to returns index of a local minima using binary search
int localMin(int a[], int low, int high,int n) 
{ 
    // Finding index of middle element 
    int mid = low + (high - low)/2;  
  
    // Comparing middle element with its neighbours 
    if ((mid == 0 || a[mid-1] > a[mid]) && (mid == n-1 || a[mid+1] > a[mid])) 
      {  
          //returning middle element 
           return mid; 
      }

    else if (mid > 0 && a[mid-1] < a[mid]) 
     {   
         //recursively calling the function for local minima
          return localMin(a, low, (mid -1), n);
    }
  
    //recursive calling of function for local minima 
    return localMin(a, (mid + 1), high, n); 
    
} 
