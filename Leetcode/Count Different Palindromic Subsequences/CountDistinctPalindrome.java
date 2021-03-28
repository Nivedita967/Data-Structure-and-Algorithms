class Solution {
    public int countPalindromicSubsequences(String S) {
        int len = S.length();

        // Storing the next and previous occurence of every character 
        int[] next= new int[len];
        int[] prev= new int[len];
        Arrays.fill(next, -1);
        Arrays.fill(prev, -1);
        HashMap<Character, Integer> mymap1=new HashMap<>();

        // For next occurence
        for(int i=0; i<len; i++){
            if(mymap1.containsKey(S.charAt(i))==true){
                prev[i]= mymap1.get(S.charAt(i));
            }
            mymap1.put(S.charAt(i), i);
        }

        // For previous occurence
        HashMap<Character, Integer> mymap2=new HashMap<>();
        for(int i=len-1; i>=0; i--){
            if(mymap2.containsKey(S.charAt(i))==true){
                next[i]= mymap2.get(S.charAt(i));
            }
            mymap2.put(S.charAt(i), i);
        }

        // For modulo
        int N = 1_000_000_007;
        int[][] dp = new int[len][len];

        // using gap method
        for(int gap=0; gap<len; gap++){
            for(int i=0, j=gap; j< len; i++, j++){

                // Subcase 1: When gap = 0
                if(gap == 0){
                    dp[i][j]= 1;
                }

                // Subcase 2: When gap = 1
                else if(gap == 1){
                     dp[i][j]= 2;
                }
                
                else{
                    // Subcase 3: When two extreme characters are same
                    if(S.charAt(i) == S.charAt(j)){
                        int n = next[i];
                        int p = prev[j];

                        // Subcase 3.1 : when next exceeds previous 
                        if(n > p){
                            dp[i][j] = ((2*dp[i+1][j-1]) %N + 2) %N;
                        }

                        // Subcase 3.2 : when next equals previous 
                        else if(n == p){
                            dp[i][j] =((2*dp[i+1][j-1]) %N + 1) %N;
                        }

                        // Subcase 3.3 : when previous exceeds next
                        else{
                            dp[i][j] = ((2*dp[i+1][j-1]) % N - dp[n+1][p-1] + N) % N;
                        }
                    }

                    // Subcase 4: When two extreme characters are different
                    else{
                        dp[i][j] = ((dp[i+1][j] + dp[i][j-1]) %N - dp[i+1][j-1] + N) %N;
                    }
                }
            }
        }

        // returning final answer 
        return dp[0][len-1];
    }
}