
//C++ program for pllindrome partitioning
class Solution {
public:
    int palindromePartition(string s, int k) {
        //Finding length of the string
        int len = s.size();
        vector<vector<int>> palindrome (len, vector <int> (len, 0));
        for (int i=0;i<len;i++)
        {
            for (auto d: {0,1})
            {
                int c = 0;
                int j=i-1,k=i+d;
                while(j>=0&&k<len)
                    palindrome[j--][k++] = s[j]!=s[k]?++c:c;
            }
        }
        vector<int> dp(len,0);
        for (int i=0; i<len; i++)
        //Using helper function for k=0
            dp[i] = palindrome[i][len-1];
        int nk = 1;
        while(nk < k)
        {
            for (int i=0; i<len; i++)
            {
                dp[i] = len;
                for (int j=i;j<len-nk;j++)
                //For each length greater than current value of k, ans will be minimum value
                // found between current value and partition at length-1 plus helper for the substring 
                // between length-1 and current value of length
                    dp[i] = min(dp[i],palindrome[i][j] + dp[j+1]);
            }
            nk++;
        }      
        // returning answer
        return dp[0]; 
    }
};