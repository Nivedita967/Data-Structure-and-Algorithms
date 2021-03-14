class Solution {
    public int minHeightShelves(int[][] books, int shelf_width) {
        //dp array will contain the answer for each books
        int[] dp = new int[books.length + 1];
        //Base case
        dp[0] = 0;
        
        //Iterating through the books
        for (int i = 1; i <= books.length; ++i) {
            //Finding width and height
            int width = books[i-1][0];
            int height = books[i-1][1];
            //Assigning dp value to moving it to new shelf, i.e. adding height
            dp[i] = dp[i-1] + height;
            //Finding min value of dp where we can either move each book to new level or add the current book to new shelf
            for (int j = i - 1; j > 0 && width + books[j-1][0] <= shelf_width; --j) {
                height = Math.max(height, books[j-1][1]);
                width += books[j-1][0];
                dp[i] = Math.min(dp[i], dp[j-1] + height);
            }
        }
        //Returning required answer
        return dp[books.length];
    }
}
