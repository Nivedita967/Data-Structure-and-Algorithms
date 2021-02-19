class Solution {
public:
    
    //s-> string to be find
    //t-> input string
    bool isSubsequence(string s, string t) {
       
        //we'll basically compare all the alphabets of s and t in order in linear time complexity of O(n)
        int j=0;
        bool res =true;
        for(int i=0;i<t.length();i++){

            //if the characters match then only we'll increment j index.
            if(t[i]==s[j]){
                j++;
            }
        }

        //if j is not reached til the end of string s that would mean, all characters of s are not present in t in order. 
        //Thus there is no subsequence of t equal to s.
        if(j!=s.length()){
            res=false;
        }

        //return the bool value 
        return res;
    }
};