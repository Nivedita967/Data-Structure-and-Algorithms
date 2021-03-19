class Solution {
    public int longestDecomposition(String text) {
        int ans = 0;
        //Finding the length of given string
        int n = text.length();
        //Initialising two empty strings
        String s = "", t = "";
        //Looping through characters
        for (int i = 0; i < n; ++i) {
            //Adding characters from beginning and end to both strings respectively
            s = s + text.charAt(i);
            t = text.charAt(n - i - 1) + t;
            //If strings are equal, increasing count and procceding again with empty strings
            if (s.equals(t)) {
                ++ans;
                s = "";
                t = "";
            }
        }
        //Returning ans
        return ans;
    }
}
