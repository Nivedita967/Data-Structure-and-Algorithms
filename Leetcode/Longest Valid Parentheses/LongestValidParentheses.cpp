//Find the length of the longest valid parentheses substring of a given string

class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0 , right = 0 , maxans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                maxans=max(maxans, 2*right);
            }
            else if(right>left){
                left=right=0;
            }
        }
        
        left=right=0;
        for(int i=s.size()-1 ; i>=0;i--){
            if(s[i]=='('){
                left++;
            }
            else{
                right++;
            }
            if(left==right){
                maxans=max(maxans, 2*left);
            }
            else if(left>right){
                left=right=0;
            }
        }
        return maxans;
    }
};
