class Solution {
    public int minimumDistance(String word) {
        //dp array for each character
        int dp[] = new int[26]; 
        //Declaring ans and save variable which will contain the maximum distance that can be saved by using only one finger
        int ans = 0, save = 0;
        //Finding length of given word
        int n = word.length();
        //Looping through each character of given word
        for (int i = 0; i < n - 1; ++i) {
            //Finding b and c
            int b = word.charAt(i) - 'A';
            int c = word.charAt(i + 1) - 'A';
            //Looping through each character
            for (int a = 0; a < 26; ++a){
                //dp will be equal to maximum of current value and looped character and difference of the distance
                dp[b] = Math.max(dp[b], dp[a] + distance(b, c) - distance(a, c)); 
            }    
            //Updating save and ans
            save = Math.max(save, dp[b]);
            ans += distance(b, c);
        }
        return ans - save;

    }

    //Method to find distance
    private int distance(int x, int y) {
        return Math.abs(x / 6 - y / 6) + Math.abs(x % 6 - y % 6);
    }
}
