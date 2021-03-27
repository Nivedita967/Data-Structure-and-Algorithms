import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner scn = new Scanner(System.in);
		int tc = scn.nextInt();
		for(int t=0; t<tc; t++){
		    int n = scn.nextInt();
		    String s = scn.nextLine();
            boolean[][] dp= new boolean[s.length()][s.length()];
            for(int gap=0; gap<s.length(); gap++){
                for(int i=0, j=gap; j<s.length(); i++, j++){
                    
                    // Subcase 1: when gap is 1 
                    if(gap == 1 && (s.charAt(i))==s.charAt(j)){
                        dp[i][j] = true;
                    }
                    
                    // Subcase 1: when extreme character are same 
                    else if(s.charAt(i)==s.charAt(j)){
                        dp[i][j] = dp[i+1][j-1];
                    }

                    // Subcase 1: when extreme character are different
                    else{
                        dp[i][j] = false;
                    }
                }
            }

            // keeping a count of all the values that are true & palindromes;
            int count =0;
            for(int gap=0; gap<s.length(); gap++){
                for(int i=0, j=gap; j<s.length(); i++, j++){
                    if(dp[i][j] == true){
                        count++;
                    }
                }
            }

            //printing count
            System.out.println(count);
		}
	}
}