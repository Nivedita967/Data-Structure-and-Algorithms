/* TODO : Print pattern for a given number n
Consider the pattern as a cartesian grid with 1 as the center.Hence we can move along the X-Y axis 
Therefore, 
rows start from n-1 and range till -(n-1)
columns start from 1-n and range till (n-1)

Eg: for n=2

    2     2     2
 (-1,1) (0,1) (1,1)
 
    2      1     2 
  (-1,0) (0,0) (1,0)
  
    2      2     2 
 (-1,-1) (0,-1)(1,-1)
*/



#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    for(int i=n-1;i>-n;i--){          //row
        for(int j=-n+1;j<n;j++){      //column
            printf("%d ",max(abs(i),abs(j))+1);   // the number to be printed will always be the distance of the number from center +1 
        }
        printf("\n");
    }
}
