import java.util.*;

public class Solution{
    public static void main(String[] args){
        //for taking input
        Scanner scn= new Scanner(System.in);
        int n= scn.nextInt();
        int k= scn.nextInt();

        //dynamic programming array of size k x n
        long[][] dp= new long[k+1][n+1];
        
        for(int i=1; i<=k; i++){
            for(int j=1; j<=n; j++){

                //when only 1 group 
                if(i==1){
                    dp[i][j]=1;
                }

                //when number of groups equals number of students
                else if(i==j){
                    dp[i][j]=1;
                }

                //if number of studnets is less than number of groups
                else if(j<i){
                    dp[i][j]=0;
                }

                // all other intermediate cells
                else{
                    dp[i][j] = dp[i-1][j-1] + (dp[i][j-1] * (i));
                }
            }
        }
    
        //printing stored output at last cell
        System.out.println(dp[k][n]);
    }
}
