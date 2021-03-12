#include <bits/stdc++.h>
using namespace std;
 
 int main()
{
    //declaring variables
    int i, j, arr[3][3], tmp[3][3];

    //setting the matrix
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
           {
               arr[i][j] = 1;
           }
    }
    
    //taking input and computing output
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin>>tmp[i][j];
            
            //checking if light is on
            if (tmp[i][j] % 2 == 1)
            {

                if (arr[i][j]){ arr[i][j] = 0;}
                else {arr[i][j] = 1;}
                //checking on rows
                if (i != 0)
                    {
                        if (arr[i-1][j]) {arr[i-1][j] = 0; }
                        else {arr[i-1][j] = 1;}
                    }
                if (i != 2)
                   { 
                       if (arr[i+1][j]) {arr[i+1][j] = 0;}
                       else {arr[i+1][j] = 1;}
                   }
                   
                //checking on columns   
                if (j != 0)
                  {
                      if (arr[i][j-1]) {arr[i][j-1] = 0;}
                      else {arr[i][j-1] = 1;}
                  }    
                if (j != 2)
                  {
                      if (arr[i][j+1]) {arr[i][j+1] = 0; }
                      else {arr[i][j+1] = 1;}
                  }      
            }
        }
    }

    //printing the output 
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}