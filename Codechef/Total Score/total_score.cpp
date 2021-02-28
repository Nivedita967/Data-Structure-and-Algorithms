/* TODO : To print total score of each participant obtained in a contest with K problems and N participants 
We can store the problem scores in an array, and for each participant, consider all problems one by one.
If at position ii, 1 appears, participant has solved this problem, hence the score of that problem is added to participant score.
Therefore, we treat each participant individually */


#include <bits/stdc++./h>
using namespace std;
int main()
{
    int t;
    cin>>t;
	  while(t--)
	  {
	    int n,k;
	    cin>>n>>k;
	    long long int a[k];
	    int i,j;
	    string str[n];
	    
	    for(i=0;i<k;i++)
	    {
	        cin>>a[i];
	    }
	    for(i=0;i<n;i++)
	    {
	        cin>>str[i];                                  // getting binary string for each participant 
	        long long int total=0;
	        for(j=0;j<k;j++)
	        {
	            if(str[i][j]=='1')                        // if element of string is 1, we add to total 
	            total+=a[j];
	        }
	        cout<<total<<"\n";                            // print total for each participant 
	      }
      }
	  return 0;
}
