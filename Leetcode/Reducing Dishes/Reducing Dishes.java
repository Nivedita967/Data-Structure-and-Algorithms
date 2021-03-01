class Solution {
    public int maxSatisfaction(int[] satisfaction) {
        //We need to cook dishes with high satisfaction in the end
        Arrays.sort(satisfaction);
        //Finding the size of given array
        int size = satisfaction.length;
        //Declaring the ans
        //Declaring total satisfaction till now
        int ans = 0;
        int total = 0;
        //Traversing from the end, each dish will be cooked one unit later
        //We traverse till current satisfaction+ total satisfaction >0
        for (int i = size - 1; i >= 0 && satisfaction[i] + total > 0; --i) {
            total += satisfaction[i];
            ans += total;
        }
        return ans;
    }
}
