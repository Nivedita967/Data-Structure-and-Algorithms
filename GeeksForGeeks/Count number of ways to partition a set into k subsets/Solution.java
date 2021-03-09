import java.util.*;

public class Solution{
    public static void main(String[] args){
        Scanner scn= new Scanner(System.in);
        int n= scn.nextInt();
        int k= scn.nextInt();
        long[][] dp= new long[k+1][n+1];
        
        for(int i=1; i<=k; i++){
            for(int j=1; j<=n; j++){
                if(i==1){
                    dp[i][j]=1;
                }
                else if(i==j){
                    dp[i][j]=1;
                }
                else if(j<i){
                    dp[i][j]=0;
                }
                else{
                    dp[i][j] = dp[i-1][j-1] + (dp[i][j-1] * (i));
                }
            }
        }
    
        System.out.println(dp[k][n]);
    }
}
