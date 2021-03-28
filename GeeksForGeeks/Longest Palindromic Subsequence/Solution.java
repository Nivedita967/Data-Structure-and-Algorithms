import java.util.*;

public class Solution{
    public static void main(String[] args){
        Scanner scn = new Scanner(System.in);
        String s1 = scn.nextLine();
        // using the gap method we calculate longest pallindromic subsequence
        int[][] dp = new int[s1.length()][s1.length()];
        int n = s1.length();
        for(int gap=0; gap<n; gap++){
            for(int i=0, j=gap; j<n; i++, j++){

                //Case 1 : when gap =0
                if(i==j){
                    dp[i][j]=1;
                }
                //case 2 : when two extreme points are similar characters
                else if(s1.charAt(i)== s1.charAt(j)){
                    dp[i][j] = dp[i+1][j-1] + 2;
                }
                //case 3 : when two extreme points are distinct characters
                else{
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }

        //return the answer stored at first row last column
        System.out.println(dp[0][s1.length()-1]);
        scn.close();
    }
}