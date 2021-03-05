// * ALGORITHM ==>
// * Basically what we do is we check the current character and the previous character and try to break the string/substring in two ways.
// * There can be 4 cases depending on the value of current character and its previous character.
// * Assume the index of current character to be 'i', so index of previous character will be 'i - 1'
// * Cases are as follows -
// * char At 'i - 1' == '0' and char At 'i' == '0' ==> Here no encodings can be generated as both the characters are 0 and there are no encodings for '0'
// * char At 'i - 1' == '0' and char At 'i' != '0' ==> Here we can break the string as {0 - - - - + [i - 1]} + [i], and hence we look for the number of encodings up till 'i - 1' and add it to current value stored at dp[i]
// * char At 'i - 1' != '0' and char At 'i' == '0' ==> Here we can break the string as {0 - - - - + [i - 2]} + {[i - 1] + [i]} and on the values of 'i - 1' we decide the numbers of encoding.
// * char At 'i - 1' != '0' and char At 'i' != '0' ==> Here we can break the string in 2 ways {0 - - - - + [i - 2]} + {[i - 1] + [i]} and on the values of 'i - 1', we decide the numbers of encoding. And the other way is to break like,  {0 - - - - + [i - 1]} + [i], and then we just add the value stored at dp[i - 1] to the current value stored at dp[i].
// * IMPORTANT NOTE => 1) Edge case at index 0, on the basis of a '0' or '!0'(non - zero) character should be checked.
// *                => 2) Always use substr method of string to concatenate characters.   


// * Solution class 
class Solution{
public:
    int numDecodings(string s){
        vector<int> dp(s.size(), 0);
        if (s[0] == '0'){
            dp[0] = 0;
        }
        else{
            dp[0] = 1;
        }
        for (int i = 1; i < s.size(); i++){
            if (s[i - 1] == '0' && s[i] == '0'){
                dp[i] = 0;
            }
            else if (s[i - 1] == '0' && s[i] != '0'){
                dp[i] += dp[i - 1];
            }
            else if (s[i - 1] != '0' && s[i] == '0'){
                string str = "";
                str += s.substr(i - 1, 2);
                if (str <= "26"){
                    if (i == 1){
                        dp[i] += 1;
                    }
                    else{
                        dp[i] += dp[i - 2];
                    }
                }
                else{
                    dp[i] = 0;
                }
            }
            else if (s[i - 1] != '0' && s[i] != '0'){
                dp[i] += dp[i - 1];
                string str = "";
                str += s.substr(i - 1, 2);
                if (str <= "26"){
                    if (i == 1){
                        dp[i] += 1;
                    }
                    else{
                        dp[i] += dp[i - 2];
                    }
                }
            }
        }
        return dp[s.size() - 1];
    }
};