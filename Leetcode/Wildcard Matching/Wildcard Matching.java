public boolean isMatch(String s, String p) {
    // replace multiple * with single *
    char[] sArray = s.toCharArray(), pArray = p.toCharArray();
    int writeIndex = 0;
    boolean isFirst = true;
    for(int i=0; i<pArray.length; i++) {
        if(pArray[i] == '*') {
            if(isFirst) {
                pArray[writeIndex++] = pArray[i];
                isFirst = false;
            }
        } else {
            pArray[writeIndex++] = pArray[i];
            isFirst = true;
        }
    }
    
    // initiate dp array
    int m = sArray.length, n = writeIndex;
    boolean[][] dp = new boolean[m+1][n+1];
    
    // s and p are all empty, they match
    dp[0][0] = true;
    
    // s is empty and p is *, they match
    if(n > 0 && pArray[0] == '*') dp[0][1] = true;
    
    for(int i=1; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            // add j>0 to make first column false, because pattern is empty but text is not
            if(j > 0 && (sArray[i-1] == pArray[j-1] || pArray[j-1] == '?')) {
                dp[i][j] = dp[i-1][j-1];
            } else if(j > 0 && pArray[j-1] == '*') {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            } else {
                dp[i][j] = false;
            }
        }
    }
    return dp[m][n];
}