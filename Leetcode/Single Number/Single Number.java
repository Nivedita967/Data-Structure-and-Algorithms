// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
class Solution {
    public int singleNumber(int[] nums) {
    //using HashMap

        // Initializing a hashmap
        HashMap<Integer,Integer> hm =  new HashMap<Integer,Integer>();
        // Creating a hashmap for given array
        for(int i : nums){
            if(hm.containsKey(i)){
                hm.put(i,hm.get(i) + 1);
            }
            else{
                hm.put(i,1);
            }
        }
        for(int i : nums){
            // if elements occurs only once then return that element
            if(hm.get(i) == 1){
                return i;
            }
        }
        return 0;
    }
}