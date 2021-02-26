/* print a pattern for given value of n.
Consider the whole pattern as a cartesian grid with 1 as the center. Now move alongside the X-Y axis to fill in the values;
The rows will start from n-1 and will range till -(n-1) 
The columns will start from -n+1 and will range till n-1*/
//Example for n = 2
/*  2       2      2 
  (-1,1)  (0,1)  (1,1)
  
    2       1      2
  (-1,0)  (0,0)  (1,0)
  
    2       2      2
  (-1,-1) (0,-1) (1,-1) */


#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=n-1;i>-n;i--){          //row
        for(int j=-n+1;j<n;j++){      //column
            printf("%d ",max(abs(i),abs(j))+1);   //the value to be printed will always be the distance of the value from center + 1 
        }
        printf("\n");
    }
}
