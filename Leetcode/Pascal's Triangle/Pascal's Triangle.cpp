//Carefully observe that in each row 1 is at the leftmost and rightmost
//And every element is sum of upper 2 elements

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //Declaring ans of size of Nmber of Rows
        vector<vector<int>>ans(numRows);
        
        for(int i=0;i<numRows;i++)
        {
            //Give the size of ans(i) as i+1. Observe the figure in question.
            ans[i].resize(i+1);

            //1st and last element is 1
            ans[i][0]=ans[i][i]=1;
            
            // All other elements are sum of upper 2 elements. Again see the figure.
            for(int j=1;j<i;j++)
                ans[i][j]=ans[i-1][j-1]+ans[i-1][j];
        }
        
        return ans;
    }
};



// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]