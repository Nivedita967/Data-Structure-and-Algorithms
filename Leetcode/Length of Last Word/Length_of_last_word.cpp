// * ALGORITHM =>
// * As we have to find the length of last word, we can start at the end of the given string and traverse the string backwards till we encounter first space.
// * Although there are some edge cases which needs to be taken care of. Such as for "a" and " a" and "a ".
// * So will maintain a count variable initialised to '0' and only increment count variable on encountering a character which is not a space.
// * Also, we will only break out of the loop when either we reach the start of the string (i < 0) or we encounter a space and the count is not equal to 0, to handle the edge case of "a "


// * Driver code + lengthofLastWord function
class Solution{
public:
    int lengthOfLastWord(string s){
        int count = 0;
        for (int i = s.size() - 1; i >= 0; i--){
            if (s[i] == ' ' && count != 0){
                break;
            }
            if (s[i] != ' '){
                count++;
            }
        }
        return count;
    }
};