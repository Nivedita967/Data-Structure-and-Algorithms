// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.
// Example 1:
// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]

// Example 2:
// Input: nums = [1], k = 1
// Output: [1]


class Solution {
    public int[] topKFrequent(int[] nums, int k) {
        // Invalid k
        if (k < 0 || k > nums.length) {
            return null;
        }
        
        // initialization
        Map<Integer, Integer> mapOfNumberAndCounter = new HashMap<Integer, Integer>();
        int [] resultArr = new int [k];
        
        // 1. create number and its' frequency map 
        for (int i = 0; i < nums.length; i++) {
            // If the map does not contains key then put the key & put 1 in its value since it is occuring for the first time
            if (!mapOfNumberAndCounter.containsKey(nums[i])) {
                mapOfNumberAndCounter.put(nums[i], 1);
            } else {
                // If the key already exists then increment its value by 1
                mapOfNumberAndCounter.put(nums[i], mapOfNumberAndCounter.get(nums[i]) + 1);
            }
        }
        
        for (int i = 0; i < k; i++) {
            // the old maxValue needs to be clean after each map's for-each 
            int maxValue = Integer.MIN_VALUE;
            
            for (Map.Entry<Integer, Integer> entry : mapOfNumberAndCounter.entrySet()) {
                if (maxValue < entry.getValue()) {
                    maxValue = entry.getValue();
                    resultArr[i] = entry.getKey();
                }
            }
            
            // when the map's for-each end every single time, remove the current element
            // so, the next loop will not have the previous maxValue
            mapOfNumberAndCounter.remove(resultArr[i]);
        }
        
        return resultArr;
    }
    }