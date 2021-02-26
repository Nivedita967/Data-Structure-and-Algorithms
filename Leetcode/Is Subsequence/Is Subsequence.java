class Solution {
    public boolean isSubsequence(String s, String t) {
        //If s is a null string, it is always a subsequence
        if(s.length()==0){
            return true;
        }
        //This index will be used to iterate over s
        int firstIndex=0;
        //We will loop through string t and check if characters are equal
        for(int i=0;i<t.length();i++){
            //If they are equal, then we move firstIndex
            if(t.charAt(i)==s.charAt(firstIndex)){
                firstIndex++;
            }
            //If we have reached the end of s string, it is a subsequence
            if(firstIndex== s.length()){
            return true;
        }
        }
        //If true is not returned, it is not a subsequence
        return false;
    }
}
