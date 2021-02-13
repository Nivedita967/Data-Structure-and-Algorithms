class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        // We will first create a List that will store all the subsets
        List<List<Integer>> ans = new ArrayList();
        // We will use a recursive function to generate subarrays and store them in our answer list. The argument it takes are the current subset that we're getting, our answer, index and the nums array.
        allSubsets(new ArrayList<Integer>(), ans, 0, nums);

        // We will get all the subsets stored in ans and we will return it.
        return ans;
    }

    //This is our recursive function
    public void allSubsets(List<Integer> currSubset, List<List<Integer>> ans, int index, int[] nums){
        //First we will add a copy of current subset to our answer
        ans.add(new ArrayList<>(currSubset));
        // We will then use both possibilities of adding a number to subset and not adding the number to subset
        for(int i= index; i< nums.length;i++){
            //Adding the number to subset
            currSubset.add(nums[i]);
            // Proceeding further with the current subset
            allSubsets(currSubset, ans, i+1, nums);
            // Removing the number from subset
            currSubset.remove(currSubset.size() -1);
        }
    }
}
