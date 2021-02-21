class Solution {
 public:
  int countVowelStrings(int n)
  {
    // dp[0] := # of lexicographically sorted strings ends with 'a'
    // dp[1] := # of lexicographically sorted strings ends with 'e'
    // dp[2] := # of lexicographically sorted strings ends with 'i'
    // dp[3] := # of lexicographically sorted strings ends with 'o'
    // dp[4] := # of lexicographically sorted strings ends with 'u'
      
    vector<int> dp(5, 1);
    
     // loop for counting sorted vowel strings 
    for (int i = 2; i <= n; ++i) 
    {
      //declaring a vector for every position of dp vector  
      vector<int> newDp(5);
      
      //loop for making vowel strings   
      for (int j = 0; j < 5; ++j)
      { 
          for (int k = 0; k <= j; ++k)
          {
              newDp[j] += dp[k];
          }
      }
      dp = move(newDp);
    }

    // returning no of sorted vowel strings 
    return accumulate(begin(dp), end(dp), 0);
  }
};