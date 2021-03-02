
#include <bits/stdc++.h>
using namespace std;

//Function to find the leaders in the array.
vector<int> leaders(int a[], int n)
{
    //declaration of vector for storing leaders
    vector<int> v;

    //variable to store leader and then pushing it to vector
   int max_from_right =  a[n-1]; 
  
    //Rightmost element is always leader 
    v.push_back(max_from_right);
      
    //loop for finding and pushing leaders into vector
    for (int i = n-2; i >= 0; i--) 
    { 
        if (max_from_right <= a[i])  
        {            
            max_from_right = a[i]; 
            v.push_back(max_from_right); 
        } 
    }     
    //reversing the vector 
    reverse(v.begin(), v.end()); 
    
    //returning vector
    return v;
}


// { Driver Code Starts.

int main()
{
    //declaration of varible for testcases
   long long t;
   //inputting testcases
   cin >> t;

   //loop for running test cases
   while (t--)
   {
       //total size of array
       long long n;
       cin >> n;
        
        //declaration of array
        int a[n];
        
        //inserting elements in the array
        for(long long i =0;i<n;i++)
        {
            cin >> a[i];
        }
        
        //calling leaders() function
        vector<int> v = leaders(a, n);
        
        //printing elements of the vector
        for(auto it = v.begin();it!=v.end();it++){
            cout << *it << " ";
        }
        
        cout << endl;

   }
}
  // } Driver Code Ends