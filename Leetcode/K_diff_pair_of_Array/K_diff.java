// Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.
// A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:
// 0 <= i, j < nums.length
// i != j
// |nums[i] - nums[j]| == k
// Notice that |val| denotes the absolute value of val.

package Leetcode.K_diff_pair_of_Array;
class K_diff {
    //Initialize the count
    int count = 0;
    public int findPairs(int[] nums, int k) {
       if(k < 0)
           return 0;
        if(k == 0){
            // Initialize a HashMap
            Map<Integer,Integer> hm = new HashMap<>();
            for(int x : nums)
                //Create a hashmap for the given array elements
                hm.put(x,hm.getOrDefault(x,0)+1);
            for(Map.Entry e : hm.entrySet()){
                // if the elements occur more than twice then increment the count
                if((int)e.getValue() >= 2)
                    count = count + 1;
            }
            
        }
        else{
            //Initialize an array list
             List<Integer> al = new ArrayList<>();
             // check list would store the traversed elements of the nums array
             List<Integer> check = new ArrayList<>();

             // Add all the elements of nums to list al
            for(int x : nums)
            {al.add(x);}
            // Traverse through each element of nums
        for(int x : nums)
        {
            // if check does not contain x that means elements x has not been traversed yet. so process with the loop
            if(!check.contains(x)){
                // if al would contain x+k that means there would be a number in al that would give the required differnce k
                if(al.contains(x+k))
                    count++;
                // Since x has been traversed so add it check array
                check.add(x);
            }
        }
       
        }
         return count;
    }
}