//Find the length of the longest valid parentheses substring of a given string

/*we start traversing the string from the left towards the right and for every ‘(’,
encountered, we increment the left counter and for every )’ encountered, we increment the right counter*/

/* maxans --> contains max length of string*/

class Solution {
public:
    int longestValidParentheses(string s) {
        int left=0 , right = 0 , maxans = 0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){                               
                left++;                                         //increment left counter
            }
            else{
                right++;                                        //increment right counter
            }
            if(left==right){
                maxans=max(maxans, 2*right);                    //update max counter if left and right counters are equal 
            }
            else if(right>left){                                //if right>left --> make both the counters 0 
                left=right=0;
            }
        }
      
   /* traverse from right to left with the same procedure*/
        
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
