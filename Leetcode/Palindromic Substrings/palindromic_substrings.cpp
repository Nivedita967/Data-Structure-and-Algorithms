// Scan through all lengths and check if it is  palindrome or not 
// And Increment the counter 
// For eg: Check for lenghts 0,1,2..N, and for each
// length check how many palindrome exists.

class Solution {
public:

    bool checkPalin(string str, int s , int e){
        while(s <= e){
            if(str[s++]!=str[e--]) return false;
        }
        return true;
    }
    int countSubstrings(string str) {
        if(str.length() == 0) return 0;
        
        int sum=0;
        for(int len = 0; len<str.length() ; ++len){
            for(int s=0 ; s<str.length()-len ;++s){
                // If palin for this specific start and
                // end point increment the count.
                if(checkPalin(str, s, s+len)) sum++;          
            }
        }
        return sum;
    }
};
